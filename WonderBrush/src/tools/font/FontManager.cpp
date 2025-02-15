// FontManager.cpp

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include <ft2build.h>
#include FT_SFNT_NAMES_H
#include <freetype/ttnameid.h>

#include <FindDirectory.h>
#include <Directory.h>
#include <Menu.h>
#include <MenuItem.h>
#include <Path.h>
#include <String.h>
#include <UTF8.h>

#include "FontPopup.h"

#include "FontManager.h"

// static default instance
FontManager*
FontManager::fDefaultManager = NULL;

static const char* threadName = "font scanner";

// constructor
FontManager::FontManager()
	: BLooper(threadName, B_LOW_PRIORITY),
	  fLibrary(NULL),
	  fFontFiles(1024)
{
	// initialize engine
	FT_Error error = FT_Init_FreeType(&fLibrary);
	if (error)
		fprintf(stderr, "Could not initialise FreeType library\n");

	// start thread to read keyfile
	thread_id fontScanner = spawn_thread(_update, threadName,
										 B_LOW_PRIORITY, this);
	if (fontScanner >= B_OK)
		resume_thread(fontScanner);

	Run();
}

// destructor
FontManager::~FontManager()
{
	_MakeEmpty();
}

// MessageReceived
void
FontManager::MessageReceived(BMessage* message)
{
	switch (message->what) {
		case MSG_UPDATE: {
			// notify potential observes
			BMessage message(MSG_FONTS_CHANGED);
			SendNotices(FONTS_CHANGED, &message);
			break;
		}
		default:
			break;
	}
}

// CreateDefault
void
FontManager::CreateDefault()
{
	if (!fDefaultManager)
		fDefaultManager = new FontManager();
}

// DeleteDefault
void
FontManager::DeleteDefault()
{
	fDefaultManager->Lock();
	fDefaultManager->Quit();
}

// Default
FontManager*
FontManager::Default()
{
	if (!fDefaultManager)
		CreateDefault();
	return fDefaultManager;
}

// FontFileAt
const entry_ref*
FontManager::FontFileAt(int32 index) const
{
	if (font_file* ff = (font_file*)fFontFiles.ItemAt(index)) {
		return &ff->ref;
	}
	return NULL;
}

// FontFileFor
const entry_ref*
FontManager::FontFileFor(const char* family, const char* style) const
{
	if (family && style) {
		for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {
			if (ff->family_name && strcmp(ff->family_name, family) == 0
				&& ff->style_name && strcmp(ff->style_name, style) == 0)
				return &ff->ref;
		}
	}
	return NULL;
}

// IndexFor
int32
FontManager::IndexFor(const char* family, const char* style) const
{
	if (family && style) {
		for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {
			if (ff->family_name && strcmp(ff->family_name, family) == 0
				&& ff->style_name && strcmp(ff->style_name, style) == 0)
				return i;
		}
	}
	return -1;
}

// FamilyFor
const char*
FontManager::FamilyFor(const entry_ref* fontFile) const
{
	if (font_file* ff = _FontFileFor(fontFile))
		return ff->family_name;
	return NULL;
}

// StyleFor
const char*
FontManager::StyleFor(const entry_ref* fontFile) const
{
	if (font_file* ff = _FontFileFor(fontFile))
		return ff->style_name;
	return NULL;
}

// FullFamilyFor
const char*
FontManager::FullFamilyFor(const entry_ref* fontFile) const
{
	if (font_file* ff = _FontFileFor(fontFile))
		return ff->full_family_name;
	return NULL;
}

// PostScriptNameFor
const char*
FontManager::PostScriptNameFor(const entry_ref* fontFile) const
{
	if (font_file* ff = _FontFileFor(fontFile))
		return ff->ps_name;
	return NULL;
}

// CountFontFiles
int32
FontManager::CountFontFiles() const
{
	return fFontFiles.CountItems();
}

// PopulateMenu
void
FontManager::PopulateMenu(BMenu* menu, bool subMenus,
						  const char* markedFamily,
						  const char* markedStyle)
{
	if (menu && markedFamily && markedStyle && Lock()) {
		if (subMenus) {
			BMenu* fontMenu = NULL;
			for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {

				BMessage* message = new BMessage(MSG_SET_FONT);
				message->AddString("font family", ff->family_name);
				message->AddString("font style", ff->style_name);

				FontMenuItem* item = new FontMenuItem(ff->style_name,
													  ff->family_name,
													  ff->style_name,
													  message);
				bool markStyle = false;
				if (!fontMenu || (fontMenu->Name() && ff->family_name
								  && strcmp(fontMenu->Name(), ff->family_name) != 0)) {
					// create new entry
					fontMenu = new BMenu(ff->family_name);
					fontMenu->AddItem(item);
					menu->AddItem(fontMenu);
					// mark the menu if necessary
					if (strcmp(markedFamily, ff->family_name) == 0) {
						if (BMenuItem* superItem = fontMenu->Superitem())
							superItem->SetMarked(true);
						markStyle = true;
					}
				} else {
					// reuse old entry
					fontMenu->AddItem(item);
				}
				// mark the item if necessary
				if (markStyle && strcmp(markedStyle, ff->style_name) == 0)
					item->SetMarked(true);
			}
		} else {
			const char* previousFamily = NULL;
			for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {
				if (previousFamily && strcmp(previousFamily, ff->family_name) != 0)
					menu->AddSeparatorItem();
				BString label;
				label << ff->family_name << ", " << ff->style_name;

				BMessage* message = new BMessage(MSG_SET_FONT);
				message->AddString("font family", ff->family_name);
				message->AddString("font style", ff->style_name);

				FontMenuItem* item = new FontMenuItem(label.String(),
													  ff->family_name,
													  ff->style_name,
													  message);
				menu->AddItem(item);
				if (strcmp(markedFamily, ff->family_name) == 0 && strcmp(markedStyle, ff->style_name) == 0)
					item->SetMarked(true);
				previousFamily = ff->family_name;
			}
		}
		Unlock();
	}
}

// _MakeEmpty
void
FontManager::_MakeEmpty()
{
	int32 i = fFontFiles.CountItems() - 1;
	while (i >= 0) {
		if (font_file* ff = (font_file*)fFontFiles.ItemAt(i)) {
			_DeleteFontFile(ff);
		}
		i--;
	}
	fFontFiles.MakeEmpty();
}

// _DeleteFontFile
void
FontManager::_DeleteFontFile(font_file* ff) const
{
	if (ff->family_name)
		free(ff->family_name);
	if (ff->style_name)
		free(ff->style_name);
	if (ff->full_family_name)
		free(ff->full_family_name);
	if (ff->ps_name)
		free(ff->ps_name);
	delete ff;
}

// _update
int32
FontManager::_update(void* cookie)
{
	FontManager* fm = (FontManager*)cookie;
	if (fm && fm->Lock()) {
//bigtime_t now = system_time();
		// update from system, common and user fonts folders
		BPath path;
		if (find_directory(B_SYSTEM_FONTS_DIRECTORY, &path) >= B_OK) {
			BDirectory fontFolder(path.Path());
			fm->_Update(&fontFolder);
		}
/*			if (find_directory(B_USER_FONTS_DIRECTORY, &path) >= B_OK) {
			BDirectory fontFolder(path.Path());
			_Update(&fontFolder);
		}*/
/*printf("scanning fonts: %lld µsecs\n", system_time() - now);
for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {
	printf("fond %ld: \"%s, %s\"\n", i, ff->family_name, ff->style_name);
}*/
		fm->Unlock();
	}
	return 0;
}

//_Update
void
FontManager::_Update(BDirectory* fontFolder)
{
	fontFolder->Rewind();
	// scan the entire folder for font files
	BEntry entry;
	while (fontFolder->GetNextEntry(&entry) >= B_OK) {
		if (entry.IsDirectory()) {
			// recursive scan of sub folders
			BDirectory subFolder(&entry);
			_Update(&subFolder);
		} else {
			// see if this is a usable font file
			BPath path;
			if (entry.GetPath(&path) >= B_OK) {
				FT_Face face;
				FT_Error error = FT_New_Face(fLibrary, path.Path(), 0, &face);
				if (!error && face->family_name && face->style_name) {
					// create font_file object and init it
					font_file* fontFile = new font_file;
					entry.GetRef(&fontFile->ref);
					fontFile->family_name = strdup(face->family_name);
					fontFile->style_name = strdup(face->style_name);
					fontFile->full_family_name = NULL;
					fontFile->ps_name = NULL;
					// iterate over the names we find for this font face
					int32 nameCount = FT_Get_Sfnt_Name_Count(face);
					FT_SfntName fontName;
//printf("\n\nfont: '%s'/'%s':\n", fontFile->family_name, fontFile->style_name);
					for (int32 i = 0; (fontFile->full_family_name == NULL || fontFile->ps_name == NULL)
									  && i < nameCount; i++) {
						if (FT_Get_Sfnt_Name(face, i, &fontName ) == 0) {
							switch (fontName.platform_id) {
								case TT_PLATFORM_APPLE_UNICODE:
//printf("  platform: TT_PLATFORM_APPLE_UNICODE\n");
									// TODO: implement
									break;
								case TT_PLATFORM_MACINTOSH:
//printf("  platform: TT_PLATFORM_MACINTOSH\n");
									if (fontName.encoding_id == TT_MAC_ID_ROMAN) {
										if (fontName.name_id == TT_NAME_ID_FONT_FAMILY) {
											fontFile->full_family_name = (char*)malloc(fontName.string_len + 1);
											memcpy(fontFile->full_family_name, fontName.string, fontName.string_len);
											fontFile->full_family_name[fontName.string_len] = 0;

											if (fontFile->family_name)
												free(fontFile->family_name);
											fontFile->family_name = strdup(fontFile->full_family_name);
										} else if (fontName.name_id == TT_NAME_ID_PS_NAME) {
											fontFile->ps_name = (char*)malloc(fontName.string_len + 1);
											memcpy(fontFile->ps_name, fontName.string, fontName.string_len);
											fontFile->ps_name[fontName.string_len] = 0;
										}
									}
									break;
								case TT_PLATFORM_MICROSOFT:
//printf("  platform: TT_PLATFORM_MICROSOFT\n");
									// TODO: implement
									if (fontName.encoding_id == TT_MS_ID_UNICODE_CS) {
										if (fontName.name_id == TT_NAME_ID_FONT_FAMILY
											|| fontName.name_id == TT_NAME_ID_PS_NAME) {
											int32 length = fontName.string_len + 1;
											char* buffer = (char*)malloc(length);
											memcpy(buffer, fontName.string, length - 1);
											buffer[length - 1] = 0;
											int32 state = 0;
											convert_to_utf8(B_UNICODE_CONVERSION,
															buffer,
															&length,
															buffer,
															&length,
															&state,
															B_SUBSTITUTE);
											if (fontName.name_id == TT_NAME_ID_FONT_FAMILY)
												fontFile->full_family_name = buffer;
											else if (fontName.name_id == TT_NAME_ID_PS_NAME)
												fontFile->ps_name = buffer;
//printf("uni-code name: '%s' (orig-length: %d, length: %ld)\n", buffer, fontName.string_len, length);
										}
									}
									break;
							}
						}
/*
char* name = (char*)malloc(fontName.string_len + 1);
memcpy(name, fontName.string, fontName.string_len);
name[fontName.string_len] = 0;
printf("  %d, %d, ", fontName.encoding_id, fontName.name_id);
printf("name: '%s'\n", name);
free(name);
*/
					}
					// find slot in sorted list and add it
					int32 i = 0;
					bool duplicate = false;
					font_file* ff;
					while ((ff = (font_file*)fFontFiles.ItemAt(i))
						   && strcasecmp(fontFile->family_name, ff->family_name) >= 0) {
						if (strcasecmp(fontFile->family_name, ff->family_name) == 0) {
							while ((ff = (font_file*)fFontFiles.ItemAt(i))
								   && strcasecmp(fontFile->family_name, ff->family_name) == 0
								   && strcasecmp(fontFile->style_name, ff->style_name) >= 0) {
								if (strcasecmp(fontFile->style_name, ff->style_name) == 0) {
									duplicate = true;
									break;
								} else
								   i++;
							}
							break;
					   }
					   i++;
					}
					if (!duplicate) {
						fFontFiles.AddItem((void*)fontFile, i);
					} else {
						_DeleteFontFile(fontFile);
					}
					FT_Done_Face(face);
				}
			}
		}
	}
}

// _FontFileFor
FontManager::font_file*
FontManager::_FontFileFor(const entry_ref* ref) const
{
	if (ref) {
		for (int32 i = 0; font_file* ff = (font_file*)fFontFiles.ItemAt(i); i++) {
			if (ff->ref == *ref) {
				return ff;
			}
		}
	}
	return NULL;
}

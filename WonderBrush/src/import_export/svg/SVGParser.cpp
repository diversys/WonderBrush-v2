//----------------------------------------------------------------------------
// Anti-Grain Geometry - Version 2.2
// Copyright (C) 2002-2004 Maxim Shemanarev (http://www.antigrain.com)
//
// Permission to copy, use, modify, sell and distribute this software 
// is granted provided this copyright notice appears in all copies. 
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//
//----------------------------------------------------------------------------
// Contact: mcseem@antigrain.com
//		  mcseemagg@yahoo.com
//		  http://www.antigrain.com
//----------------------------------------------------------------------------
//
// SVG Parser.
//
//----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <expat.h>

#include "SVGGradients.h"

#include "SVGParser.h"

namespace agg
{
namespace svg
{

struct named_color
{
	char  name[22];
	int8u r, g, b, a;
};

named_color colors[] = 
{
	{ "aliceblue",240,248,255, 255 },
	{ "antiquewhite",250,235,215, 255 },
	{ "aqua",0,255,255, 255 },
	{ "aquamarine",127,255,212, 255 },
	{ "azure",240,255,255, 255 },
	{ "beige",245,245,220, 255 },
	{ "bisque",255,228,196, 255 },
	{ "black",0,0,0, 255 },
	{ "blanchedalmond",255,235,205, 255 },
	{ "blue",0,0,255, 255 },
	{ "blueviolet",138,43,226, 255 },
	{ "brown",165,42,42, 255 },
	{ "burlywood",222,184,135, 255 },
	{ "cadetblue",95,158,160, 255 },
	{ "chartreuse",127,255,0, 255 },
	{ "chocolate",210,105,30, 255 },
	{ "coral",255,127,80, 255 },
	{ "cornflowerblue",100,149,237, 255 },
	{ "cornsilk",255,248,220, 255 },
	{ "crimson",220,20,60, 255 },
	{ "cyan",0,255,255, 255 },
	{ "darkblue",0,0,139, 255 },
	{ "darkcyan",0,139,139, 255 },
	{ "darkgoldenrod",184,134,11, 255 },
	{ "darkgray",169,169,169, 255 },
	{ "darkgreen",0,100,0, 255 },
	{ "darkgrey",169,169,169, 255 },
	{ "darkkhaki",189,183,107, 255 },
	{ "darkmagenta",139,0,139, 255 },
	{ "darkolivegreen",85,107,47, 255 },
	{ "darkorange",255,140,0, 255 },
	{ "darkorchid",153,50,204, 255 },
	{ "darkred",139,0,0, 255 },
	{ "darksalmon",233,150,122, 255 },
	{ "darkseagreen",143,188,143, 255 },
	{ "darkslateblue",72,61,139, 255 },
	{ "darkslategray",47,79,79, 255 },
	{ "darkslategrey",47,79,79, 255 },
	{ "darkturquoise",0,206,209, 255 },
	{ "darkviolet",148,0,211, 255 },
	{ "deeppink",255,20,147, 255 },
	{ "deepskyblue",0,191,255, 255 },
	{ "dimgray",105,105,105, 255 },
	{ "dimgrey",105,105,105, 255 },
	{ "dodgerblue",30,144,255, 255 },
	{ "firebrick",178,34,34, 255 },
	{ "floralwhite",255,250,240, 255 },
	{ "forestgreen",34,139,34, 255 },
	{ "fuchsia",255,0,255, 255 },
	{ "gainsboro",220,220,220, 255 },
	{ "ghostwhite",248,248,255, 255 },
	{ "gold",255,215,0, 255 },
	{ "goldenrod",218,165,32, 255 },
	{ "gray",128,128,128, 255 },
	{ "green",0,128,0, 255 },
	{ "greenyellow",173,255,47, 255 },
	{ "grey",128,128,128, 255 },
	{ "honeydew",240,255,240, 255 },
	{ "hotpink",255,105,180, 255 },
	{ "indianred",205,92,92, 255 },
	{ "indigo",75,0,130, 255 },
	{ "ivory",255,255,240, 255 },
	{ "khaki",240,230,140, 255 },
	{ "lavender",230,230,250, 255 },
	{ "lavenderblush",255,240,245, 255 },
	{ "lawngreen",124,252,0, 255 },
	{ "lemonchiffon",255,250,205, 255 },
	{ "lightblue",173,216,230, 255 },
	{ "lightcoral",240,128,128, 255 },
	{ "lightcyan",224,255,255, 255 },
	{ "lightgoldenrodyellow",250,250,210, 255 },
	{ "lightgray",211,211,211, 255 },
	{ "lightgreen",144,238,144, 255 },
	{ "lightgrey",211,211,211, 255 },
	{ "lightpink",255,182,193, 255 },
	{ "lightsalmon",255,160,122, 255 },
	{ "lightseagreen",32,178,170, 255 },
	{ "lightskyblue",135,206,250, 255 },
	{ "lightslategray",119,136,153, 255 },
	{ "lightslategrey",119,136,153, 255 },
	{ "lightsteelblue",176,196,222, 255 },
	{ "lightyellow",255,255,224, 255 },
	{ "lime",0,255,0, 255 },
	{ "limegreen",50,205,50, 255 },
	{ "linen",250,240,230, 255 },
	{ "magenta",255,0,255, 255 },
	{ "maroon",128,0,0, 255 },
	{ "mediumaquamarine",102,205,170, 255 },
	{ "mediumblue",0,0,205, 255 },
	{ "mediumorchid",186,85,211, 255 },
	{ "mediumpurple",147,112,219, 255 },
	{ "mediumseagreen",60,179,113, 255 },
	{ "mediumslateblue",123,104,238, 255 },
	{ "mediumspringgreen",0,250,154, 255 },
	{ "mediumturquoise",72,209,204, 255 },
	{ "mediumvioletred",199,21,133, 255 },
	{ "midnightblue",25,25,112, 255 },
	{ "mintcream",245,255,250, 255 },
	{ "mistyrose",255,228,225, 255 },
	{ "moccasin",255,228,181, 255 },
	{ "navajowhite",255,222,173, 255 },
	{ "navy",0,0,128, 255 },
	{ "oldlace",253,245,230, 255 },
	{ "olive",128,128,0, 255 },
	{ "olivedrab",107,142,35, 255 },
	{ "orange",255,165,0, 255 },
	{ "orangered",255,69,0, 255 },
	{ "orchid",218,112,214, 255 },
	{ "palegoldenrod",238,232,170, 255 },
	{ "palegreen",152,251,152, 255 },
	{ "paleturquoise",175,238,238, 255 },
	{ "palevioletred",219,112,147, 255 },
	{ "papayawhip",255,239,213, 255 },
	{ "peachpuff",255,218,185, 255 },
	{ "peru",205,133,63, 255 },
	{ "pink",255,192,203, 255 },
	{ "plum",221,160,221, 255 },
	{ "powderblue",176,224,230, 255 },
	{ "purple",128,0,128, 255 },
	{ "red",255,0,0, 255 },
	{ "rosybrown",188,143,143, 255 },
	{ "royalblue",65,105,225, 255 },
	{ "saddlebrown",139,69,19, 255 },
	{ "salmon",250,128,114, 255 },
	{ "sandybrown",244,164,96, 255 },
	{ "seagreen",46,139,87, 255 },
	{ "seashell",255,245,238, 255 },
	{ "sienna",160,82,45, 255 },
	{ "silver",192,192,192, 255 },
	{ "skyblue",135,206,235, 255 },
	{ "slateblue",106,90,205, 255 },
	{ "slategray",112,128,144, 255 },
	{ "slategrey",112,128,144, 255 },
	{ "snow",255,250,250, 255 },
	{ "springgreen",0,255,127, 255 },
	{ "steelblue",70,130,180, 255 },
	{ "tan",210,180,140, 255 },
	{ "teal",0,128,128, 255 },
	{ "thistle",216,191,216, 255 },
	{ "tomato",255,99,71, 255 },
	{ "turquoise",64,224,208, 255 },
	{ "violet",238,130,238, 255 },
	{ "wheat",245,222,179, 255 },
	{ "white",255,255,255, 255 },
	{ "whitesmoke",245,245,245, 255 },
	{ "yellow",255,255,0, 255 },
	{ "yellowgreen",154,205,50, 255 },
	{ "zzzzzzzzzzz",0,0,0, 0 }
}; 



// cmp_color
int
cmp_color(const void* p1, const void* p2)
{
	return strcmp(((named_color*)p1)->name, ((named_color*)p2)->name);
}

// parse_color
rgba8
parse_color(const char* str)
{
	while(*str == ' ') ++str;
	if (*str == '#') {
		str++;
		int32 length = strlen(str);
		unsigned c = 0;
		if (length == 3) {
			// if there are only 3 byte, than it means that we
			// need to expand the color (#f60 -> #ff6600)
			// TODO: There must be an easier way...
			char expanded[7];
			expanded[0] = *str;
			expanded[1] = *str++;
			expanded[2] = *str;
			expanded[3] = *str++;
			expanded[4] = *str;
			expanded[5] = *str++;
			expanded[6] = 0;
			sscanf(expanded, "%x", &c);
		} else {
			sscanf(str, "%x", &c);
		}
		return rgb8_packed(c);
	} else {
		named_color c;
		unsigned len = strlen(str);
		if(len > sizeof(c.name) - 1)
		{
			throw exception("parse_color: Invalid color name '%s'", str);
		}
		strcpy(c.name, str);
		const void* p = bsearch(&c, 
								colors, 
								sizeof(colors) / sizeof(colors[0]), 
								sizeof(colors[0]), 
								cmp_color);
		if(p == 0)
		{
			throw exception("parse_color: Invalid color name '%s'", str);
		}
		const named_color* pc = (const named_color*)p;
		return rgba8(pc->r, pc->g, pc->b, pc->a);
	}
}

// parse_double
double
parse_double(const char* str)
{
	while(*str == ' ') ++str;
	double value = atof(str);
	// handle percent
	int32 length = strlen(str);
	if (str[length - 1] == '%')
		value /= 100.0;
	return value;
}

// parse_url
char*
parse_url(const char* str)
{
	const char* begin = str;
	while (*begin != '#')
		begin++;

	begin++;
	const char* end = begin;
	while (*end != ')')
		end++;

	end--;

	int32 length = end - begin + 2;
	char* result = new char[length];
	memcpy(result, begin, length - 1);
	result[length - 1] = 0;

	return result;
}


//------------------------------------------------------------------------

// constructor
Parser::Parser(DocumentBuilder& path)
	: fBuilder(path),
	  fPathTokenizer(),
	  fBuffer(new char[buf_size]),
	  fTitle(new char[256]),
	  fTitleLength(0),

	  fTitleFlag(false),
	  fPathFlag(false),

	  fAttrName(new char[128]),
	  fAttrValue(new char[1024]),
	  fAttrNameLength(127),
	  fAttrValueLength(1023),

	  fTagsIgnored(false)
{
	fTitle[0] = 0;
}

// destructor
Parser::~Parser()
{
	delete [] fAttrValue;
	delete [] fAttrName;
	delete [] fBuffer;
	delete [] fTitle;
}

// parse
void
Parser::parse(const char* fname)
{
	char msg[1024];
	XML_Parser p = XML_ParserCreate(NULL);
	if (p == 0) {
		throw exception("Couldn't allocate memory for Parser");
	}

	XML_SetUserData(p, this);
	XML_SetElementHandler(p, start_element, end_element);
	XML_SetCharacterDataHandler(p, content);

	FILE* fd = fopen(fname, "r");
	if (fd == 0) {
		sprintf(msg, "Couldn't open file %s", fname);
		throw exception(msg);
	}

	bool done = false;
	do {
		size_t len = fread(fBuffer, 1, buf_size, fd);
		done = len < buf_size;
		if (!XML_Parse(p, fBuffer, len, done)) {
			sprintf(msg, "%s at line %d\n",
					XML_ErrorString(XML_GetErrorCode(p)),
					XML_GetCurrentLineNumber(p));
			throw exception(msg);
		}
	} while (!done);

	fclose(fd);
	XML_ParserFree(p);

	char* ts = fTitle;
	while (*ts) {
		if (*ts < ' ') *ts = ' ';
		++ts;
	}
}

// start_element
void
Parser::start_element(void* data, const char* el, const char** attr)
{
//printf("Parser::start_element(%s)\n", el);
	Parser& self = *(Parser*)data;

	if (strcmp(el, "svg") == 0)
	{
		self.parse_svg(attr);
	}
	else
	if (strcmp(el, "title") == 0)
	{
		self.fTitleFlag = true;
	}
	else
	if (strcmp(el, "g") == 0)
	{
		self.fBuilder.push_attr();
		self.parse_attr(attr);
	}
	else
	if (strcmp(el, "path") == 0)
	{
		if (self.fPathFlag) {
			throw exception("start_element: Nested path");
		}
		self.fBuilder.begin_path();
		self.parse_path(attr);
		self.fBuilder.end_path();
		self.fPathFlag = true;
	}
	else
	if (strcmp(el, "circle") == 0)
	{
		self.parse_circle(attr);
	}
	else
	if (strcmp(el, "ellipse") == 0)
	{
		self.parse_ellipse(attr);
	}
	else
	if (strcmp(el, "rect") == 0)
	{
		self.parse_rect(attr);
	}
	else
	if (strcmp(el, "line") == 0)
	{
		self.parse_line(attr);
	}
	else
	if (strcmp(el, "polyline") == 0)
	{
		self.parse_poly(attr, false);
	}
	else
	if (strcmp(el, "polygon") == 0)
	{
		self.parse_poly(attr, true);
	}
	else
	if (strcmp(el, "linearGradient") == 0 || strcmp(el, "radialGradient") == 0)
	{
		self.parse_gradient(attr, strcmp(el, "radialGradient") == 0);
	}
	else
	if (strcmp(el, "stop") == 0)
	{
		self.parse_gradient_stop(attr);
	}
	//else
	//if(strcmp(el, "<OTHER_ELEMENTS>") == 0) 
	//{
	//}
	// . . .
	else
	{
		fprintf(stderr, "SVGParser igoring tag: \"%s\"\n", el);
		self.fTagsIgnored = true;
	}
} 

// end_element
void
Parser::end_element(void* data, const char* el)
{
	Parser& self = *(Parser*)data;

	if (strcmp(el, "title") == 0)
	{
		self.fTitleFlag = false;
		self.fBuilder.SetTitle(self.fTitle);
	}
	else
	if (strcmp(el, "g") == 0)
	{
		self.fBuilder.pop_attr();
	}
	else
	if (strcmp(el, "path") == 0)
	{
		self.fPathFlag = false;
	}
	else
	if (strcmp(el, "linearGradient") == 0 || strcmp(el, "radialGradient") == 0)
	{
		self.fBuilder.EndGradient();
	}
	//else
	//if(strcmp(el, "<OTHER_ELEMENTS>") == 0) 
	//{
	//}
	// . . .
}

// content
void
Parser::content(void* data, const char* s, int len)
{
	Parser& self = *(Parser*)data;

	// fTitleFlag signals that the <title> tag is being parsed now.
	// The following code concatenates the pieces of content of the <title> tag.
	if(self.fTitleFlag)
	{
		if(len + self.fTitleLength > 255) len = 255 - self.fTitleLength;
		if(len > 0) 
		{
			memcpy(self.fTitle + self.fTitleLength, s, len);
			self.fTitleLength += len;
			self.fTitle[self.fTitleLength] = 0;
		}
	}
}

// parse_svg
void Parser::parse_svg(const char** attr)
{
	double width = 0.0;
	double height = 0.0;
	BRect viewBox(0.0, 0.0, -1.0, -1.0);

	for (int i = 0; attr[i]; i += 2) {
		if (strcmp(attr[i], "width") == 0)
		{
			width = parse_double(attr[i + 1]);
		}
		else
		if (strcmp(attr[i], "height") == 0)
		{
			height = parse_double(attr[i + 1]);
		}
		else
		if (strcmp(attr[i], "viewBox") == 0)
		{
			fPathTokenizer.set_path_str(attr[i + 1]);
			if(!fPathTokenizer.next())
			{
				throw exception("parse_svg (viewBox): Too few coordinates");
			}
			viewBox.left = fPathTokenizer.last_number();
			if(!fPathTokenizer.next())
			{
				throw exception("parse_svg (viewBox): Too few coordinates");
			}
			viewBox.top = fPathTokenizer.last_number();
			if(!fPathTokenizer.next())
			{
				throw exception("parse_svg (viewBox): Too few coordinates");
			}
			viewBox.right = fPathTokenizer.last_number();
			if(!fPathTokenizer.next())
			{
				throw exception("parse_svg (viewBox): Too few coordinates");
			}
			viewBox.bottom = fPathTokenizer.last_number();
		}
	}
	if (width >= 0.0 && height >= 0.0) {
		fBuilder.SetDimensions((uint32)ceil(width), (uint32)ceil(height), viewBox);
	} else {
		throw exception("parse_svg: Invalid width or height\n");
	}
}

// parse_attr
void Parser::parse_attr(const char** attr)
{
	for (int i = 0; attr[i]; i += 2) {
		if (strcmp(attr[i], "style") == 0) {
			parse_style(attr[i + 1]);
		} else {
			parse_attr(attr[i], attr[i + 1]);
		}
	}
}

// parse_path
void Parser::parse_path(const char** attr)
{
	int i;

	for(i = 0; attr[i]; i += 2)
	{
		// The <path> tag can consist of the path itself ("d=") 
		// as well as of other parameters like "style=", "transform=", etc.
		// In the last case we simply rely on the function of parsing 
		// attributes (see 'else' branch).
		if(strcmp(attr[i], "d") == 0)
		{
			fPathTokenizer.set_path_str(attr[i + 1]);
			fBuilder.parse_path(fPathTokenizer);
		}
		else
		{
			// Create a temporary single pair "name-value" in order
			// to avoid multiple calls for the same attribute.
			const char* tmp[4];
			tmp[0] = attr[i];
			tmp[1] = attr[i + 1];
			tmp[2] = 0;
			tmp[3] = 0;
			parse_attr(tmp);
		}
	}
}

// parse_attr
bool
Parser::parse_attr(const char* name, const char* value)
{
	if(strcmp(name, "style") == 0) {
		parse_style(value);
	} else
	if(strcmp(name, "opacity") == 0) {
		fBuilder.opacity(parse_double(value));
	} else
	if(strcmp(name, "fill") == 0) {
		if(strcmp(value, "none") == 0) {
			fBuilder.fill_none();
		} else if (strncmp(value, "url", 3) == 0) {
			char* url = parse_url(value);
			fBuilder.fill_url(url);
			delete[] url;
		} else {
			fBuilder.fill(parse_color(value));
		}
	} else
	if(strcmp(name, "fill-opacity") == 0) {
		fBuilder.fill_opacity(parse_double(value));
	} else
	if(strcmp(name, "fill-rule") == 0) {
		fBuilder.even_odd(strcmp(value, "evenodd") == 0);
	} else
	if(strcmp(name, "stroke") == 0) {
		if(strcmp(value, "none") == 0) {
			fBuilder.stroke_none();
		} else if (strncmp(value, "url", 3) == 0) {
			char* url = parse_url(value);
			fBuilder.stroke_url(url);
			delete[] url;
		} else {
			fBuilder.stroke(parse_color(value));
		}
	} else
	if(strcmp(name, "stroke-width") == 0) {
		fBuilder.stroke_width(parse_double(value));
	} else
	if(strcmp(name, "stroke-linecap") == 0) {
		if(strcmp(value, "butt") == 0)		fBuilder.line_cap(butt_cap);
		else if(strcmp(value, "round") == 0)  fBuilder.line_cap(round_cap);
		else if(strcmp(value, "square") == 0) fBuilder.line_cap(square_cap);
	} else
	if(strcmp(name, "stroke-linejoin") == 0) {
		if(strcmp(value, "miter") == 0)	  fBuilder.line_join(miter_join);
		else if(strcmp(value, "round") == 0) fBuilder.line_join(round_join);
		else if(strcmp(value, "bevel") == 0) fBuilder.line_join(bevel_join);
	} else
	if(strcmp(name, "stroke-miterlimit") == 0) {
		fBuilder.miter_limit(parse_double(value));
	} else
	if(strcmp(name, "stroke-opacity") == 0) {
		fBuilder.stroke_opacity(parse_double(value));
	} else
	if(strcmp(name, "transform") == 0) {
		fBuilder.transform().premultiply(parse_transform(value));
	} else
	if (strcmp(name, "stop-color") == 0) {
		fGradientStopColor = parse_color(value);
	} else
	if (strcmp(name, "stop-opacity") == 0) {
		fGradientStopColor.opacity(parse_double(value));
	}
	//else
	//if(strcmp(el, "<OTHER_ATTRIBUTES>") == 0) 
	//{
	//}
	// . . .
	else
	{
		return false;
	}
	return true;
}

// copy_name
void Parser::copy_name(const char* start, const char* end)
{
	unsigned len = unsigned(end - start);
	if(fAttrNameLength == 0 || len > fAttrNameLength)
	{
		delete [] fAttrName;
		fAttrName = new char[len + 1];
		fAttrNameLength = len;
	}
	if(len) memcpy(fAttrName, start, len);
	fAttrName[len] = 0;
}

// copy_value
void Parser::copy_value(const char* start, const char* end)
{
	unsigned len = unsigned(end - start);
	if(fAttrValueLength == 0 || len > fAttrValueLength)
	{
		delete [] fAttrValue;
		fAttrValue = new char[len + 1];
		fAttrValueLength = len;
	}
	if(len) memcpy(fAttrValue, start, len);
	fAttrValue[len] = 0;
}

// parse_name_value
bool Parser::parse_name_value(const char* nv_start, const char* nv_end)
{
	const char* str = nv_start;
	while(str < nv_end && *str != ':') ++str;

	const char* val = str;

	// Right Trim
	while(str > nv_start && 
		(*str == ':' || isspace(*str))) --str;
	++str;

	copy_name(nv_start, str);

	while(val < nv_end && (*val == ':' || isspace(*val))) ++val;
	
	copy_value(val, nv_end);
	return parse_attr(fAttrName, fAttrValue);
}

// parse_style
void Parser::parse_style(const char* str)
{
	while(*str)
	{
		// Left Trim
		while(*str && isspace(*str)) ++str;
		const char* nv_start = str;
		while(*str && *str != ';') ++str;
		const char* nv_end = str;

		// Right Trim
		while(nv_end > nv_start && 
			(*nv_end == ';' || isspace(*nv_end))) --nv_end;
		++nv_end;

		parse_name_value(nv_start, nv_end);
		if(*str) ++str;
	}

}

// parse_circle
void
Parser::parse_circle(const char** attr)
{
	int i;
	double cx = 0.0;
	double cy = 0.0;
	double r = 0.0;

	fBuilder.begin_path();
	for(i = 0; attr[i]; i += 2) {
		if (!parse_attr(attr[i], attr[i + 1])) {
			if(strcmp(attr[i], "cx") == 0)	cx = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "cy") == 0)	cy = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "r") == 0)	r = parse_double(attr[i + 1]);
		}
	}


	if (r != 0.0) {
		if (r < 0.0) throw exception("parse_circle: Invalid radius: %f", r);

		fBuilder.move_to(cx, cy - r);
		fBuilder.curve4(cx + r * 0.56, cy - r,
						cx + r, cy - r * 0.56,
						cx + r, cy);
		fBuilder.curve4(cx + r, cy + r * 0.56,
						cx + r * 0.56, cy + r,
						cx, cy + r);
		fBuilder.curve4(cx - r * 0.56, cy + r,
						cx - r, cy + r * 0.56,
						cx - r, cy);
		fBuilder.curve4(cx - r, cy - r * 0.56,
						cx - r * 0.56, cy - r,
						cx, cy - r);
		fBuilder.close_subpath();
	}
	fBuilder.end_path();
}

// parse_ellipse
void
Parser::parse_ellipse(const char** attr)
{
	int i;
	double cx = 0.0;
	double cy = 0.0;
	double rx = 0.0;
	double ry = 0.0;

	fBuilder.begin_path();
	for(i = 0; attr[i]; i += 2) {
		if (!parse_attr(attr[i], attr[i + 1])) {
			if(strcmp(attr[i], "cx") == 0)	cx = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "cy") == 0)	cy = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "rx") == 0)	rx = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "ry") == 0)	ry = parse_double(attr[i + 1]);
		}
	}


	if (rx != 0.0 && ry != 0.0) {
		if (rx < 0.0) throw exception("parse_ellipse: Invalid x-radius: %f", rx);
		if (ry < 0.0) throw exception("parse_ellipse: Invalid y-radius: %f", ry);

		fBuilder.move_to(cx, cy - ry);
		fBuilder.curve4(cx + rx * 0.56, cy - ry,
						cx + rx, cy - ry * 0.56,
						cx + rx, cy);
		fBuilder.curve4(cx + rx, cy + ry * 0.56,
						cx + rx * 0.56, cy + ry,
						cx, cy + ry);
		fBuilder.curve4(cx - rx * 0.56, cy + ry,
						cx - rx, cy + ry * 0.56,
						cx - rx, cy);
		fBuilder.curve4(cx - rx, cy - ry * 0.56,
						cx - rx * 0.56, cy - ry,
						cx, cy - ry);
		fBuilder.close_subpath();
	}
	fBuilder.end_path();
}

// parse_rect
void
Parser::parse_rect(const char** attr)
{
	int i;
	double x = 0.0;
	double y = 0.0;
	double w = 0.0;
	double h = 0.0;

	fBuilder.begin_path();
	for(i = 0; attr[i]; i += 2)
	{
		if(!parse_attr(attr[i], attr[i + 1]))
		{
			if(strcmp(attr[i], "x") == 0)	  x = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "y") == 0)	  y = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "width") == 0)  w = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "height") == 0) h = parse_double(attr[i + 1]);
			// rx - to be implemented 
			// ry - to be implemented
		}
	}


	if(w != 0.0 && h != 0.0)
	{
		if(w < 0.0) throw exception("parse_rect: Invalid width: %f", w);
		if(h < 0.0) throw exception("parse_rect: Invalid height: %f", h);

		fBuilder.move_to(x,	 y);
		fBuilder.line_to(x + w, y);
		fBuilder.line_to(x + w, y + h);
		fBuilder.line_to(x,	 y + h);
		fBuilder.close_subpath();
	}
	fBuilder.end_path();
}

// parse_line
void
Parser::parse_line(const char** attr)
{
	int i;
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 0.0;
	double y2 = 0.0;

	fBuilder.begin_path();
	for(i = 0; attr[i]; i += 2)
	{
		if(!parse_attr(attr[i], attr[i + 1]))
		{
			if(strcmp(attr[i], "x1") == 0) x1 = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "y1") == 0) y1 = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "x2") == 0) x2 = parse_double(attr[i + 1]);
			if(strcmp(attr[i], "y2") == 0) y2 = parse_double(attr[i + 1]);
		}
	}

	fBuilder.move_to(x1, y1);
	fBuilder.line_to(x2, y2);
	fBuilder.end_path();
}

// parse_poly
void
Parser::parse_poly(const char** attr, bool close_flag)
{
	int i;
	double x = 0.0;
	double y = 0.0;

	fBuilder.begin_path();
	for (i = 0; attr[i]; i += 2) {
		if (!parse_attr(attr[i], attr[i + 1])) {
			if (strcmp(attr[i], "points") == 0) {
				fPathTokenizer.set_path_str(attr[i + 1]);
				if (!fPathTokenizer.next())
					throw exception("parse_poly: Too few coordinates");
				x = fPathTokenizer.last_number();
				if (!fPathTokenizer.next())
					throw exception("parse_poly: Too few coordinates");
				y = fPathTokenizer.last_number();
				fBuilder.move_to(x, y);
				while (fPathTokenizer.next()) {
					x = fPathTokenizer.last_number();
					if (!fPathTokenizer.next())
						throw exception("parse_poly: Odd number of coordinates");
					y = fPathTokenizer.last_number();
					fBuilder.line_to(x, y);
				}
			}
		}
	}
	if (close_flag)
		fBuilder.close_subpath();
	fBuilder.end_path();
}

// parse_transform
trans_affine
Parser::parse_transform(const char* str)
{
	trans_affine transform;
	while (*str) {
		if (islower(*str)) {
			if (strncmp(str, "matrix", 6) == 0)		str += parse_matrix(str, transform);	else 
			if (strncmp(str, "translate", 9) == 0)	str += parse_translate(str, transform);	else 
			if (strncmp(str, "rotate", 6) == 0)		str += parse_rotate(str, transform);	else 
			if (strncmp(str, "scale", 5) == 0)		str += parse_scale(str, transform);		else 
			if (strncmp(str, "skewX", 5) == 0)		str += parse_skew_x(str, transform);	else 
			if (strncmp(str, "skewY", 5) == 0)		str += parse_skew_y(str, transform);	else
			{
				++str;
			}
		}
		else
		{
			++str;
		}
	}
	return transform;
}

// parse_gradient
void
Parser::parse_gradient(const char** attr, bool radial)
{
//	printf("Parser::parse_gradient(%s)\n", attr[0]);

	fBuilder.StartGradient(radial);

	for (int32 i = 0; attr[i]; i += 2)
	{
/*		if(!parse_attr(attr[i], attr[i + 1]))
		{*/
			if (strcmp(attr[i], "id") == 0)
				fBuilder.CurrentGradient()->SetID(attr[i + 1]);
			else if(strcmp(attr[i], "gradientTransform") == 0) {
				fBuilder.CurrentGradient()->SetTransformation(parse_transform(attr[i + 1]));
			} else
				fBuilder.CurrentGradient()->AddString(attr[i], attr[i + 1]);
/*		}*/
	}
}

// parse_gradient_stop
void
Parser::parse_gradient_stop(const char** attr)
{
//	printf("Parser::parse_gradient_stop(%s)\n", attr[0]);

	float offset = 0.0;
	rgba8 color;
	for (int32 i = 0; attr[i]; i += 2) {
		if (strcmp(attr[i], "offset") == 0) {
			offset = parse_double(attr[i + 1]);
		} else
		if (strcmp(attr[i], "style") == 0) {
			parse_style(attr[i + 1]);
			// here we get a bit hacky, in order not to change too much code at once...
			// historically, parse_style() was for parsing path attributes only, but
			// it comes in handy here as well, and I added "stop-color" and "stop-opacity"
			// to parse_name_value(). It remembers the color in "fGradientStopColor".
			// The color will of course be broken if the "style" attribute did not contain
			// any valid stuff.
			color = fGradientStopColor;
		} else
		if (strcmp(attr[i], "stop-color") == 0) {
			color = parse_color(attr[i + 1]);
		} else
		if (strcmp(attr[i], "stop-opacity") == 0) {
			color.opacity(parse_double(attr[i + 1]));
		}
	}

//	printf("  offset: %f, color: %d, %d, %d, %d\n", offset, color.r, color.g, color.b, color.a);

	if (SVGGradient* gradient = fBuilder.CurrentGradient()) {
		gradient->AddStop(offset, color);
	} else {
		throw exception("parse_gradient_stop() outside of gradient tag!\n");
	}
}

// is_numeric
static bool
is_numeric(char c)
{
	return strchr("0123456789+-.eE", c) != 0;
}

// parse_transform_args
static unsigned
parse_transform_args(const char* str, 
					 double* args, 
					 unsigned max_na, 
					 unsigned* na)
{
	*na = 0;
	const char* ptr = str;
	while(*ptr && *ptr != '(') ++ptr;
	if(*ptr == 0)
	{
		throw exception("parse_transform_args: Invalid syntax");
	}
	const char* end = ptr;
	while(*end && *end != ')') ++end;
	if(*end == 0)
	{
		throw exception("parse_transform_args: Invalid syntax");
	}

	while(ptr < end)
	{
		if(is_numeric(*ptr))
		{
			if(*na >= max_na)
			{
				throw exception("parse_transform_args: Too many arguments");
			}
			args[(*na)++] = atof(ptr);
			while(ptr < end && is_numeric(*ptr)) ++ptr;
		}
		else
		{
			++ptr;
		}
	}
	return unsigned(end - str);
}

// parse_matrix
unsigned
Parser::parse_matrix(const char* str, trans_affine& transform)
{
	double args[6];
	unsigned na = 0;
	unsigned len = parse_transform_args(str, args, 6, &na);
	if(na != 6)
	{
		throw exception("parse_matrix: Invalid number of arguments");
	}
	transform.premultiply(trans_affine(args[0], args[1], args[2], args[3], args[4], args[5]));
	return len;
}

// parse_translate
unsigned
Parser::parse_translate(const char* str, trans_affine& transform)
{
	double args[2];
	unsigned na = 0;
	unsigned len = parse_transform_args(str, args, 2, &na);
	if(na == 1) args[1] = 0.0;
	transform.premultiply(trans_affine_translation(args[0], args[1]));
	return len;
}

// parse_rotate
unsigned
Parser::parse_rotate(const char* str, trans_affine& transform)
{
	double args[3];
	unsigned na = 0;
	unsigned len = parse_transform_args(str, args, 3, &na);
	if(na == 1) 
	{
		transform.premultiply(trans_affine_rotation(deg2rad(args[0])));
	}
	else if(na == 3)
	{
		trans_affine t = trans_affine_translation(-args[1], -args[2]);
		t *= trans_affine_rotation(deg2rad(args[0]));
		t *= trans_affine_translation(args[1], args[2]);
		transform.premultiply(t);
	}
	else
	{
		throw exception("parse_rotate: Invalid number of arguments");
	}
	return len;
}

// parse_scale
unsigned Parser::parse_scale(const char* str, trans_affine& transform)
{
	double args[2];
	unsigned na = 0;
	unsigned len = parse_transform_args(str, args, 2, &na);
	if(na == 1) args[1] = args[0];
	transform.premultiply(trans_affine_scaling(args[0], args[1]));
	return len;
}

// parse_skew_x
unsigned
Parser::parse_skew_x(const char* str, trans_affine& transform)
{
	double arg;
	unsigned na = 0;
	unsigned len = parse_transform_args(str, &arg, 1, &na);
	transform.premultiply(trans_affine_skewing(deg2rad(arg), 0.0));
	return len;
}

// parse_skew_y
unsigned
Parser::parse_skew_y(const char* str, trans_affine& transform)
{
	double arg;
	unsigned na = 0;
	unsigned len = parse_transform_args(str, &arg, 1, &na);
	transform.premultiply(trans_affine_skewing(0.0, deg2rad(arg)));
	return len;
}

}
}



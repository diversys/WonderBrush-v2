const int32 kImageWidth = 13;
const int32 kImageHeight = 22;
const color_space kColorSpace = B_RGBA32;

const unsigned char kOpenEnabledBits [] = {
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x98,0x98,0x98,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xf9,0xf9,0xf9,0xff,0xef,0xef,0xef,0xff,
	0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xdf,0xdf,0xdf,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xef,0xef,0xef,0xff,0x9f,0x9f,0x9f,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0xc3,0xc3,0xc3,0xff,
	0xe7,0xe7,0xe7,0xff,0xc3,0xc3,0xc3,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xb6,0xb6,0xb6,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xc3,0xc3,0xc3,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,
	0xc3,0xc3,0xc3,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,
	0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0xca,0xca,0xca,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,
	0xca,0xca,0xca,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,
	0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,
	0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0x81,0x81,0x81,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,
	0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,
	0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0x81,0x81,0x81,0xff,0x00,0x00,0x00,0xff,0x81,0x81,0x81,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0x00,0x00,0x00,0xff,
	0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,
	0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff
};

const unsigned char kClosedEnabledBits [] = {
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,
	0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xdf,0xdf,0xff,
	0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xf9,0xf9,0xf9,0xff,0xef,0xef,0xef,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xc3,0xc3,0xc3,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xef,0xef,0xef,0xff,0x9f,0x9f,0x9f,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x85,0x85,0x85,0xff,0xb6,0xb6,0xb6,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,
	0x98,0x98,0x98,0xff,0xe7,0xe7,0xe7,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,
	0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0xca,0xca,0xca,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,
	0xca,0xca,0xca,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,
	0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,
	0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0x81,0x81,0x81,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,
	0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xaf,0xaf,0xaf,0xff,0x00,0x00,0x00,0xff,0xaf,0xaf,0xaf,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,
	0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0x81,0x81,0x81,0xff,0x00,0x00,0x00,0xff,0x81,0x81,0x81,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0x00,0x00,0x00,0xff,
	0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xca,0xca,0xca,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe7,0xe7,0xe7,0xff,0xe7,0xe7,0xe7,0xff,0xb8,0xb8,0xb8,0xff,0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0xff,0xff,0xff,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,0xb8,0xb8,0xb8,0xff,
	0x60,0x60,0x60,0xff,0x98,0x98,0x98,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff,0x60,0x60,0x60,0xff
};

const unsigned char kClosedDisabledBits [] = {
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,
	0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xd7,0xd7,0xd7,0xff,
	0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xe3,0xe3,0xe3,0xff,0xde,0xde,0xde,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xcb,0xcb,0xcb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xde,0xde,0xde,0xff,0xbc,0xbc,0xbc,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xb1,0xb1,0xb1,0xff,0xc6,0xc6,0xc6,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,
	0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,
	0xe5,0xe5,0xe5,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,
	0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0xce,0xce,0xce,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,
	0xce,0xce,0xce,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0x78,0x78,0x78,0xff,0x78,0x78,0x78,0xff,
	0x78,0x78,0x78,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,
	0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xaf,0xaf,0xaf,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,
	0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,
	0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xaf,0xaf,0xaf,0xff,0x78,0x78,0x78,0xff,0xaf,0xaf,0xaf,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0x78,0x78,0x78,0xff,
	0x78,0x78,0x78,0xff,0x78,0x78,0x78,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,
	0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,
	0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff
};

const unsigned char kOpenDisabledBits [] = {
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xb9,0xb9,0xb9,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xe3,0xe3,0xe3,0xff,0xde,0xde,0xde,0xff,
	0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xd7,0xd7,0xd7,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xde,0xde,0xde,0xff,0xbc,0xbc,0xbc,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xcb,0xcb,0xcb,0xff,
	0xdb,0xdb,0xdb,0xff,0xcb,0xcb,0xcb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xc6,0xc6,0xc6,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,
	0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xcb,0xcb,0xcb,0xff,0xa1,0xa1,0xa1,0xff,0xd8,0xd8,0xd8,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,
	0xcb,0xcb,0xcb,0xff,0xdb,0xdb,0xdb,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,
	0xe5,0xe5,0xe5,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,
	0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0xce,0xce,0xce,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,
	0xce,0xce,0xce,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0x78,0x78,0x78,0xff,0x78,0x78,0x78,0xff,
	0x78,0x78,0x78,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,
	0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xaf,0xaf,0xaf,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,
	0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc3,0xc3,0xc3,0xff,0x78,0x78,0x78,0xff,0xc3,0xc3,0xc3,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,
	0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xaf,0xaf,0xaf,0xff,0x78,0x78,0x78,0xff,0xaf,0xaf,0xaf,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0x78,0x78,0x78,0xff,
	0x78,0x78,0x78,0xff,0x78,0x78,0x78,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xce,0xce,0xce,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,0xe5,0xe5,0xe5,0xff,
	0xdb,0xdb,0xdb,0xff,0xdb,0xdb,0xdb,0xff,0xc7,0xc7,0xc7,0xff,0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xe5,0xe5,0xe5,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,0xc7,0xc7,0xc7,0xff,
	0xa1,0xa1,0xa1,0xff,0xb9,0xb9,0xb9,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff,0xa1,0xa1,0xa1,0xff
};

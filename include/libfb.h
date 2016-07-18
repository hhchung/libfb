/*
	libfb.h
*/

#include <stddef.h>

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED		0xFF0000
#define WHITE	0xFFFFFF
#define BLACK	0x000000

#if 0
/* colors 8bpp */
#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED		4
#define MAGENTA		5
#define BROWN		6
#define WHITE		7		
#define GRAY		8
#define	LIGHT_BLUE	9 
#define	LIGHT_GREEN	10
#define LIGHT_CYAN	11
#define LIGHT_RED	12
#define	LIGHT_MAGENTA	13 
#define YELLOW		14
#define LIGHT_WHITE	15
#endif

typedef unsigned char byte;

typedef struct{
	int x;
	int y;
} Point;

typedef int Color;

typedef struct{
	int width;
	int height;
	int bpp;
	char *data;
} Image;

struct{
	char id[18];
	int width;
	int height;
	int bpp;
	void (*init)();
	void (*memset)(void *, unsigned int, size_t);
	void (*fillscr)(Color);
	void (*fillbox)(int, int, int, int, Color);
	void (*drawline)(Point, Point, int, Color);
	void (*drawpolygon)(Point *, int, Color);
	void (*drawsquare)(Point, int, int, int, Color);
	void (*fillsquare)(Point, int, int, Color);
	Image* (*loadPNG)(int);
	int (*drawimage)(Image *, Point);
	void (*setpixel)(int offset, Color);
    void (*putpixel)(int, int, Color);
	void (*draw_char)(char, Color);
	void (*refresh)();
} lfb;

void lfb_init();
extern byte *src;
// Usually in a header file, following information are included 
// 1. function declarations
// 2. constant definitions
// 3. conditional compilation

//constant definitions
#define ESC 0x1B
#define UNICODE
#define HEART "\u2665"
#define BAR "\u2590"
#define DEBUG //for conditional compilation

//#define BLACK 30, instead of using that, it's better to use enumeration
enum FG{BLACK=30, RED=31, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define bg(c) (c+10) // Macro definition => bg(c) = c+10

typedef struct{
	int row;
	int col;
}Position;

// function declarations
void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int,int);
void resetcolors(void);
void gotoXY(int,int);
void drawbar(int,int);
void drawrect(int, int, int, int);
Position getscreensize(void);

/*The file contains functions to manipulate screens, such as set foreground
printf("%c[%d; %dH", ESC, row, col);color, background color, classscreen, restore defualt settings and so on
To enable screen manipulations, we need to use VT100 escape sequences
Read at this link: http://www.termsys.demon.co.uk/vtansi.htm
*/
	
#include <stdio.h>
#include "screen.h"
//Function definitions
void setfgcolor(int fg){
	printf("%c[1;%dm",0x1B,fg);
}

void setbgcolor(int bg){
	printf("%c[1;%dm",ESC,bg);
}

void setcolors(int fg, int bg){
	setfgcolor(fg);
	setbgcolor(bg);
}

void clearscreen(void){
	printf("%c[2J",27);//0x1b and 27 is hex and ascii value of ESC 
}

void resetcolors(){
	printf("%c[0m", ESC);
}

void gotoXY(int row,int col){
	printf("%c[%d;%dH", ESC, row, col);	
}

void drawbar(int col, int height){
	for(int i=1; i<=height;i++){
		gotoXY(40-i,col);
#ifdef UNICODE
	printf("%s",BAR);
#else
	printf("%c",'#');
#endif		
	}
}

void drawrect(int row, int col, int height, int width){
	int i,j;
	for(i=row;i<row+height;i++){
		for(j=col; j<col+width; j++){
			gotoXY(i,j);
#ifdef UNICODE
			printf("%s", HEART);
#else
			printf("%c","#");
#endif
		}
		printf("\n");
	}
}

Position getscreensize(void){
	//In this function, use terminal query function to query cursor pos
	//The terminal should return a string back to the program
	//If a query string "ESC[6n" is issued to the terminal
	Position p;
	int r,c;				 //for decoding the report string
	char re[100] = "\0";	//empty string to get report
	gotoXY(999,999);		//force the cursor to the bottom right corner
	printf("%c[6n",ESC);	//send the query string for  cursor position
	scanf("%s",re);			//get report from the terminal
#ifdef DEBUG
	printf("%s",re);	
#endif
	//We will decode the returned string
#include <string.h>
	if(strlen(re)>0){	//in this case we will get a cursor position report
		char dum;		//dummy char to consume those symbols
		sscanf(re,"%c%c%d%c%d%c",&dum,&dum,&r,&dum,&c,&dum);
		p.row=r;
		p.col=c;
	}else{
		p.row=0;
		p.col=0;
	}
	return p;
}

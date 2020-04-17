// This file will be used to test functions in screen.c
#include <unistd.h>
#include <stdio.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
/*
	Position cur = getscreensize();
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900318", cur.row, cur.col);
	sendpost(URL, postdata);
	printf("Screen size: row = %d, col = %d\n",cur.row,cur.col);
	printf("Today we will make some animations. Press any key to continue\n");
	getchar(); //Wait for the user to press any key
*/
	int ff,bb;
	for(int i=0;i<=25;i++){
		ff = (i+1)%8+30;
		bb = (i+2)%8+BLACK;
		//setcolors(ff,bg(bb));
		clearscreen();
		setcolors(31,40);
		drawrect(i+1,i*1.6+1,2,4);
		gotoXY(25-i+1,i*1.6+1);
		setcolors(32,40);
		printf("HELLO\n");
		usleep(250000);//delay
	}
	for(int i=1;i<=25;i++){
        ff = (i+1)%8+30;
        bb = (i+2)%8+BLACK;
        //setcolors(ff,bg(bb));
        clearscreen();
		setcolors(31,40);
        drawrect(25-i+1, 40+i*1.6+1, 2, 4);
        gotoXY(i+1,40+i*1.6+1);
        setcolors(32,40);
        printf("HELLO\n");
    	usleep(250000);//delay
    }
	resetcolors();
	clearscreen();
	gotoXY(1,1);
    FILE *fp = fopen("test.wav","r"); //open the wav file in read-only mode
    WAVheader h = readwavhdr(fp);
    fclose(fp);
    displaywavhdr(h);
	printf("Color is set back to default\n");
/*
	clearscreen();
	setfgcolor(MAGENTA);
	gotoXY(14,35);
	printf("HELLO, WORLD!\n");
	getchar(); //Wait for the user to press any key
	drawbar(30,30);
	drawbar(52,30);
	getchar(); //After draing bars, wait for the user to press any key
	resetcolors(); 
	printf("Text is displayed in default color.\n");
*/
}


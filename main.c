// This file will be used to test functions in screen.c
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	clearscreen();
	Position p = getscreensize();
	if(p.col < BARS){
		printf("The screen size is not wide enough to display %d bars\n",BAR);
		return 1;
	}
	// use wget command to fetch a wav file from a URL
	gotoXY(1,1);
    FILE *fp = fopen("test.wav","r"); //open the wav file in read-only mode
    WAVheader h = readwavhdr(fp);
    displaywavhdr(h);
	getchar();
	clearscreen();
	wavdata(h,fp);
    fclose(fp);
	getchar();
}


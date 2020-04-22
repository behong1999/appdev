// This file will be used to test functions in screen.c
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	Position p = getscreensize();
	getchar();
	//Check if the screensize is wide enough to continue the program
	if(p.col < BARS){
		printf("The screen size is not wide enough to display %d bars\n",BARS);
		return 1;
	}
	// use wget command to fetch a wav file from a URL
    FILE *fp = fopen("test.wav","r"); //open the wav file in read-only mode
    WAVheader h = readwavhdr(fp);
    displaywavhdr(h);
	clearscreen();
	wavdata(h,fp);
    fclose(fp);
	gotoXY(p.row-2,1);
	printf("Press Enter To Continue...");
	getchar();
	resetcolors();
}


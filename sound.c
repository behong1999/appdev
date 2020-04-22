#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

//function definitions
WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h){
	for(int i=0; i<4; i++)
		printf("%c",h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n",h.chunkSize);
	printf("Sample rate: %d\n",h.sampleRate);
	printf("Bits per sample: %d\n",h.bitsPerSample);
	//Calculate duration
	double duration;
	duration = (double)h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n",duration);	
}

void wavdata(WAVheader h, FILE *fp){
	// For sample rate 16000sps, we need to read 2000 samples to calculate 
	// a "Fast" decibel value. A decibel value is always calculated by RMS
	// (ROOT MEAN SQUARE) formula 
	short samples[SIZE];
	char postData[100];
	double max = 0;
	int peaks = 0, check = 0;
	for(int i=0; i<BARS; i++){ // to read 5-sec wav file, we have 40 data
		fread(samples,sizeof(samples),1,fp);
		double sum = 0.0;
		for(int k=0; k<SIZE; k++){ // sum the squares of all data 
			sum += samples[k]*samples[k];
		}
		//double dB = sqrt(sum/2000);
		double dB = 20*log10(sqrt(sum/SIZE));
		
#ifdef SDEBUG
	printf("dB[%d] = %f\n", i, dB);
#else 
	if(dB>70){
		//check maximum dB value
		if(dB > max){
			max = dB;
		}
		//check peak
		setfgcolor(RED);
		if(check == 0)
			peaks++; check = 1;
	} else {
		resetcolors();
		if(check==1) check = 0;
	}
	drawbar(i+1,(int)dB/3);
	gotoXY(1,1);
	setfgcolor(CYAN);
	printf("Sample rate: %d\n",SAMPLERATE);
	gotoXY(1,75);
	setfgcolor(MAGENTA);
	printf("Duration: %.2f\n", (double)h.subchunk2Size/h.byteRate);
	gotoXY(1,150);
	setfgcolor(YELLOW);
	printf("Peaks: %d\n",peaks);
#endif
	}
	//String formatted and send data to a PHP file via URL to store data
	sprintf(postData, "peaks=%d&max=%.2f\n", peaks, max);
	sendpost(URL,postData); 
}

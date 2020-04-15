#include <stdio.h>      //for printf(), scanf() functions
#include <stdlib.h>     //for rand(), srand() functions
#include <time.h>
#include "screen.h"

void clearscreen(void);
void setfgcolor(int fg);
int main(void){
        printf("We will generate a number of random numbers\n");
        printf("Press any key ro continue...\n");
        getchar();
        clearscreen();
        srand(time(NULL));
        for (int i=0;i<100 ;i++){
                int n=rand()%80;
        if(n==8 || n==14){
                printf("%s",BAR);
        }
        else{
                if (n%2==0){
                        setfgcolor(YELLOW);
                        printf("%d ",n);
                }
                else if (n%2!=0){
                        setfgcolor(35);
                        printf("%d",n);

                }
        }
        }
        return 0;
}

void clearscreen(void){
        printf("%c[2J", ESC);
}

void setfgcolor(int fg){
        printf("%c[1;%dm",ESC,fg);
}

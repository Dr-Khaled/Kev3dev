//my c library to deal with sensors and motors with ev3dev
//it needs to be compile under linux using arm-linux-gnueabi-gcc compiler
//it could be download using the following command
//sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi

#include <stdio.h>
#include <stdlib.h>
#include "kev3dev.h"

int writeVToFile(char* file, int value){
    FILE* fp;
    if((fp = fopen(file, "r+")) == NULL) return(0);
    fprintf(fp,"%d",value);
    fclose(fp);
    return 1;

}
int writeSToFile(char* file, char* str){
    FILE* fp;
    if((fp = fopen(file, "r+")) == NULL) return(0);
    fprintf(fp,"%s",str);
    fclose(fp);
    return 1;

}
int readVFromFile(char* file, int* value){
    FILE* fp;
    if((fp = fopen(file, "r+")) == NULL) return(0);
    fscanf(fp,"%d",value);
    fclose(fp);
    return 1;

}
int readSFromFile(char* file, char* value){
    FILE* fp;
    if((fp = fopen(file, "r+")) == NULL) return(0);
    fscanf(fp,"%s",value);
    fclose(fp);
    return 1;

}



char greenLeftFile[] = "/sys/class/leds/led0:green:brick-status/brightness";
char redLeftFile[] = "/sys/class/leds/led0:red:brick-status/brightness";
char greenRightFile[] = "/sys/class/leds/led1:green:brick-status/brightness";
char redRightFile[] = "/sys/class/leds/led1:red:brick-status/brightness";

void setLeds(int greenPer, int redPer, char side){
    int num, gp, rp;
    FILE *glfp;
    FILE *rlfp;

    FILE *grfp;
    FILE *rrfp;

    
    if(side == 'l' || side == 'b'){

        if ((glfp = fopen(greenLeftFile, "r+")) == NULL){
            printf("error open left green led brightness");
            exit(1);
        }

        if ((rlfp = fopen(redLeftFile, "r+")) == NULL){
          printf("error open left red led brightness");
         exit(1);
        }


        gp = (int)(255 * ((double) greenPer / 100));
        //gp = greenPer; 
        rp = (int)(255 * ((double) redPer / 100));
        //rp = redPer;

        fprintf(glfp, "%d", gp);

        fprintf(rlfp, "%d", rp);

        fclose(glfp);
        fclose(rlfp);
    }

    if(side == 'r' || side == 'b'){

        if ((grfp = fopen(greenRightFile, "r+")) == NULL){
            printf("error open right green led brightness");
            exit(1);
        }

        if ((rrfp = fopen(redRightFile, "r+")) == NULL){
          printf("error open right red led brightness");
         exit(1);
        }

        gp = (int)(255 * ((double) greenPer / 100));
        //gp = greenPer; 
        rp = (int)(255 * ((double) redPer / 100));
        //rp = redPer;


       fprintf(grfp, "%d", gp);

        fprintf(rrfp, "%d", rp);

        fclose(grfp);
        fclose(rrfp);
    }


  }


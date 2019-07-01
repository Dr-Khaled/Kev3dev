
#include "klegomotor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kev3dev.h"

char motorsDir[] = "/sys/class/techo-motor/";

char motorPositon[] = "/sys/class/tacho-motor/motorx/position";
char targetPositon[] = "/sys/class/tacho-motor/motorx/position_sp";

char motorCommand[] = "/sys/class/tacho-motor/motorx/command";
char targetSpeed[] = "/sys/class/tacho-motor/motorx/speed_sp";
char motorDuty[] = "/sys/class/tacho-motor/motorx/duty_cycle_sp";

//motor commands
char direct[] = "run-direct";
char forever[] = "run-forever";
char toAPos[] = "run-to-abs-pos";
char toRPos[] = "run-to-rel-pos";
char stop[] = "stop";
char timed[] = "run-timed";
char reset[] = "reset";


void runMotor(char mt, char* command ){
   char temp[45];
   FILE* CF;
    //open command file for motor as write only 
    strcpy(temp, motorCommand);
    temp[28] = mt;
    printf("%s \n", temp );

    if ((CF = fopen(temp, "w")) == NULL){
            printf("error open command");
            exit(1);
        }

    fprintf(CF,"%s", command);
    fclose(CF);

}

void duty(char mt, int duty){
    char temp[50];

    strcpy(temp, motorDuty);
    temp[28] = mt;

    if(writeVToFile(temp, duty) == 0){
        printf("error in opening duty file \n");
        exit(1);
    }
}

void setSpeed(char mt, int speed){
    char temp[50];

    strcpy(temp, targetSpeed);
    temp[28] = mt;

    if(writeVToFile(temp, speed) == 0){
        printf("error in opening speed file \n");
        exit(1);
    }
}

void setNextPos(char mt, int pos){
    char temp[50];

    strcpy(temp, targetPositon);
    temp[28] = mt;

    if(writeVToFile(temp, pos) == 0){
        printf("error in opening position file \n");
        exit(1);
    }

}

int getCounter(char mt){
    int value = 0;
    char temp[50];

    strcpy(temp, motorPositon);
    temp[28] = mt;

    if(readVFromFile(temp, &value)== 0){
        printf("error in opining position file \n");
        exit(1);
    }

    return value;
}
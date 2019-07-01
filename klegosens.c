#include "klegosens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kev3dev.h"

char sensorDir[] = "/sys/class/lego-sensor/sensorX/";

char sensorValue[] = "/sys/class/lego-sensor/sensorX/value0";

char sensorMode[] = "/sys/class/lego-sensor/sensorX/mode";

int getSensValue(char sensor){
    int value = 0;
    char temp[50];

    strcpy(temp, sensorValue);
    temp[29] = sensor;

    if(readVFromFile(temp, &value)== 0){
        printf("error in opining position file \n");
        exit(1);
    }

    return value;
}




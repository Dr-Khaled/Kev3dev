#ifndef KLMOTOR
#define KLMOTOR

#include <stdio.h>
int writeVToFile(char* file, int value);
int writeSToFile(char* file, char* str);
int readVFromFile(char* file, int* value);
int readSFromFile(char* file, char* value);


void runMotor(char mt, char* command);  

void setSpeed(char mt, int speed);
void setNextPos(char mt, int pos);
void duty(char mt, int duty);

int getCounter(char mt);

#endif
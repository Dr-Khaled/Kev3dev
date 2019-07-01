#ifndef KEV3DEV
#define KEV3DEV
int writeVToFile(char* file, int value);
int writeSToFile(char* file, char* str);
int readVFromFile(char* file, int* value);
int readSFromFile(char* file, char* value);


void setLeds(int greenPer, int redPer, char side);
#endif

#include <stdio.h>
#include <stdlib.h>
#include "kev3dev.h"
#include "klegomotor.h"
#include <unistd.h>

int main(int argc, char *argv[]){
/*
    if(argc == 4) setLeds(atoi(argv[1]), atoi(argv[2]), *argv[3]);
    else printf("not correct number of parameters");
 */
    char radar = '0';
    runDirect(radar);
    duty(radar, 40);
int x = 1;
while(x > 0){
    printf("set your pace:");
    scanf("%d", &x);
    duty(radar,x);

}
    duty(radar, 0);

    return 0;
}
    

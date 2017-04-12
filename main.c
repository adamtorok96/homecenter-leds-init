#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

static int leds[3] = {12, 13, 14};

int main(int argc, char * args[]) {

    if( wiringPiSetupSys() == -1 )
        return 1;

    int i;
    for(i = 0; i < 3; i++) {
        softPwmCreate(leds[i], 0, 100);
        softPwmWrite(leds[i], 0);
    }

    return 0;
}
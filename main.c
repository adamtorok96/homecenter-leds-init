#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

static int leds[3] = {12, 13, 14};

int main(int argc, char * args[]) {

    if( wiringPiSetup() == -1 )
        return 1;

    int i;
    for(i = 0; i < 3; i++) {
        softPwmCreate(leds[i], 0, 100);
        softPwmWrite(leds[i], 0);
    }

    delay(50);

#define DMS 100
    while(1) {
        /*
        for(i = 50; i < 100; i++) {
            softPwmWrite(leds[0], i);
            delay(30);
        }

        for(i = 100; i >= 50; i--) {
            softPwmWrite(leds[0], i);
            delay(30);
        } */

        softPwmWrite(leds[0], 100);
        delay(DMS);
        softPwmWrite(leds[0], 0);
        delay(DMS);

        softPwmWrite(leds[1], 100);
        delay(DMS);
        softPwmWrite(leds[1], 0);
        delay(DMS);

        softPwmWrite(leds[2], 100);
        delay(DMS);
        softPwmWrite(leds[2], 0);
        delay(DMS);
    }


    return 0;
}
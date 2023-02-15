#ifndef __MAIN_H
    #define __MAIN_H
    #include <htc.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "lcd.h"
    #include "pwm.h"
    #include "isr.h"
    #include "adc.h"
    #include "timer.h"
    #define _XTAL_FREQ 4000000
    #define SW1 RB0
    #define SW2 RB1
    #define SW3 RB2
    #define SW4 RB3
    #define D1 RE0
    #define D2 RE1
    #define D3 RE2
    #define ENABLE RC0
    #define RELAY RD0
    #define BUZ RA0

    char count = 0, temp = 0;
#endif
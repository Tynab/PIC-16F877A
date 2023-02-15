#include "main.h"

void interrupt ISR(void)
{
    if (TMR0IF)
    {
        count++;
        if (count > 3)
            count = 0;
        TMR0IF = 0;
    }
}

void _ENABLE_INTERRUPTS(char name_interrupt)
{
    switch (name_interrupt)
    {
        case GLOBAL:
        {
            GIE = 1;
            break;
        }
        case TIMER0:
        {
            TMR0IE = 1;
            break;
        }
        case INT:
        {
            INTE = 1;
            break;
        }
        case RBI:
        {
            RBIE = 1;
            break;
        }
        case PEI:
        {
            PEIE = 1;
            break;
        }
        case MSSP:
        {
            SSPIE = 1;
            break;
        }
    }
}
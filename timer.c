#include "main.h"

void _InitTimer0(void)
{
    // OPTION_REG
    T0CS = 0;            // chon che do TIMER
    PSA = 0;             // dinh bo ti le cho TIMER
    PS2 = PS1 = PS0 = 0; // chon ti le 1:2
    TMR0IE = 1;          // cho phep ngat TIMER0
    GIE = 1;             // cho phep ngat toan cuc
}

void _SETUP_TIMER_0(char source_signal, char prescaler)
{
    switch (source_signal)
    {
    case INTERNAL:
    {
        T0CS = 0; // chon che do TIMER
        PSA = 0;  // dinh bo ti le cho TIMER
        break;
    }
    case EXTERNAL:
    {
        T0CS = 1; // chon che do COUNTER
        PSA = 1;  // dinh bo ti le cho COUNTER
        break;
    }
    default: // khi co dieu kien nao duoc thoa man
        break;
    }
    switch (prescaler)
    {
        case DIV2:
        {
            // chon ti le 1:2
            PS2 = 0;
            PS1 = 0;
            PS0 = 0;
            break;
        }
        case DIV4:
        {
            // chon ti le 1:4
            PS2 = 0;
            PS1 = 0;
            PS0 = 1;
            break;
        }
        case DIV8:
        {
            // chon ti le 1:8
            PS2 = 0;
            PS1 = 1;
            PS0 = 0;
            break;
        }
        case DIV16:
        {
            // chon ti le 1:16
            PS2 = 0;
            PS1 = 1;
            PS0 = 1;
            break;
        }
        case DIV32:
        {
            // chon ti le 1:32
            PS2 = 1;
            PS1 = 0;
            PS0 = 0;
            break;
        }
        case DIV64:
        {
            // chon ti le 1:64
            PS2 = 1;
            PS1 = 0;
            PS0 = 1;
            break;
        }
        case DIV128:
        {
            // chon ti le 1:128
            PS2 = 1;
            PS1 = 1;
            PS0 = 0;
            break;
        }
        case DIV256:
        {
            // chon ti le 1:256
            PS2 = 1;
            PS1 = 1;
            PS0 = 1;
            break;
        }
        default: // khi khong co dieu kien nao duoc thoa man
            break;
    }
}

void _SET_TIMER0(unsigned char value)
{
    TMR0 = value; // ghi gia tri vao thanh ghi TIMER0
}
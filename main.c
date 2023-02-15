#include "main.h"

__CONFIG(HS &WDTDIS &PWRTEN &UNPROTECT &BORDIS &LVPDIS);

char lrpwm = 0, im = 60, ir = 20, il = 30, ib = 20, irl = 20, irud = 20, ic = 20, icud = 20, i60, i, i20, i30, delay = 5, ig = 20, pp, pc, status = 1, ilv = 30;
int duty = 100, value_adc;

void _Init_LCD(void);
void _Init_IO(void);
void _Delay(char time);
void _Display_Number(char x, char y, int num);
void _Seti60(char im);
void _Seti20(char ir);
void _Seti30(char il);
void _Processing(void);
void _Main_Menu(void);
void _M_M(char i60);
void _Copyright(void);
void _ADC(void);
void _Nick(void);
void _Name(void);
void _Relay(void);
void _On_Off(char i20);
void _Day(void);
void _Buz(void);
void _Beap(void);
void _Motor(char lrpwm, int dutys);
int _Check_Limit(char x, char y, int limit);
void _Turn_Left_PWM(int duty);
void _Turn_Right_PWM(int duty);
void _Up_Down(char i20);
void _Limit(char delays);
void _Led(void);
void _L_M(char i30);
void _Run(void);
void _R_U(void);
void _R_D(void);
void _Catch(void);
void _C_U(void);
void _C_D(void);
void _Run_Up_LED(char delay);
void _Run_Down_LED(char delay);
void _Catch_Up_LED(char delay);
void _Catch_Down_LED(char delay);
void _H_L(void);
void _High_Low(char delay);
void _O_T_T(void);
void _Level(char i30);
void _EASY(void);
void _HARD(void);
void _One_Two_Three(char i30);
void _One(void);
void _Two(void);
void _Three(void);
void _Rock(char pp, char pc);
void _Paper(char pp, char pc);
void _Scissor(char pp, char pc);
void _Close(void);
void _Win(void);
void _Draw(void);
void _Check_Point(char pp, char pc);

void main(void)
{
    _Init_LCD();
    _Init_IO();
    _KhoiTao_ADC();
    _SETUP_TIMER_0(INTERNAL, DIV256);
    _SET_TIMER0(0);
    _ENABLE_INTERRUPTS(TIMER0);
    _ENABLE_INTERRUPTS(GLOBAL);
    _Processing();
MainMenu:
    _Main_Menu();
    _Seti60(im);
    _M_M(i60);
    ENABLE = 0;
    while (1)
    {
        if (SW1 == 0)
        {
            while (SW1 == 0);
            _Copyright();
            goto MainMenu;
        }
        else if (SW2 == 0)
        {
            while (SW2 == 0);
            im--;
            goto MainMenu;
        }
        else if (SW3 == 0)
        {
            while (SW3 == 0);
            im++;
            goto MainMenu;
        }
        else if (SW4 == 0)
        {
            while (SW4 == 0);
            _Seti60(im);
            if (i60 == 0)
            {
            ADCMenu:
                _ADC();
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        _Nick();
                        goto ADCMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        _Name();
                        goto ADCMenu;
                    }
                    else if (SW4 == 0)
                    {
                        while (SW4 == 0);
                        goto ADCMenu;
                    }
                }
            }
            else if (i60 == 1)
            {
            RELAYMenu:
                _Relay();
                _Seti20(ir);
                _On_Off(i20);
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        ir--;
                        _Seti20(ir);
                        if (i20 == 0)
                            RELAY = 0;
                        else
                            RELAY = 1;
                        goto RELAYMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        ir++;
                        _Seti20(ir);
                        if (i20 == 0)
                            RELAY = 0;
                        else
                            RELAY = 1;
                        goto RELAYMenu;
                    }
                    else if (SW4 == 0)
                    {
                        while (SW4 == 0);
                        _Day();
                        goto RELAYMenu;
                    }
                }
            }
            else if (i60 == 2)
            {
            BUZMenu:
                _Buz();
                _Seti20(ib);
                _On_Off(i20);
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        ib--;
                        _Seti20(ib);
                        if (i20 == 0)
                            BUZ = 0;
                        else
                            BUZ = 1;
                        goto BUZMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        ib++;
                        _Seti20(ib);
                        if (i20 == 0)
                            BUZ = 0;
                        else
                            BUZ = 1;
                        goto BUZMenu;
                    }
                    else if (SW4 == 0)
                    {
                        _Beap();
                        while (SW4 == 0)
                            BUZ = 1;
                        BUZ = 0;
                        goto BUZMenu;
                    }
                }
            }
            else if (i60 == 3)
            {
            MOTORMenu:
                _SetUpPWM1();
                _SetUpPWM2();
                ENABLE = 1;
                _Motor(lrpwm, duty);
                if (lrpwm == 1)
                    _Turn_Right_PWM(duty);
                else
                    _Turn_Left_PWM(duty);
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        duty -= 20;
                        goto MOTORMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        duty += 20;
                        goto MOTORMenu;
                    }
                    else if (SW4 == 0)
                    {
                        while (SW4 == 0);
                        if (lrpwm == 1)
                            _Turn_Left_PWM(duty);
                        else
                            _Turn_Right_PWM(duty);
                        goto MOTORMenu;
                    }
                }
            }
            else if (i60 == 4)
            {
            LEDMenu:
                _Led();
                _Seti30(il);
                _L_M(i30);
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        il--;
                        goto LEDMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        il++;
                        goto LEDMenu;
                    }
                    else if (SW4 == 0)
                    {
                        while (SW4 == 0);
                        _Seti30(il);
                        if (i30 == 0)
                        {
                        RunMenu:
                            _Run();
                            _Seti20(irl);
                            _Up_Down(i20);
                            while (1)
                            {
                                if (SW1 == 0)
                                {
                                    while (SW1 == 0);
                                    goto LEDMenu;
                                }
                                else if (SW2 == 0)
                                {
                                    while (SW2 == 0);
                                    irl--;
                                    goto RunMenu;
                                }
                                else if (SW3 == 0)
                                {
                                    while (SW3 == 0);
                                    irl++;
                                    goto RunMenu;
                                }
                                else if (SW4 == 0)
                                {
                                    while (SW4 == 0);
                                    _Seti20(irl);
                                    if (i20 == 0)
                                    {
                                    RunUp:
                                        _R_U();
                                        _Limit(delay);
                                        while (1)
                                        {
                                            if (SW1 == 0)
                                            {
                                                while (SW1 == 0);
                                                goto RunMenu;
                                            }
                                            else if (SW2 == 0)
                                            {
                                                while (SW2 == 0);
                                                delay -= 2;
                                                goto RunUp;
                                            }
                                            else if (SW3 == 0)
                                            {
                                                while (SW3 == 0);
                                                delay += 2;
                                                goto RunUp;
                                            }
                                            else if (SW4 == 0)
                                            {
                                                while (SW4 == 0)
                                                    _Run_Up_LED(delay);
                                                goto RunUp;
                                            }
                                        }
                                    }
                                    else if (i20 == 1)
                                    {
                                    RunDown:
                                        _R_D();
                                        _Limit(delay);
                                        while (1)
                                        {
                                            if (SW1 == 0)
                                            {
                                                while (SW1 == 0);
                                                goto RunMenu;
                                            }
                                            else if (SW2 == 0)
                                            {
                                                while (SW2 == 0);
                                                delay -= 2;
                                                goto RunDown;
                                            }
                                            else if (SW3 == 0)
                                            {
                                                while (SW3 == 0);
                                                delay += 2;
                                                goto RunDown;
                                            }
                                            else if (SW4 == 0)
                                            {
                                                while (SW4 == 0)
                                                    _Run_Down_LED(delay);
                                                goto RunDown;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if (i30 == 1)
                        {
                        CatchMenu:
                            _Catch();
                            _Seti20(ic);
                            _Up_Down(i20);
                            while (1)
                            {
                                if (SW1 == 0)
                                {
                                    while (SW1 == 0);
                                    goto LEDMenu;
                                }
                                else if (SW2 == 0)
                                {
                                    while (SW2 == 0);
                                    ic--;
                                    goto CatchMenu;
                                }
                                else if (SW3 == 0)
                                {
                                    while (SW3 == 0);
                                    ic++;
                                    goto CatchMenu;
                                }
                                else if (SW4 == 0)
                                {
                                    while (SW4 == 0);
                                    _Seti20(ic);
                                    if (i20 == 0)
                                    {
                                    CatchUp:
                                        _C_U();
                                        _Limit(delay);
                                        while (1)
                                        {
                                            if (SW1 == 0)
                                            {
                                                while (SW1 == 0);
                                                goto CatchMenu;
                                            }
                                            else if (SW2 == 0)
                                            {
                                                while (SW2 == 0);
                                                delay -= 2;
                                                goto CatchUp;
                                            }
                                            else if (SW3 == 0)
                                            {
                                                while (SW3 == 0);
                                                delay += 2;
                                                goto CatchUp;
                                            }
                                            else if (SW4 == 0)
                                            {
                                                while (SW4 == 0)
                                                    _Catch_Up_LED(delay);
                                                goto CatchUp;
                                            }
                                        }
                                    }
                                    else if (i20 == 1)
                                    {
                                    CatchDown:
                                        _C_D();
                                        _Limit(delay);
                                        while (1)
                                        {
                                            if (SW1 == 0)
                                            {
                                                while (SW1 == 0)
                                                    ;
                                                goto CatchMenu;
                                            }
                                            else if (SW2 == 0)
                                            {
                                                while (SW2 == 0);
                                                delay -= 2;
                                                goto CatchDown;
                                            }
                                            else if (SW3 == 0)
                                            {
                                                while (SW3 == 0);
                                                delay += 2;
                                                goto CatchDown;
                                            }
                                            else if (SW4 == 0)
                                            {
                                                while (SW4 == 0)
                                                    _Catch_Down_LED(delay);
                                                goto CatchDown;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if (i30 == 2)
                        {
                        HLMenu:
                            _H_L();
                            _Limit(delay);
                            while (1)
                            {
                                if (SW1 == 0)
                                {
                                    while (SW1 == 0);
                                    goto LEDMenu;
                                }
                                else if (SW2 == 0)
                                {
                                    while (SW2 == 0);
                                    delay -= 2;
                                    goto HLMenu;
                                }
                                else if (SW3 == 0)
                                {
                                    while (SW3 == 0);
                                    delay += 2;
                                    goto HLMenu;
                                }
                                else if (SW4 == 0)
                                {
                                    while (SW4 == 0)
                                        _High_Low(delay);
                                    goto HLMenu;
                                }
                            }
                        }
                    }
                }
            }
            else if (i60 == 5)
            {
            GameMenu:
                pp = 3;
                pc = 3;
                _O_T_T();
                _Seti20(ig);
                _Level(i20);
                while (1)
                {
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        ig--;
                        goto GameMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        ig++;
                        goto GameMenu;
                    }
                    else if (SW4 == 0)
                    {
                        while (SW4 == 0);
                        if (i20 == 0)
                        {
                            _EASY();
                        EasyMenu:
                            _Seti30(ilv);
                            _One_Two_Three(i30);
                            while (1)
                            {
                                if (SW1 == 0)
                                {
                                    while (SW1 == 0);
                                    goto GameMenu;
                                }
                                else if (SW2 == 0)
                                {
                                    while (SW2 == 0);
                                    ilv--;
                                    goto EasyMenu;
                                }
                                else if (SW3 == 0)
                                {
                                    while (SW3 == 0);
                                    ilv++;
                                    goto EasyMenu;
                                }
                                else if (SW4 == 0)
                                {
                                    while (SW4 == 0);
                                    _Check_Point(pp, pc);
                                    _Seti30(ilv);
                                    if (i30 == 0)
                                    {
                                        _One();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            case 3:
                                            {
                                                pp++;
                                                pc--;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            {
                                                pp--;
                                                pc++;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    else if (i30 == 1)
                                    {
                                        _Two();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            case 3:
                                            {
                                                pp++;
                                                pc--;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            {
                                                pp--;
                                                pc++;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    else if (i30 == 2)
                                    {
                                        _Three();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            case 3:
                                            {
                                                pp++;
                                                pc--;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            {
                                                pp--;
                                                pc++;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    if (pp == 0)
                                    {
                                        if (pc == 0)
                                        {
                                            _Draw();
                                            goto GameMenu;
                                        }
                                        else
                                        {
                                            _Close();
                                            goto GameMenu;
                                        }
                                    }
                                    else if (pc == 0)
                                    {
                                        _Win();
                                        goto GameMenu;
                                    }
                                    else
                                        goto EasyMenu;
                                }
                            }
                        }
                        else if (i20 == 1)
                        {
                            _HARD();
                        HardMenu:
                            _Seti30(ilv);
                            _One_Two_Three(i30);
                            while (1)
                            {
                                if (SW1 == 0)
                                {
                                    while (SW1 == 0);
                                    goto GameMenu;
                                }
                                else if (SW2 == 0)
                                {
                                    while (SW2 == 0);
                                    ilv--;
                                    goto HardMenu;
                                }
                                else if (SW3 == 0)
                                {
                                    while (SW3 == 0);
                                    ilv++;
                                    goto HardMenu;
                                }
                                else if (SW4 == 0)
                                {
                                    while (SW4 == 0);
                                    _Check_Point(pp, pc);
                                    _Seti30(ilv);
                                    if (i30 == 0)
                                    {
                                        _One();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            {
                                                pp++;
                                                pc--;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            case 3:
                                            {
                                                pp--;
                                                pc++;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    else if (i30 == 1)
                                    {
                                        _Two();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            {
                                                pp++;
                                                pc--;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            case 3:
                                            {
                                                pp--;
                                                pc++;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    else if (i30 == 2)
                                    {
                                        _Three();
                                        switch (count)
                                        {
                                            case 0:
                                            {
                                                pp--;
                                                pc--;
                                                _Scissor(pp, pc);
                                                break;
                                            }
                                            case 1:
                                            {
                                                pp++;
                                                pc--;
                                                _Paper(pp, pc);
                                                break;
                                            }
                                            case 2:
                                            case 3:
                                            {
                                                pp--;
                                                pc++;
                                                _Rock(pp, pc);
                                                break;
                                            }
                                        }
                                    }
                                    if (pp == 0)
                                    {
                                        if (pc == 0)
                                        {
                                            _Draw();
                                            goto GameMenu;
                                        }
                                        else
                                        {
                                            _Close();
                                            goto GameMenu;
                                        }
                                    }
                                    else if (pc == 0)
                                    {
                                        _Win();
                                        goto GameMenu;
                                    }
                                    else
                                        goto HardMenu;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void _Init_LCD(void)
{
    lcd_init();
    lcd_putc('\f');
}

void _Init_IO(void)
{
    TRISA0 = 0;
    TRISB0 = 1;
    TRISB1 = 1;
    TRISB2 = 1;
    TRISB3 = 1;
    TRISC0 = 0;
    TRISD0 = 0;
    TRISE = 0;
    ENABLE = 0;
    RBPU = 0;
    D1 = D2 = D3 = 0;
}

void _Delay(char time)
{
    char i;
    for (i = 0; i < time; i++)
        __delay_ms(100);
}

void _Display_Number(char x, char y, int num)
{
    char i;
    for (i = x;; i--)
    {
        lcd_gotoxy(i - 1, y);
        lcd_putc((num % 10) + 48);
        num /= 10;
        if (num < 1)
            break;
    }
}

void _Seti60(char im)
{
    if (im < 0)
        im += 60;
    i60 = im % 6;
}

void _Seti20(char ir)
{
    if (ir < 0)
        ir += 20;
    i20 = ir % 2;
}

void _Seti30(char il)
{
    if (il < 0)
        il += 30;
    i30 = il % 3;
}

void _Processing(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   PROCESSING   ");
    for (i = 0; i < 16; i++)
    {
        lcd_gotoxy(i, 1);
        lcd_putc('.');
        _Delay(3);
    }
}

void _Main_Menu(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   MAIN MENU    ");
}

void _M_M(char i60)
{
    lcd_gotoxy(0, 1);
    switch (i60)
    {
        case 0:
        {
            lcd_puts("<     ADC      >");
            break;
        }
        case 1:
        {
            lcd_puts("<    RELAY     >");
            break;
        }
        case 2:
        {
            lcd_puts("<    BUZZER    >");
            break;
        }
        case 3:
        {
            lcd_puts("<    MOTOR     >");
            break;
        }
        case 4:
        {
            lcd_puts("<     LED      >");
            break;
        }
        case 5:
        {
            lcd_puts("<    GAMES     >");
            break;
        }
    }
}

void _Copyright(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("  COPYRIGHT by  ");
    lcd_gotoxy(0, 1);
    lcd_puts("    YAMI AN     ");
    _Delay(10);
}

void _ADC(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      ADC       ");
    lcd_gotoxy(0, 1);
    lcd_puts("Value ADC:      ");
    value_adc = _Read_ADC(3);
    _Display_Number(16, 1, value_adc);
}

void _Nick(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    YAMI AN     ");
    lcd_gotoxy(0, 1);
    lcd_puts("    Nephilim    ");
    _Delay(10);
}

void _Name(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("  NGUYEN DANG   ");
    lcd_gotoxy(0, 1);
    lcd_puts("   TRUONG AN    ");
    _Delay(10);
}

void _Relay(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     RELAY      ");
}

void _On_Off(char i20)
{
    lcd_gotoxy(0, 1);
    switch (i20)
    {
        case 1:
        {
            lcd_puts("<      ON      >");
            break;
        }
        case 0:
        {
            lcd_puts("<     OFF      >");
            break;
        }
    }
}

void _Day(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts(" Date of Birth  ");
    lcd_gotoxy(0, 1);
    lcd_puts("   10/07/1993   ");
    _Delay(10);
}

void _Buz(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     BUZZER     ");
}

void _Beap(void)
{
    lcd_gotoxy(0, 1);
    lcd_puts("      BEAP      ");
}

void _Motor(char lrpwm, int dutys)
{
    duty = _Check_Limit(60, 240, dutys);
    lcd_gotoxy(0, 0);
    if (lrpwm == 1)
        lcd_puts("     RIGHT      ");
    else
        lcd_puts("      LEFT      ");
    lcd_gotoxy(0, 1);
    if (duty == 60 || duty == 240)
        lcd_puts("Limit:          ");
    else
        lcd_puts("Duty Cycles:    ");
    _Display_Number(16, 1, duty);
}

int _Check_Limit(char x, char y, int limit)
{
    if (limit < x)
        limit = x;
    else if (limit > y)
        limit = y;
    return limit;
}

void _Turn_Left_PWM(int duty)
{
    _SetDutyPWM1(0);
    _SetDutyPWM2(duty);
    lrpwm = 0;
}

void _Turn_Right_PWM(int duty)
{
    _SetDutyPWM1(duty);
    _SetDutyPWM2(0);
    lrpwm = 1;
}

void _Up_Down(char i20)
{
    lcd_gotoxy(0, 1);
    switch (i20)
    {
        case 0:
        {
            lcd_puts("<      UP      >");
            break;
        }
        case 1:
        {
            lcd_puts("<     DOWN     >");
            break;
        }
    }
}

void _Limit(char delays)
{
    delay = _Check_Limit(3, 9, delays);
    lcd_gotoxy(0, 1);
    if (delay == 3 || delay == 9)
        lcd_puts("Limit:          ");
    else
        lcd_puts("Delay:          ");
    _Display_Number(16, 1, delay * 100);
}

void _Led(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      LED       ");
}

void _L_M(char i30)
{
    lcd_gotoxy(0, 1);
    switch (i30)
    {
        case 0:
        {
            lcd_puts("<     RUN      >");
            break;
        }
        case 1:
        {
            lcd_puts("<    CATCH     >");
            break;
        }
        case 2:
        {
            lcd_puts("<   HIGH-LOW   >");
            break;
        }
    }
}

void _Run(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      RUN       ");
}

void _R_U(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     RUN UP     ");
}

void _R_D(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    RUN DOWN    ");
}

void _Catch(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     CATCH      ");
}

void _C_U(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    CATCH UP    ");
}

void _C_D(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   CATCH DOWN   ");
}

void _Run_Up_LED(char delay)
{
    D1 = D2 = D3 = 0;
    D1 = 1;
    _Delay(delay);
    D1 = 0;
    _Delay(delay);
    D2 = 1;
    _Delay(delay);
    D2 = 0;
    _Delay(delay);
    D3 = 1;
    _Delay(delay);
    D3 = 0;
    _Delay(delay);
}

void _Run_Down_LED(char delay)
{
    D1 = D2 = D3 = 0;
    D3 = 1;
    _Delay(delay);
    D3 = 0;
    _Delay(delay);
    D2 = 1;
    _Delay(delay);
    D2 = 0;
    _Delay(delay);
    D1 = 1;
    _Delay(delay);
    D1 = 0;
    _Delay(delay);
}

void _Catch_Up_LED(char delay)
{
    D1 = D2 = D3 = 0;
    D1 = 1;
    _Delay(delay);
    D2 = 1;
    _Delay(delay);
    D3 = 1;
    _Delay(delay);
    D1 = D2 = D3 = 0;
    _Delay(delay);
}

void _Catch_Down_LED(char delay)
{
    D1 = D2 = D3 = 0;
    D3 = 1;
    _Delay(delay);
    D2 = 1;
    _Delay(delay);
    D1 = 1;
    _Delay(delay);
    D1 = D2 = D3 = 0;
    _Delay(delay);
}

void _H_L(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    HIGH-LOW    ");
}

void _High_Low(char delay)
{
    D1 = D2 = D3 = 0;
    D1 = D2 = D3 = 1;
    _Delay(delay);
    D1 = D2 = D3 = 0;
    _Delay(delay);
}

void _O_T_T(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts(" ONE-TWO-THREE  ");
}

void _Level(char i20)
{
    lcd_gotoxy(0, 1);
    switch (i20)
    {
        case 0:
        {
            lcd_puts("<     EASY     >");
            break;
        }
        case 1:
        {
            lcd_puts("<     HARD     >");
            break;
        }
    }
}

void _EASY(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      EASY      ");
}

void _HARD(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      HARD      ");
}

void _One_Two_Three(char i30)
{
    lcd_gotoxy(0, 1);
    switch (i30)
    {
        case 0:
        {
            lcd_puts("ROCK            ");
            break;
        }
        case 1:
        {
            lcd_puts("PAPER           ");
            break;
        }
        case 2:
        {
            lcd_puts("SCISSOR         ");
            break;
        }
    }
}

void _One(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

void _Two(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

void _Three(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

void _Rock(char pp, char pc)
{
    lcd_gotoxy(12, 1);
    lcd_puts("ROCK");
    _Check_Point(pp, pc);
    _Delay(30);
}

void _Paper(char pp, char pc)
{
    lcd_gotoxy(11, 1);
    lcd_puts("PAPER");
    _Check_Point(pp, pc);
    _Delay(30);
}

void _Scissor(char pp, char pc)
{
    lcd_gotoxy(9, 1);
    lcd_puts("SCISSOR");
    _Check_Point(pp, pc);
    _Delay(30);
}

void _Close(void)
{
    for (i = 0; i < 3; i++)
    {
        lcd_putc('\f');
        lcd_gotoxy(0, 0);
        lcd_puts("------YOU-------");
        lcd_gotoxy(0, 1);
        lcd_puts("-----CLOSE------");
        BUZ = 1;
        D1 = D2 = D3 = 1;
        _Delay(3);
        BUZ = 0;
        D1 = D2 = D3 = 0;
        _Delay(3);
    }
}

void _Win(void)
{
    for (i = 0; i < 3; i++)
    {
        lcd_putc('\f');
        lcd_gotoxy(0, 0);
        lcd_puts("------YOU-------");
        lcd_gotoxy(0, 1);
        lcd_puts("------WIN-------");
        BUZ = 1;
        D1 = D2 = D3 = 1;
        _Delay(3);
        BUZ = 0;
        D1 = D2 = D3 = 0;
        _Delay(3);
    }
}

void _Draw(void)
{
    for (i = 0; i < 3; i++)
    {
        lcd_putc('\f');
        lcd_gotoxy(0, 0);
        lcd_puts("------DRAW------");
        lcd_gotoxy(0, 1);
        lcd_puts("------GAME------");
        BUZ = 1;
        D1 = D2 = D3 = 1;
        _Delay(3);
        BUZ = 0;
        D1 = D2 = D3 = 0;
        _Delay(3);
    }
}

void _Check_Point(char pp, char pc)
{
    lcd_gotoxy(0, 0);
    lcd_puts("YOU:       COM: ");
    _Display_Number(5, 0, pp);
    _Display_Number(16, 0, pc);
}
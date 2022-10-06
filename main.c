#include "main.h"

__CONFIG(HS &WDTDIS &PWRTEN &UNPROTECT &BORDIS &LVPDIS);

// Fields
char i;
char i60;
char i20;
char i30;
char pp;
char pc;
char im = 60;
char ir = 20;
char il = 30;
char ib = 20;
char irl = 20;
char irud = 20;
char ic = 20;
char icud = 20;
char ilv = 30;
char ig = 20;
char lrpwm = 0;
char delay = 5;
char status = 1;
int duty = 100;
int value_adc;

// Declares
void _Init_LCD(void);
void _Init_IO(void);
void _Delay(char time);
void _Display_Number(char x, char y, int num);
void _SetI60(char im);
void _SetI20(char ir);
void _SetI30(char il);
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

/// @brief Main.
/// @param  .
void main(void)
{
    // init
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
    _SetI60(im);
    _M_M(i60);
    ENABLE = 0;
    // run
    while (1)
    {
        // check switch
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
            _SetI60(im);
            // check menu
            if (i60 == 0)
            {
            ADCMenu:
                _ADC();
                // run adc
                while (1)
                {
                    // check switch adc
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
                _SetI20(ir);
                _On_Off(i20);
                // run replay
                while (1)
                {
                    // check switch replay
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        ir--;
                        _SetI20(ir);
                        // check state replay
                        if (i20 == 0)
                        {
                            RELAY = 0;
                        }
                        else
                        {
                            RELAY = 1;
                        }
                        goto RELAYMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        ir++;
                        _SetI20(ir);
                        // check state replay
                        if (i20 == 0)
                        {
                            RELAY = 0;
                        }
                        else
                        {
                            RELAY = 1;
                        }
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
                _SetI20(ib);
                _On_Off(i20);
                // run buzz
                while (1)
                {
                    // check switch buzz
                    if (SW1 == 0)
                    {
                        while (SW1 == 0);
                        goto MainMenu;
                    }
                    else if (SW2 == 0)
                    {
                        while (SW2 == 0);
                        ib--;
                        _SetI20(ib);
                        // check state buzz
                        if (i20 == 0)
                        {
                            BUZ = 0;
                        }
                        else
                        {
                            BUZ = 1;
                        }
                        goto BUZMenu;
                    }
                    else if (SW3 == 0)
                    {
                        while (SW3 == 0);
                        ib++;
                        _SetI20(ib);
                        // check state buzz
                        if (i20 == 0)
                        {
                            BUZ = 0;
                        }
                        else
                        {
                            BUZ = 1;
                        }
                        goto BUZMenu;
                    }
                    else if (SW4 == 0)
                    {
                        _Beap();
                        // on buzz
                        while (SW4 == 0)
                        {
                            BUZ = 1;
                        }
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
                // check turn motor
                if (lrpwm == 1)
                {
                    _Turn_Right_PWM(duty);
                }
                else
                {
                    _Turn_Left_PWM(duty);
                }
                // run motor
                while (1)
                {
                    // check switch motor
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
                        // turning motor
                        if (lrpwm == 1)
                        {
                            _Turn_Left_PWM(duty);
                        }
                        else
                        {
                            _Turn_Right_PWM(duty);
                        }
                        goto MOTORMenu;
                    }
                }
            }
            else if (i60 == 4)
            {
            LEDMenu:
                _Led();
                _SetI30(il);
                _L_M(i30);
                // run led
                while (1)
                {
                    // check switch led
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
                        _SetI30(il);
                        // menu led style
                        if (i30 == 0)
                        {
                        RunMenu:
                            _Run();
                            _SetI20(irl);
                            _Up_Down(i20);
                            // run style
                            while (1)
                            {
                                // check style
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
                                    _SetI20(irl);
                                    // check speed
                                    if (i20 == 0)
                                    {
                                    RunUp:
                                        _R_U();
                                        _Limit(delay);
                                        // run speed
                                        while (1)
                                        {
                                            // update speed
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
                                                {
                                                    _Run_Up_LED(delay);
                                                }
                                                goto RunUp;
                                            }
                                        }
                                    }
                                    else if (i20 == 1)
                                    {
                                    RunDown:
                                        _R_D();
                                        _Limit(delay);
                                        // run speed
                                        while (1)
                                        {
                                            // update speed
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
                                                {
                                                    _Run_Down_LED(delay);
                                                }
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
                            _SetI20(ic);
                            _Up_Down(i20);
                            // run style
                            while (1)
                            {
                                // check style
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
                                    _SetI20(ic);
                                    // check speed
                                    if (i20 == 0)
                                    {
                                    CatchUp:
                                        _C_U();
                                        _Limit(delay);
                                        // run speed
                                        while (1)
                                        {
                                            // update speed
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
                                                {
                                                    _Catch_Up_LED(delay);
                                                }
                                                goto CatchUp;
                                            }
                                        }
                                    }
                                    else if (i20 == 1)
                                    {
                                    CatchDown:
                                        _C_D();
                                        _Limit(delay);
                                        // run speed
                                        while (1)
                                        {
                                            // update speed
                                            if (SW1 == 0)
                                            {
                                                while (SW1 == 0);
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
                                                {
                                                    _Catch_Down_LED(delay);
                                                }
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
                            // run style
                            while (1)
                            {
                                // check style
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
                                    {
                                        _High_Low(delay);
                                    }
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
                _SetI20(ig);
                _Level(i20);
                // run game
                while (1)
                {
                    // check switch game
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
                        // menu game
                        if (i20 == 0)
                        {
                            _EASY();
                        EasyMenu:
                            _SetI30(ilv);
                            _One_Two_Three(i30);
                            // run level
                            while (1)
                            {
                                // check back
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
                                    _SetI30(ilv);
                                    // check result
                                    if (i30 == 0)
                                    {
                                        _One();
                                        // return result
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
                                        // return result
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
                                        // return result
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
                                    // compare result
                                    if (pp == 0)
                                    {
                                        // end game
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
                                    {
                                        goto EasyMenu;
                                    }
                                }
                            }
                        }
                        else if (i20 == 1)
                        {
                            _HARD();
                        HardMenu:
                            _SetI30(ilv);
                            _One_Two_Three(i30);
                            // run level
                            while (1)
                            {
                                // check back
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
                                    _SetI30(ilv);
                                    // check result
                                    if (i30 == 0)
                                    {
                                        _One();
                                        // return result
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
                                        // return result
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
                                        // return result
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
                                    // compare result
                                    if (pp == 0)
                                    {
                                        // end game
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
                                    {
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
}

/// @brief Init LCD.
/// @param  .
void _Init_LCD(void)
{
    lcd_init();
    lcd_putc('\f');
}

/// @brief Init IO.
/// @param  .
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

/// @brief Delay.
/// @param time Milisecond.
void _Delay(char time)
{
    char i;
    // step
    for (i = 0; i < time; i++)
    {
        __delay_ms(100);
    }
}

/// @brief Display number.
/// @param x X.
/// @param y Y.
/// @param num Number.
void _Display_Number(char x, char y, int num)
{
    char i;
    // put
    for (i = x;; i--)
    {
        lcd_gotoxy(i - 1, y);
        lcd_putc((num % 10) + 48);
        num /= 10;
        // break
        if (num < 1)
        {
            break;
        }
    }
}

/// @brief Set I60
/// @param im IM.
void _SetI60(char im)
{
    // compare
    if (im < 0)
    {
        im += 60;
    }
    i60 = im % 6;
}

/// @brief Set IR.
/// @param ir IR.
void _SetI20(char ir)
{
    // compare
    if (ir < 0)
    {
        ir += 20;
    }
    i20 = ir % 2;
}

/// @brief Set I30.
/// @param il IL.
void _SetI30(char il)
{
    // compare
    if (il < 0)
    {
        il += 30;
    }
    i30 = il % 3;
}

/// @brief Processing.
/// @param  .
void _Processing(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   PROCESSING   ");
    // show
    for (i = 0; i < 16; i++)
    {
        lcd_gotoxy(i, 1);
        lcd_putc('.');
        _Delay(3);
    }
}

/// @brief Main menu.
/// @param . 
void _Main_Menu(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   MAIN MENU    ");
}

/// @brief Main menu detail.
/// @param i60 I60.
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

/// @brief Copyright.
/// @param  .
void _Copyright(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("  COPYRIGHT by  ");
    lcd_gotoxy(0, 1);
    lcd_puts("    YAMI AN     ");
    _Delay(10);
}

/// @brief ADC
/// @param  .
void _ADC(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      ADC       ");
    lcd_gotoxy(0, 1);
    lcd_puts("Value ADC:      ");
    value_adc = _Read_ADC(3);
    _Display_Number(16, 1, value_adc);
}

/// @brief Nick account.
/// @param  .
void _Nick(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    YAMI AN     ");
    lcd_gotoxy(0, 1);
    lcd_puts("    Nephilim    ");
    _Delay(10);
}

/// @brief Full name.
/// @param  .
void _Name(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("  NGUYEN DANG   ");
    lcd_gotoxy(0, 1);
    lcd_puts("   TRUONG AN    ");
    _Delay(10);
}

/// @brief Replay.
/// @param  .
void _Relay(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     RELAY      ");
}

/// @brief State.
/// @param i20 I20.
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

/// @brief Birthday.
/// @param  .
void _Day(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts(" Date of Birth  ");
    lcd_gotoxy(0, 1);
    lcd_puts("   10/07/1993   ");
    _Delay(10);
}

/// @brief BUZZ
/// @param  .
void _Buz(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     BUZZER     ");
}

/// @brief Beap.
/// @param  .
void _Beap(void)
{
    lcd_gotoxy(0, 1);
    lcd_puts("      BEAP      ");
}

/// @brief Motor
/// @param lrpwm Turn.
/// @param dutys Duty.
void _Motor(char lrpwm, int dutys)
{
    duty = _Check_Limit(60, 240, dutys);
    lcd_gotoxy(0, 0);
    if (lrpwm == 1)
    {
        lcd_puts("     RIGHT      ");
    }
    else
    {
        lcd_puts("      LEFT      ");
    }
    lcd_gotoxy(0, 1);
    if (duty == 60 || duty == 240)
    {
        lcd_puts("Limit:          ");
    }
    else
    {
        lcd_puts("Duty Cycles:    ");
    }
    _Display_Number(16, 1, duty);
}

/// @brief Check limit.
/// @param x X.
/// @param y Y.
/// @param limit Limit.
/// @return Valid value.
int _Check_Limit(char x, char y, int limit)
{
    if (limit < x)
    {
        limit = x;
    }
    else if (limit > y)
    {
        limit = y;
    }
    return limit;
}

/// @brief Turn left PWM.
/// @param duty Duty.
void _Turn_Left_PWM(int duty)
{
    _SetDutyPWM1(0);
    _SetDutyPWM2(duty);
    lrpwm = 0;
}

/// @brief Turn right PWM.
/// @param duty Duty.
void _Turn_Right_PWM(int duty)
{
    _SetDutyPWM1(duty);
    _SetDutyPWM2(0);
    lrpwm = 1;
}

/// @brief Up down.
/// @param i20 I20.
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

/// @brief Limit.
/// @param delays Delay.
void _Limit(char delays)
{
    delay = _Check_Limit(3, 9, delays);
    lcd_gotoxy(0, 1);
    if (delay == 3 || delay == 9)
    {
        lcd_puts("Limit:          ");
    }
    else
    {
        lcd_puts("Delay:          ");
    }
    _Display_Number(16, 1, delay * 100);
}

/// @brief Led.
/// @param  .
void _Led(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      LED       ");
}

/// @brief Led menu.
/// @param i30 I30.
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

/// @brief Run.
/// @param  .
void _Run(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      RUN       ");
}

/// @brief Run up.
/// @param  .
void _R_U(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     RUN UP     ");
}

/// @brief Run down.
/// @param  .
void _R_D(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    RUN DOWN    ");
}

/// @brief Catch.
/// @param  .
void _Catch(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("     CATCH      ");
}

/// @brief Catch up.
/// @param  .
void _C_U(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    CATCH UP    ");
}

/// @brief Catch down.
/// @param  .
void _C_D(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("   CATCH DOWN   ");
}

/// @brief Run up led.
/// @param delay Delay.
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

/// @brief Run down led.
/// @param delay Delay.
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

/// @brief Catch up led.
/// @param delay Delay.
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

/// @brief Catch down led.
/// @param delay Delay.
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

/// @brief High low.
/// @param  .
void _H_L(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("    HIGH-LOW    ");
}

/// @brief High low run.
/// @param delay Delay.
void _High_Low(char delay)
{
    D1 = D2 = D3 = 0;
    D1 = D2 = D3 = 1;
    _Delay(delay);
    D1 = D2 = D3 = 0;
    _Delay(delay);
}

/// @brief One Two Three.
/// @param  .
void _O_T_T(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts(" ONE-TWO-THREE  ");
}

/// @brief Level
/// @param i20 I20.
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

/// @brief Easy.
/// @param  .
void _EASY(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      EASY      ");
}

/// @brief Hard.
/// @param  .
void _HARD(void)
{
    lcd_gotoxy(0, 0);
    lcd_puts("      HARD      ");
}

/// @brief Selection game.
/// @param i30 I30.
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

/// @brief Selected 1.
/// @param  .
void _One(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

/// @brief Selected 2.
/// @param  .
void _Two(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

/// @brief Selected 3.
/// @param  .
void _Three(void)
{
    for (i = 3; i > 0; i--)
    {
        _Display_Number(14, 1, i);
        _Catch_Down_LED(3);
    }
}

/// @brief Rock.
/// @param pp Player.
/// @param pc PC.
void _Rock(char pp, char pc)
{
    lcd_gotoxy(12, 1);
    lcd_puts("ROCK");
    _Check_Point(pp, pc);
    _Delay(30);
}

/// @brief Paper.
/// @param pp Player.
/// @param pc PC.
void _Paper(char pp, char pc)
{
    lcd_gotoxy(11, 1);
    lcd_puts("PAPER");
    _Check_Point(pp, pc);
    _Delay(30);
}

/// @brief Scissor.
/// @param pp Player.
/// @param pc PC.
void _Scissor(char pp, char pc)
{
    lcd_gotoxy(9, 1);
    lcd_puts("SCISSOR");
    _Check_Point(pp, pc);
    _Delay(30);
}

/// @brief Close.
/// @param  .
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

/// @brief Win.
/// @param  .
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

/// @brief Draw.
/// @param  .
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

/// @brief Check point.
/// @param pp Player.
/// @param pc PC.
void _Check_Point(char pp, char pc)
{
    lcd_gotoxy(0, 0);
    lcd_puts("YOU:       COM: ");
    _Display_Number(5, 0, pp);
    _Display_Number(16, 0, pc);
}
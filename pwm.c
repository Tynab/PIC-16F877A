#include "main.h"

/// @brief Set duty PWM1.
/// @param DutyCycle Duty cycle.
void _SetDutyPWM1(unsigned int DutyCycle)
{
    PR2 = 99;
    CCPR1L = DutyCycle;
    CCP1X = T2CKPS1;
    CCP1Y = T2CKPS0;
}

/// @brief Setup PWM1.
/// @param  .
void _SetUpPWM1(void)
{
    TRISC2 = 0;
    // cau hinh cho CCP1 o che do PWM
    CCP1M3 = 1;
    CCP1M2 = 1;
    CCP1M1 = 0;
    CCP1M0 = 0;
    TOUTPS3 = 0;
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;
    TMR2ON = 0;
    T2CKPS1 = 0;
    T2CKPS0 = 0;
    _SetDutyPWM1(0);
    TMR2ON = 1;
}

/// @brief Set duty PWM2.
/// @param DutyCycle Duty cycle.
void _SetDutyPWM2(unsigned int DutyCycle)
{
    PR2 = 99;
    CCPR2L = DutyCycle;
    CCP2X = T2CKPS1;
    CCP2Y = T2CKPS0;
}

/// @brief Setup PWM2.
/// @param  .
void _SetUpPWM2(void)
{
    TRISC1 = 0;
    // cau hinh cho CCP2 o che do PWM
    CCP2M3 = 1;
    CCP2M2 = 1;
    CCP2M1 = 0;
    CCP2M0 = 0;
    TOUTPS3 = 0;
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;
    TMR2ON = 0;
    T2CKPS1 = 0;
    T2CKPS0 = 0;
    _SetDutyPWM2(0);
    TMR2ON = 1;
}

/*
    Ap dung cong thuc chu ky PWM ta co:
    T(pwm)=[PR2+1]*4*(Tosc)*(TMR2 Prescale Value)=[PR2+1]*4*(1/Fosc)*(TMR2 Prescale Value)
    hay T(pwm)=[99+1]*4*(1/4)*1=100*10^(-6)=10^(-4)=10khz
    vay tan so de dieu khien dong co la 10(kHz)
*/
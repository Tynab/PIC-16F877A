#include "main.h"

/// @brief Init ADC.
/// @param  .
void _KhoiTao_ADC(void)
{
    _ThietLapKenh_ADC(AN4_AN3_AN2_AN1_AN0);
    ADFM = 1;   // dinh dang 10 bit ket qua chuyen doi AD canh phai -> LSB
    ADCON0 = 0; // khoi dong thanh ghi ADCON0
    ADCS0 = 1;  // chon xung chuyen doi AD tu mach RC trong chip
    ADCS1 = 1;
}

/// @brief Read ADC.
/// @param kenh Channel.
/// @return Result.
unsigned int _Read_ADC(char kenh)
{
    _ChonKenh(kenh);
    __delay_us(5); // cho ADC thuc hien lay mau
    GODONE = 1; // bat dau thuc hien chuyen doi AD
    while (GODONE); // cho ADC thuc hien chuyen doi xong
    // tra ve ket qua ADC sau khi chuyen doi xong
    return (((unsigned int)ADRESH) << 8) | ADRESL; // ghep byte thap va byte cao cua gia tri ADC
}

/// @brief Selection channel.
/// @param kenh Channel.
void _ChonKenh(char kenh)
{
    switch (kenh)
    {
        case 0:
        {
            CHS0 = 0; // chon kenh chuyen doi AD la AN0;
            CHS1 = 0;
            CHS2 = 0;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 1:
        {
            CHS0 = 1; // chon kenh chuyen doi AD la AN1;
            CHS1 = 0;
            CHS2 = 0;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 2:
        {
            CHS0 = 0; // chon kenh chuyen doi AD la AN2;
            CHS1 = 1;
            CHS2 = 0;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 3:
        {
            CHS0 = 1; // chon kenh chuyen doi AD la AN3;
            CHS1 = 1;
            CHS2 = 0;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 4:
        {
            CHS0 = 0; // chon kenh chuyen doi AD la AN4;
            CHS1 = 0;
            CHS2 = 1;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 5:
        {
            CHS0 = 1; // chon kenh chuyen doi AD la AN5;
            CHS1 = 0;
            CHS2 = 1;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 6:
        {
            CHS0 = 0; // chon kenh chuyen doi AD la AN6;
            CHS1 = 1;
            CHS2 = 1;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        case 7:
        {
            CHS0 = 1; // chon kenh chuyen doi AD la AN7;
            CHS1 = 1;
            CHS2 = 1;
            ADON = 1; // cho phep ADC hoat dong
            break;
        }
        default:
        {
            break;
        }
    }
}

/// @brief Config channel.
/// @param config Config.
void _ThietLapKenh_ADC(char config)
{
    switch (config)
    {
        case All_Analog:
        {
            PCFG3 = 0;
            PCFG2 = 0;
            PCFG1 = 0;
            PCFG0 = 0;
            break;
        }
        case All_Analog_Vref_AN3:
        {
            PCFG3 = 0;
            PCFG2 = 0;
            PCFG1 = 0;
            PCFG0 = 1;
            break;
        }
        case AN4_AN3_AN2_AN1_AN0:
        {
            PCFG3 = 0;
            PCFG2 = 0;
            PCFG1 = 1;
            PCFG0 = 0;
            break;
        }
        case AN4_AN2_AN1_AN0_Vref_AN3:
        {
            PCFG3 = 0;
            PCFG2 = 0;
            PCFG1 = 1;
            PCFG0 = 1;
            break;
        }
        case AN3_AN2_AN1_AN0:
        {
            PCFG3 = 0;
            PCFG2 = 1;
            PCFG1 = 0;
            PCFG0 = 0;
            break;
        }
        case AN1_AN0_Vref_AN3:
        {
            PCFG3 = 0;
            PCFG2 = 1;
            PCFG1 = 0;
            PCFG0 = 1;
            break;
        }
        case No_All_Analog:
        {
            PCFG3 = 0;
            PCFG2 = 1;
            PCFG1 = 1;
            PCFG0 = 1;
            break;
        }
        case All_Analog_Vref_AN3_AN2:
        {
            PCFG3 = 1;
            PCFG2 = 0;
            PCFG1 = 0;
            PCFG0 = 0;
            break;
        }
        case AN5_AN4_AN3_AN2_AN1_AN0:
        {
            PCFG3 = 1;
            PCFG2 = 0;
            PCFG1 = 0;
            PCFG0 = 1;
            break;
        }
        case AN5_AN4_AN2_AN1_AN0_Vref_AN3:
        {
            PCFG3 = 1;
            PCFG2 = 0;
            PCFG1 = 1;
            PCFG0 = 0;
            break;
        }
        case AN5_AN4_AN1_AN0_Vref_AN3_AN2:
        {
            PCFG3 = 1;
            PCFG2 = 0;
            PCFG1 = 1;
            PCFG0 = 1;
            break;
        }
        case AN4_AN1_AN0_Vref_AN3_AN2:
        {
            PCFG3 = 1;
            PCFG2 = 1;
            PCFG1 = 0;
            PCFG0 = 0;
            break;
        }
        case AN1_AN0_Vref_AN3_AN2:
        {
            PCFG3 = 1;
            PCFG2 = 1;
            PCFG1 = 0;
            PCFG0 = 1;
            break;
        }
        case AN0:
        {
            PCFG3 = 1;
            PCFG2 = 1;
            PCFG1 = 1;
            PCFG0 = 0;
            break;
        }
        case AN0_Vref_AN3_AN2:
        {
            PCFG3 = 1;
            PCFG2 = 1;
            PCFG1 = 1;
            PCFG0 = 1;
            break;
        }
        default:
        {
            break;
        }
    }
}
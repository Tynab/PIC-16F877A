#ifndef __ADC_H
    #define __ADC_H
    // dinh nghia bien
    #define All_Analog 0
    #define All_Analog_Vref_AN3 1
    #define AN4_AN3_AN2_AN1_AN0 2
    #define AN4_AN2_AN1_AN0_Vref_AN3 3
    #define AN3_AN2_AN1_AN0 4
    #define AN1_AN0_Vref_AN3 5
    #define No_All_Analog 6
    #define All_Analog_Vref_AN3_AN2 7
    #define AN5_AN4_AN3_AN2_AN1_AN0 8
    #define AN5_AN4_AN2_AN1_AN0_Vref_AN3 9
    #define AN5_AN4_AN1_AN0_Vref_AN3_AN2 10
    #define AN4_AN1_AN0_Vref_AN3_AN2 11
    #define AN1_AN0_Vref_AN3_AN2 12
    #define AN0 13
    #define AN0_Vref_AN3_AN2 14
    void _KhoiTao_ADC(void);             // ham khoi tao khoi ADC
    unsigned int _Read_ADC(char Kenh);   // ham doc gia tri ADC
    void _ChonKenh(char Kenh);           // chon kenh lay mau
    void _ThietLapKenh_ADC(char config); // thiet lap cac kenh lay mau ADC
#endif
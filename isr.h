#ifndef __ISR_H
    // dinh ngia bien
    #define GLOBAL 0 // dinh nghia ngat toan cuc
    #define TIMER0 1 // dinh nghia ngat TIMER0
    #define INT 2    // dinh nghia ngat ngoai
    #define RBI 3    // dinh nghia ngat RB
    #define PEI 4    // dinh nghia ngat ngoai vi
    #define MSSP 5
    // khai bao cac ham chuong trinh con
    void interrupt ISR(void);                     // ham dich vu ngat
    void _ENABLE_INTERRUPTS(char name_interrupt); // ham cho ngat
#endif
# PIC 16F877A
- Control:
    - LED
    - BUZZER
    - REPLAY
    - MOTOR
    - LCD
- Create game One-Two-Three (PvC)

## IMAGE DEMO
<p align='center'>
<img src='pic/0.jpg'></img>
</p>

## VIDEO DEMO
<div align='center'>

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/qTjmA7VRKn4/0.jpg)](https://youtu.be/qTjmA7VRKn4)

</div>

## VIDEO SCHEMATIC
<div align='center'>

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/lX-LB3o_Sbc/0.jpg)](https://youtu.be/lX-LB3o_Sbc)

</div>

## CODE DEMO
```c
#ifndef __TIMER_H
	#define __TIMER_H
	// dinh nghia bien
	// source la xung noi hay xung ngoai (INTERNAL hay EXTERNAL)
	#define INTERNAL 0
	#define EXTERNAL 1
	// prescaler la thong so ti le
	#define DIV2 1
	#define DIV4 2
	#define DIV8 3
	#define DIV16 4
	#define DIV32 5
	#define DIV64 6
	#define DIV128 7
	#define DIV256 8
	// khai bao cac ham chuong trinh con
	void _InitTimer0(void); // ham cai dat TIMER0
	void _SETUP_TIMER_0(char source_signal,char prescaler); // ham cai dat gia tri ban dau cho TIMER0
	void _SET_TIMER0(unsigned char value);
#endif
```
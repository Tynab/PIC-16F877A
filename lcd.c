#include <stdlib.h>
#include <ctype.h>
#include "lcd.h" //Cau hinh ket noi va khai bao lenh dung cho LCD.

void lcd_init()
{
    // Khai bao bien.
    unsigned char i;
    // Dinh nghia ham.
    LCD_EN_TRIS = 0; // Cau hinh ngo ra cac duong dieu khien.
    LCD_RS_TRIS = 0;
    LCD_RW_TRIS = 0;
    LCD_DATA4_TRIS = 0; // Cau hinh ngo ra cho cac duong du lieu.
    LCD_DATA5_TRIS = 0;
    LCD_DATA6_TRIS = 0;
    LCD_DATA7_TRIS = 0;
    LCD_EN = 0;      // EN=0 - Disable.
    LCD_RS = 0;      // RS=0 - Command.
    LCD_RW = 0;      // RW=0 - Write.
    __delay_ms(100); // Tao thoi gian tre khi bat nguon cho LCD.
    // Reset LCD.
    lcd_put_byte(0, 0x30);
    __delay_ms(50);
    lcd_put_byte(0, 0x30);
    __delay_ms(50);
    lcd_put_byte(0, 0x32);
    __delay_ms(100); // Tao tre de reset LCD.
    __delay_ms(100);
    __delay_ms(100);
    while (lcd_busy());
    lcd_put_byte(0, FOUR_BIT & LINES_5X7); // Thiet lap loai LCD.
    while (lcd_busy());
    lcd_put_byte(0, DOFF & CURSOR_OFF & BLINK_OFF); // Tat hien thi.
    while (lcd_busy());
    lcd_put_byte(0, DON & CURSOR_OFF & BLINK_OFF); // Bat hien thi.
    while (lcd_busy());
    lcd_put_byte(0, 0x01); // Xoa hien thi va di chuyen con tro ve dau dong.
    while (lcd_busy());
    lcd_put_byte(0, SHIFT_CUR_LEFT); // Che do dich chuyen con tro.
    while (lcd_busy());
    lcd_put_byte(0, 0x01); // Xoa hien thi va di chuyen con tro ve dau dong.
    while (lcd_busy());
}

unsigned char lcd_busy()
{
    // Khai bao bien.
    unsigned char busy;
    // Dinh nghia ham.
    LCD_DATA4_TRIS = 1; // Cau hinh ngo vao cho cac duong du lieu.
    LCD_DATA5_TRIS = 1;
    LCD_DATA6_TRIS = 1;
    LCD_DATA7_TRIS = 1;
    LCD_RW = 1; // RW=1 - Read.
    LCD_RS = 0; // RS=0 - Command.
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable.
    __delay_us(20);
    busy = LCD_DATA7; // Doc gia tri co bao ban tu LCD.
    LCD_EN = 0;       // EN=0 - Disable.
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable. Tao xung truyen thong tin.
    __delay_us(20);
    LCD_EN = 0;  // EN=0 - Disable.
    return busy; // Tra ve gia tri bao LCD ban hay khong (1: Busy).
}

unsigned char lcd_get_byte(unsigned char rs)
{
    // Khai bao bien.
    BYTE_VAL b; // Bien chua gia tri doc ve tu LCD.
    // Dinh nghia ham.
    LCD_DATA4_TRIS = 1; // Cau hinh ngo vao cho cac duong du lieu.
    LCD_DATA5_TRIS = 1;
    LCD_DATA6_TRIS = 1;
    LCD_DATA7_TRIS = 1;
    LCD_RW = 1; // RW=1 - Read.
    LCD_RS = 0; // RS=0 - Command. Mac dinh la doc Command.
    if (rs)
        LCD_RS = 1; // Kiem tra yeu cau doc Data (rs=1) hay doc Command (rs=0).
    // RS=1 - Data. Neu chon lua doc Data.
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable. Doc 4 bit cao cua thong tin can doc tu LCD.
    __delay_us(20);
    b.bits.b7 = LCD_DATA7; // Doc 4 bit cao.
    b.bits.b6 = LCD_DATA6;
    b.bits.b5 = LCD_DATA5;
    b.bits.b4 = LCD_DATA4;
    LCD_EN = 0; // EN=0 - Disable.
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable. Doc 4 bit thap cua thong tin can doc tu LCD.
    __delay_us(20);
    b.bits.b3 = LCD_DATA7; // Doc 4 bit thap.
    b.bits.b2 = LCD_DATA6;
    b.bits.b1 = LCD_DATA5;
    b.bits.b0 = LCD_DATA4;
    LCD_EN = 0;   // EN=0 - Disable.
    return b.Val; // Tra ve gia tri doc duoc tu LCD (8 bit).
}

void lcd_put_byte(unsigned char rs, unsigned char b)
{
    // Khai bao bien.
    BYTE_VAL temp; // Bien luu tam thong tin.
    // Dinh nghia ham.
    LCD_DATA4_TRIS = 0; // Cau hinh ngo ra cho cac duong du lieu.
    LCD_DATA5_TRIS = 0;
    LCD_DATA6_TRIS = 0;
    LCD_DATA7_TRIS = 0;
    LCD_RS = 0; // RS=0 - Command. Mac dinh la ghi Command.
    if (rs)
        LCD_RS = 1; // Kiem tra yeu cau ghi Data (rs=1) hay ghi Command (rs=0).
    // RS=1 - Data. Neu chon lua ghi Data.
    __delay_us(20);
    LCD_RW = 0; // RW=0 - Write.
    __delay_us(20);
    LCD_EN = 0;               // EN=0 - Disable.
    temp.Val = b;             // Lay gia tri thong tin can ghi vao LCD.
    LCD_DATA4 = temp.bits.b4; // Gui 4 bit cao len bus.
    LCD_DATA5 = temp.bits.b5;
    LCD_DATA6 = temp.bits.b6;
    LCD_DATA7 = temp.bits.b7;
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable. Ghi 4 bit cao cua thong tin vao LCD.
    __delay_us(20);
    LCD_EN = 0;               // EN=0 - Disable.
    LCD_DATA4 = temp.bits.b0; // Gui 4 bit thap len bus.
    LCD_DATA5 = temp.bits.b1;
    LCD_DATA6 = temp.bits.b2;
    LCD_DATA7 = temp.bits.b3;
    __delay_us(20);
    LCD_EN = 1; // EN=1 - Enable. Ghi 4 bit thap cua thong tin vao LCD.
    __delay_us(20);
    LCD_EN = 0; // EN=0 - Disable.
}

void lcd_putc(char c)
{
    // Dinh nghia ham.
    switch (c)
    {
        case '\f': // Chuc nang xoa hien thi.
        {
            lcd_put_byte(0, 0x01); // Goi ham truyen thong tin (lenh) sang C.LCD.
            while (lcd_busy());  // Kiem tra LCD bao ban.
            break; // Lenh: Xoa hien thi tren man hinh C.LCD (0x01).
        }
        case '\n': // Chuc nang bat dau hang thu 2.
        {
            lcd_gotoxy(0, 1); // Goi ham truyen thong tin (du lieu) sang C.LCD.
            break;
        }
        case '\b': // Chuc nang lui ve 1 vi tri.
        {
            lcd_put_byte(0, 0x10); // Goi ham truyen thong tin (lenh) sang C.LCD.
            while (lcd_busy());  // Kiem tra LCD bao ban.
            break; // Lenh: Doi con tro sang trai (0x10).
        }
        default: // Hien thi tat ca ky tu mac dinh trong LCD (c: dia chi HEX cua ky tu)
        {
            lcd_put_byte(1, c); // Gui thong tin sang LCD de hien thi tai toa do da xac dinh.
            while (lcd_busy()); // Kiem tra LCD bao ban.
            break;
        }
    }
}

void putch(char c)
{
    lcd_putc(c);
}

void lcd_gotoxy(unsigned char col, unsigned char row)
{
    // Khai bao bien.
    unsigned char address;
    // Dinh nghia ham.
    if (row != 0)       // Kiem tra hang hien thi de tao dia chi hien thi hang.
        address = 0x40; // Ma dieu khien hien thi hang 2.
    else
        address = 0x00;              // Ma dieu khien hien thi hang 1.
    address += col;                  // Ket hop gia tri hang va cot de tao ra dia chi hien thi.
    lcd_put_byte(0, 0x80 | address); // Gui lenh xac dinh toa do hien thi tren LCD.
    while (lcd_busy()); // Kiem tra LCD bao ban.
}

void lcd_puts(const char *s)
{
    // Dinh nghia ham.
    while (*s)
        lcd_putc(*s++);
}
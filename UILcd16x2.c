#include <stdbool.h>
#include "InterfaceLCD.h"

// Lcd pinout settings
sbit LCD_RS at RB6_bit;
sbit LCD_EN at RB7_bit;
sbit LCD_D7 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB4_bit;
sbit LCD_D4 at RB5_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB6_bit;
sbit LCD_EN_Direction at TRISB7_bit;
sbit LCD_D7_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB5_bit;

void main() 
{
    Lcd_Init();
    config_LCD_user_interface(3, '~');
    write_first_line("testando");
    write_second_line("Clesio e Bob");
    while(true);
}
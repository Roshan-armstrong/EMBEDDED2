#include <xc.h>
#include "config.h"
#include "lcd.h"
#include "function.h"

const char name[4][5];
void main(void){
  TRISA0=1;
  TRISA1=1;
  TRISA2=1;
  TRISA3=1;
  ADCON0=0X00;
  ADCON1=0X06;
  LCD_Init(); // Initialize LCD module with I2C address = 0x4E
  LCD_Set_Cursor(1, 1);
  LCD_Write_String("IC TESTER");
  unsigned int n=5;
  const char name[7][5]={"7400","7402","7404","7408","7432","7486"};
  while(1)
  {
      if(RA0==1)
      {
          n = (n + 1) % 6;
          Write_IC();
          LCD_Write_String(name[n]);
          __delay_ms(500);
      }
      if(RA1==1)
      {
          n = (n -1+6) % 6;
          Write_IC();
          LCD_Write_String(name[n]);
          __delay_ms(500);
      }
      if(RA2==1)
      {
          Write_IC();
          LCD_Write_String(name[n]);
          Test(n);
      }
      if(RA3==1)
      {
           Write_IC();
          LCD_Write_String("Auto...");
          Auto();
      }
  }
  return;
}

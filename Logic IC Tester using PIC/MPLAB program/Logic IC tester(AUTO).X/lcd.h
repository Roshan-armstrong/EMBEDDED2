#include <xc.h>
 
#define _XTAL_FREQ 20000000
 
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISC
#define LCD_RS_D TRISC6
#define LCD_EN_D TRISC7
#define RS RC6
#define EN RC7
#define D4 RC2
#define D5 RC3
#define D6 RC4
#define D7 RC5
//==============================================
//-----[ Prototypes For All LCD Functions ]-----
 
void LCD_Init(); // Initialize The LCD For 4-Bit Interface
void LCD_Clear(); // Clear The LCD Display
void LCD_SL(); // Shift The Entire Display To The Left
void LCD_SR(); // Shift The Entire Display To The Right
 
void LCD_CMD(unsigned char); // Send Command To LCD
void LCD_DATA(unsigned char); // Send 4-Bit Data To LCD
void LCD_Set_Cursor(unsigned char, unsigned char); // Set Cursor Position
void LCD_Write_Char(char); // Write Character To LCD At Current Position
void LCD_Write_String(const char*); // Write A String To LCD
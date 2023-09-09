//Functions required to display the output in 16x2 display

#include<reg51.h>
#include<header.h>
sfr LCD_Port=0x80;	
sbit rs=P0^0;			/* Register select pin */
sbit rw=P0^1;			/* Read/Write pin */
sbit en=P0^2;	

code const unsigned char myString[6][5] = {
    {"7400"},
    {"7402"},
    {"7404"},
    {"7408"},
    {"7432"},
		{"7486"},
	};

void delay(unsigned int count)    		
{int i,j;
     for(i=0;i<count;i++){
			 for(j=0;j<1120;j++);
}}

void string(){
	LCD_Command(0x01);
	LCD_String("IC_");
	LCD_String(myString[currentP]);
}

void clear_line2()
{
	LCD_Command(0x01);
	string();
	LCD_Command(0xC0);
}

void LCD_Command (char cmnd)	/* LCD16x2 command funtion */
{
	LCD_Port =(LCD_Port & 0x0F) | (cmnd & 0xF0);/* Send upper nibble */
	rs=0;			/* Command reg. */
	rw=0;			/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(2);
	
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);/* Send lower nibble */
	en=1;			/* Enable pulse */
	delay(1);
	en=0;
	delay(5);
}

void LCD_Char (char char_data)  /* LCD data write function */
{
	LCD_Port =(LCD_Port & 0x0F) | (char_data & 0xF0);/* Send upper nibble */
	rs=1;  			/*Data reg.*/
	rw=0;  			/*Write operation*/
	en=1;  
	delay(1);
	en=0;
	delay(2);

	LCD_Port = (LCD_Port & 0x0F) | (char_data << 4);/* Send lower nibble */
	en=1;  			/* Enable pulse */
	delay(1);
	en=0;
	delay(5);

}

void LCD_String (char *str)	/* Send string to LCD function */
{int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
	}
}

void LCD_Init (void)		/* LCD Initialize function */
{
	delay(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x02);	/* 4bit mode */
	LCD_Command (0x28);	/* Initialization of 16X2 LCD in 4bit mode */
	LCD_Command (0x0C);	/* Display ON Cursor OFF */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */
	LCD_Command (0x80);	/* cursor at first line */
}
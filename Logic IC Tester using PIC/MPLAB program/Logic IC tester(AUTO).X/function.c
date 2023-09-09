#include <pic16f877a.h>
#include"config.h"
#include"lcd.h"
#include"function.h"
#include <stdio.h>
unsigned int gate[6]={1,1,1,1,1,1};
const unsigned int truth[6]={11110,11000,110,10001,10111,10110};
unsigned int i,j,k;
void Write_IC(void)
{
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("IC  ");
}
void Test(unsigned int n)
{
    if(n<=5&&n!=2)
    {
     Mode_4();
     print(n,4);
     gate_1();
    }
    if(n==2)
    {
        Mode_6();
        print(n,6);
        gate_1();
    }
}
void Auto(void)
{
    Check:
    k=0;
    Mode_4();
    for(i=0;i<4;i++)
    {
        for(j=0;j<6;j++)
        {
            if(gate[i]==truth[j])
            {
                k++;
                n=j;
            }
        }
        if(k==4)
        {
            print(n,4);
            gate_1();
        }
    }
    goto Check;
}
void print(unsigned int n,unsigned int no)   //no==no of gates
{
    int num=0;
    char charNum[3];
    LCD_Set_Cursor(2,1);
    j=0;
    for(i=0;i<no;i++)
    {
        if(truth[n]==gate[i])
        {
            num=i+1;
            sprintf(charNum, "%d", num);
            LCD_Write_String(charNum);
            j++;
        }
    }
    if(j>1) LCD_Write_String(" GATE GOOD");
    if(j==0) LCD_Write_String("IC IS BAD");
       
}
void Mode_4(void)
{
    k=0;
    TRISB0=TRISB1=TRISB3=TRISB4=TRISD3=TRISD2=TRISD5=TRISD6=0;
    TRISB2=TRISB5=TRISD1=TRISD4=1;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            RB0=RB3=RD3=RD5=(__bit)i;
            RB1=RB4=RD2=RD6=(__bit)j;
            k=(int)RB2;
            gate[0]*=10;
            gate[0]+=k;
            k=(int)RB5;
            gate[1]*=10;
            gate[1]+=k;
            k=(int)RD1;
            gate[2]*=10;
            gate[2]+=k;
            k=(int)RD4;
            gate[3]*=10;
            gate[3]+=k;
            __delay_ms(500);
        }
    }
}
void Mode_6(void)
{
    k=0;
    TRISB0=TRISB2=TRISB4=TRISD2=TRISD4=TRISD6=0;
    TRISB1=TRISB3=TRISB5=TRISD1=TRISD3=TRISD5=1;
    for(i=0;i<2;i++)
    {
        RB0=RB2=RB4=RD2=RD4=RD6=(__bit)i;
        k=(int)RB1;
        gate[0]*=10;
        gate[0]+=k;
        k=(int)RB3;
        gate[1]*=10;
        gate[1]+=k;
        k=(int)RB5;
        gate[2]*=10;
        gate[2]+=k;
        k=(int)RD1;
        gate[3]*=10;
        gate[3]+=k;
        k=(int)RD3;
        gate[4]*=10;
        gate[4]+=k;
        k=(int)RD5;
        gate[5]*=10;
        gate[5]+=k;
        __delay_ms(500);
    }
}
void gate_1(void)
{
    for(i=0;i<6;i++)
    {
        gate[i]=1;
    }
}
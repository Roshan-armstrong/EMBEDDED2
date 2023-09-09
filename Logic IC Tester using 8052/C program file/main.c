//Programmer : ROSHAN NT
//AIM : To test every single logic gate in a IC and display the output

#include<reg51.h>
#include<header.h>
sbit up=P2^4;
sbit down=P2^5;
sbit test=P2^6;
void up_fn(void);
void down_fn(void);
unsigned int currentP=0;
unsigned int stringS=6;
void main()
{
	up=1;
	down=1;
	test=1;
	LCD_Init(); 
  string();	// Increment cursor position, no shift
	gate0();
	while(1){
		sbit_0();
		if(up==0){    //only increment the ic number
			currentP=(currentP+1)%stringS;
			string();
		}
		if(down==0){   //only decrement the ic number
				clear_line2();
			currentP=(currentP-1)%stringS;
	  }
	  
  
	  if(test==0){
			switch (currentP)
      {
				case 0:
				nand_7400();
				break;
				case 1:
					nor_7402();
      		break;
				case 2:
					not_7404();
				  break;
				case 3:
					and_7408();
				  break;
				case 4:
					or_7432();
				  break;
				case 5:
					xor_7486();
				  break;
      	default:
      		break;}
      }
}
}

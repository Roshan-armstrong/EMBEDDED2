//Functions required to test the IC

#include<reg51.h>
#include<header.h>
sbit p1_0=P1^0; // input and output ports
sbit p1_1=P1^1;
sbit p1_2=P1^2;
sbit p1_3=P1^3;
sbit p1_4=P1^4;
sbit p1_5=P1^5;
sbit p1_6=P1^6;
sbit p1_7=P1^7;
sbit p2_0=P2^0;
sbit p2_1=P2^1;
sbit p2_2=P2^2;
sbit p2_3=P2^3;
unsigned char g1=0;     //gate status
unsigned char g2=0;
unsigned char g3=0;
unsigned char g4=0;
unsigned char g5=0;
unsigned char g6=0;
unsigned int i,j,k;
void sbit_0(){
	p1_0=p1_1=p1_2=p1_3=p1_4=p1_5=p1_6=p1_7=0;
	p2_0=p2_1=p2_2=p2_3=0;

}

void gate0(){
	g1=g2=g3=g4=g5=g6=0;
}

void not_7404()
	{
  gate0();
	for(i=0;i<=1;i++){
		sbit_0();
		p1_0=p1_2=p1_4=p1_7=p2_1=p2_3=i;
		p1_1=p1_3=p1_5=p1_6=p2_0=p2_2=1;
		delay(10);
		g1 += (p1_1 != p1_0);
    g2 += (p1_3 != p1_2);
    g3 += (p1_5 != p1_4);
    g4 += (p1_6 != p1_7);
    g5 += (p2_0 != p2_1);
    g6 += (p2_2 != p2_3);
	}
	output(6);
}
 void and_7408(void){
	 gate0();
	 clear_line2();
	 
	 for(i=0;i<=1;i++){
		 sbit_0();
		 p1_0=p1_3=p2_0=p2_3=i;
		 for(j=0;j<=1;j++){ 
			 p1_1=p1_4=p1_7=p2_2=j;
			 p1_2=p1_5=p1_6=p2_1=1;
			 delay(10);			 
			 if (p1_2 == (p1_0 & p1_1)) g1++;
       if (p1_5 == (p1_3 & p1_4)) g2++;
       if (p1_6 == (p2_0 & p1_7)) g3++;
       if (p2_1 == (p2_3 & p2_2)) g4++;
		 } 
			 }
output(4);
 }
 void nand_7400(){
	 gate0();
	 for(i=0;i<=1;i++){
		 for(j=0;j<=1;j++){
			 sbit_0();
			 p1_0=p1_3=p2_0=p2_3=i;
			 p1_1=p1_4=p1_7=p2_2=j;
			 p1_2=p1_5=p1_6=p2_1=1;
			 delay(10);
			 
			 if(p1_2 !=(p1_0&p1_1)){       //not equal to A&B
				 g1++;}
			 if(p1_5 !=(p1_3&p1_4)){
				 g2++;} 
			 if(p1_6 !=(p2_0&p1_7)){
				 g3++;} 
			 if(p2_1 !=(p2_3&p2_2)){
				 g4++;} 
			 }
		 }
	 output(4);
	 }
 void nor_7402(){
	 gate0();
	 for(i=0;i<=1;i++){
		 for(j=0;j<=1;j++){
			 sbit_0();
			 p1_1=p1_4=p1_7=p2_2=i;
			 p1_2=p1_5=p1_6=p2_1=j;
			 p1_0=p1_3=p2_0=p2_3=1;
			 delay(10);
			 if(p1_0 !=(p1_1|p1_2)){       //not equal to A|B
				 g1++;}
			 if(p1_3 !=(p1_5|p1_4)){
				 g2++;} 
			 if(p2_0 !=(p1_6|p1_7)){
				 g3++;} 
			 if(p2_3 !=(p2_1|p2_2)){
				 g4++;} 
			 }
		 }
	 output(4);
	 }
void or_7432(){
	gate0();
	 for(i=0;i<=1;i++){
		 for(j=0;j<=1;j++){
			 sbit_0();
			 p1_0=p1_3=p2_0=p2_3=i;
			 p1_1=p1_4=p1_7=p2_2=j;
			 p1_2=p1_5=p1_6=p2_1=1;
			 delay(10);
			 
			 if(p1_2 ==(p1_0|p1_1)){       
				 g1++;}
			 if(p1_5 ==(p1_3|p1_4)){
				 g2++;} 
			 if(p1_6 ==(p2_0|p1_7)){
				 g3++;} 
			 if(p2_1 ==(p2_3|p2_2)){
				 g4++;} 
			 }
		 }
	 output(4);
	 }

void xor_7486(){
		gate0();
	 for(i=0;i<=1;i++){
		 for(j=0;j<=1;j++){
			 sbit_0();
			 p1_0=p1_3=p2_0=p2_3=i;
			 p1_1=p1_4=p1_7=p2_2=j;
			 p1_2=p1_5=p1_6=p2_1=1;
			 delay(10);
			 
			 if(p1_2 ==(p1_0^p1_1)){      
				 g1++;}
			 if(p1_5 ==(p1_3^p1_4)){
				 g2++;} 
			 if(p1_6 ==(p2_0^p1_7)){
				 g3++;} 
			 if(p2_1 ==(p2_3^p2_2)){
				 g4++;} 
			 }
		 }
	 output(4);
	 }
	 
void output(int out_num){
	clear_line2();
	switch(out_num)
  {
		case 4:
			if(g1==4 & g2==4 & g3==4 & g4==4){
         LCD_String("1 2 3 4 GOOD");
				 break;
      }
      if(g1!=4 & g2!=4 & g3!=4 & g4!=4){
         LCD_String("IC IS BAD");
      }
			else {
		  if(g1==4) LCD_String("1 ");
	    if(g2==4) LCD_String("2 ");
	    if(g3==4) LCD_String("3 ");
	    if(g4==4) LCD_String("4 ");
		  LCD_String("GOOD");
		  }
		  break;
  	case 6:
			if(g1==2 & g2==2 & g3==2 & g4==2 & g5==2 & g6==2){
         LCD_String("1 2 3 4 5 6 GOOD");
				 break;
      }
			if(g1!=2 & g2!=2 & g3!=2 & g4!=2 & g5!=2 & g6!=2){
         LCD_String("IC IS BAD");
      }
			else{
			if(g1==2) LCD_String("1 ");
	    if(g2==2) LCD_String("2 ");
	    if(g3==2) LCD_String("3 ");
	    if(g4==2) LCD_String("4 ");
	    if(g5==2) LCD_String("5 ");
	    if(g6==2) LCD_String("6 ");
	    LCD_String("GOOD");
  		break;
			}
  	default:
  		break;
  }
}
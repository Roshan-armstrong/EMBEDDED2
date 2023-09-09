void clear_line2(void); 
void string(void);
void LCD_Init (void);
void LCD_String (char *str)	;
void LCD_Char (char char_data) ;
void LCD_Command (char cmnd);
void delay(unsigned int count);
void gate0(void);
void sbit_0(void);
void output(int out_num);
void not_7404(void);     //logic function
void and_7408(void);
void nand_7400(void);
void nor_7402(void);
void or_7432(void);
void xor_7486(void);
extern unsigned int currentP;
extern unsigned int i,j,k;
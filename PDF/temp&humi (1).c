#include<P18F4520.h>
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT+OFF
#pragma config DEBUG+OFF,LVP=OFF

void DELAY(unsigned int time);
void lcdcmd(unsigned char value);
void lcddata(unsigned char value);

#define ldata PORTD
#define rs PORTbits.RB0
#define rw PORTbits.RB1
#define en PORTbits.RB2

//program for lcd display
void main(void)
{
	int answer=0;
	int j,n;
	int k=1;
	float t;
	unsigned int i,d,a,b,c,x,y,z;
	unsigned char val;
	unsigned char value;
	unsigned char temp[10];
	TRISD=0;
	PORTD=0;
	TRISB=0;
	PORTB=0;
	TRISC=0;
	PORTC=0;

//PROGRAM FOR TEMP DISPLAY

	TRISAbits.TRISA0=1;
	ADCON0=0X01;
	ADCON1=0X3D;
	ADCON2=0X8E;

	DELAY(20);
	ADCON0bits.GO=1;
	while(ADCON0bits.DONE ==1);

	DELAY(10);
	TRISB=0x00;
	DELAY(10);
	lcdcmd(0x80);
	DELAY(10);
	lcdcmd(0x38);
	DELAY(10);
	lcdcmd(0x0C);
	DELAY(10);
	lcdcmd(0x06);
	DELAY(10);
	lcdcmd(0x81);
	DELAY(10);
	lcdcmd(0x80);
     temp[9]=(ADRESH & 0x02)>>1;
     temp[8]=(ADRESH & 0x01);
     temp[7]=(ADRESH & 0x80)>>7;
     temp[6]=(ADRESH & 0x40)>>6;
     temp[5]=(ADRESH & 0x20)>>5;
     temp[4]=(ADRESH & 0x10)>>4;
     temp[3]=(ADRESH & 0x08)>>3;
     temp[2]=(ADRESH & 0x04)>>2;
     temp[1]=(ADRESH & 0x02)>>1;
     temp[0]=(ADRESH & 0x01);
	for(d=0;d<10;d++)
	{
	 answer=answer+(temp[d]*k);
	 k=k*2;
	}
	t=answer;
	answer=t/20.46;
	z=answer%10;
	y=((answer-z)/10)%10;
	x=answer/100;



	lcddata('T');	
	lcddata('E');
	lcddata('M');
	lcddata('P');
	lcddata(' ');
	lcddata(' ');
	lcddata(':');

	lcddata(' ');
	lcddata(y+0x30);
	lcddata(z+0x30);
	lcddata(' ');
	lcddata('O');
	lcddata('C');
	DELAY(5);

//Program for humidity
	TRISbits.TRISA1=1;
	ADCON0 = 0x05;
	ADCON1 = 0x3D;
	ADCON2 = 0x0F;
	
	ADCON0bits.GO=1;	
	while(ADCON0bits.GO==1);

	n=ADRESH/20;
	lcdcmd(0xC0);
	DELAY(20)
	lcddata('H');
	lcddata('U');
	lcddata('M');
	lcddata('I');
	lcddata('D');
	lcddata('I');
	lcddata('T');
	lcddata('Y');
	DELAY(15);
	for(j=0;j<n;j++)
	lcddata(0xFF);
	DELAY(5);
	lcdcmd(0x01);
}


void lcdcmd(unsigned char value)
{
  ldata=value;
  rs=0;
  rw=0;
  en=1;
  DELAY(20)
  en=0;
}

void lcddata(unsigned char value)
{
  ldata=value;
  rs=1;
  rw=0;
  en=1;
  DELAY(20)
  en=0;
}


void DELAY(unsigned int time)
{
	int i,j;
	for(i=0;i<=time;i++)
	for(j=0;j<=50;j++);

}
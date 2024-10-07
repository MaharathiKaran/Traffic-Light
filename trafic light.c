#include<reg51.h>
unsigned int x;
sbit A1=P3^4;
sbit A2=P3^5;
sbit A3=P3^6;
sbit A4=P3^7;
sbit R1=P3^3;
sbit R2=P3^0;
sbit R3=P2^5;
sbit R4=P2^2;
sbit G1=P3^1;
sbit G2=P2^6;
sbit G3=P2^3;
sbit G4=P2^0;

void delay()
{
	TMOD=0x01;

for(x=0;x<14;x++)
{
TH0=0;
TL0=0;
TR0=1;
while(TF0==0);
TF0=0;
TR0=0;
}
}
void count()
{
	int x;
	for(x=30;x>=0;x--)
	{
		P1=x;
		delay();
	}
}
void traffic()

{		
P2=0XA4;
P3=0X02; 
count();
		
P2=0X54;
P3=0X08; 
count();
		
P2=0X0A;
P3=0X09; 
count();
	
P2=0X21;
P3=0X05; 
count();
}
void main()
{
{
	if(A1==0)
	{
	P2=0x24;
		P3=0x03;
		count();
	}
	else
	{
		traffic();
	}
}
{
	if(A2==0)
	{
	P2=0x64;
		P3=0x08;
		count();
	}
	else
	{
		traffic();
	}
}
{
	if(A3==0)
	{
		P2=0x0C;
		P3=0x09;
		count();
	}
	else
	{
		traffic();
	}
}
{
	if(A4==0)
	{
	P2=0x21;
		P3=0x09;
		count();
	}
	else
	{
		traffic();
	}
}
}
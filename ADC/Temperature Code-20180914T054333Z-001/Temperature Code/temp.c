#include<reg51.h>

sbit en=P3^6;   

sbit cs=P3^0;
sbit wr= P3^1;
sbit rd= P3^2;
sbit intr= P0^0;
char cel[]="TEMP IN CELSIUS";

void delay(unsigned int time)  
{
unsigned int i,j;
for(i=0;i<time;i++)
  for(j=0;j<5;j++);
}


void lcdcmd(unsigned char value)  
{
P1=value;
P3=0x40;
delay(50);
en=0;
delay(50);
return;
}

void display(unsigned char value)  
{
P1=value;
P3=0x60;
delay(500);
en=0;
delay(50);
return;
}

void lcdint(void)         
{
   delay(15000);
   display(0x30);
   delay(4500);
   display(0x30);
   delay(300);
   display(0x30);
   delay(650);
   lcdcmd(0x38);
   lcdcmd(0x0F);
   lcdcmd(0x01);
   lcdcmd(0x06);
   lcdcmd(0x80);
}

void main()
{
unsigned int Adcvalue,Adcvalue1,i=0;
char ch1,ch2,ch3;
P0=0x01;
P1=0x00;              
P3=0x00;             
P2=0xFF;             
lcdint();
while (1){
delay(10000);
cs=0;                 
wr=0;                 
delay(10);
wr=1;                       
rd=1;                  
while(intr==1);            
rd=0;                     
Adcvalue=P2;
i=0;
while(cel[i]!='\0'){
display(cel[i]);
i++;
}
lcdcmd(0xC7);
ch1=Adcvalue/100;
if(ch1!=0)
display(ch1+0x30);
delay(100);
Adcvalue1=Adcvalue%100;
ch2=Adcvalue1/10;
display(ch2+0x30);
ch3=Adcvalue1-(ch2*10);
display(ch3+0x30);
delay(10000);
delay(10000);
delay(10000);
lcdcmd(0x01);
}
}
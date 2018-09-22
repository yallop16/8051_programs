#include<reg51.h>
 
sbit in1=P2^0;
sbit in2=P2^1;
sbit en1=P2^2;
sbit en2=P2^3;
sbit in3=P2^4;
sbit in4=P3^5;
 
void forward();
void reverse();
 
void main()
{
 en1=1;
 en2=1;
 while(1) {
 forward();
 reverse();
 }
}
 
void forward()
{
 in1=1;
 in2=0;
}
 
void reverse()
{
 in4=1;
 in3=0;
}

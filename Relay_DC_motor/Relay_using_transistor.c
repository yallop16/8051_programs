#include<reg52.h>

sbit relay_pin = P2^0;

void Delay_ms(int);

void main()
{
  do
  {
    relay_pin = 0; //Relay ON
    Delay_ms(1000);
    relay_pin = 1; //Relay OFF
    Delay_ms(1000);
  }while(1);
}

void Delay_ms(int k)
{
  int j;
  int i;
  for(i=0;i<k;i++)
  {
   for(j=0;j<100;j++)
   {
   }
  }
}
#include<reg51.h>

sbit led=P2^0;                          // led at PORT 2 pin 0

void Delay(void);              // Delay function declaration




void main ()                        // main function

{

led=0;                                   //output PORT

while(1)                               // infinite loop

    {

led = 1;                  // LED ON

Delay();

led = 0;                  // LED OFF

Delay();
    }

}

void Delay()

{

TMOD = 0x01;           // Timer0 mode1

TH0=0xDC;              //initial value for 10ms

TL0=0x00;

TR0 = 1;               // timer0 start

while (TF0 == 0);      // check overflow condition

TR0 = 0;               // Stop Timer

TF0 = 0;               // Clear flag

}
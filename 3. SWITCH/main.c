#include <avr/io.h>
#include <util/delay.h>


void main()
{
  DDRC = 0x01;; //Makes first pin of PORTC as Output
  DDRD =0x00;//Makes first pin of PORTD as Input
  while(1) //infinite loop
  {
    if(PIND & 0x01 == 0) //If switch is pressed
    {
      PORTC=0x01;
    }
  }
}
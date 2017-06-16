#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include "adc.h"
#include "uart.h"

int pulse=0, i=0;

void main()
{
DDRD=0b11111011; //connect echo pin to PORTD pin2
adc_init();
uartinit();

_delay_ms(50);

GICR=0x40;
MCUCR=0x01;

TCCR1A=0;

int dist=0;

sei();

while(1)
{
PORTD=0x01; 	//connect to trig pin
_delay_us(15);
PORTD=0x00;

dist=pulse/58;	//correction factor

printnum(dist);	// to display in tera term
_delay_ms(100);	
}
}

ISR(INT0_vect)
{
  if(i==1)
  {
  TCCR1B=0;
  pulse=TCNT1;
  TCNT1=0;
  i=0;
  }
  
  if(i==0)
  {
  TCCR1B=0x01;
  i=1;
  }
}




#include <avr/io.h>
#include <util/delay.h>
 
void main()
{
	DDRA = 0xFF;	// Configure port A as output
	
	int ssd[]={0b00110000,0b01011011, 0b01001111,0b01100110,0b01110111,0b00111001,0b01111001,0b01110001};
	int i;
    while(1)
    {
		for(i=0;i<9;i++)
		{
			PORTA=ssd[i];
			_delay_ms(1000);
		}	
 
    }
 
}
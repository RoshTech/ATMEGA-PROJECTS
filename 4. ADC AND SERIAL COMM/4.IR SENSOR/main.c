#include<avr/io.h>
#include<util/delay.h>
#include"adc.h"
#include"uart.h"
void main()
{
uartinit();
adc_init();
while(1)
{
int x=getdata(0x00); // to get value from IR sensor
printnum(x);	// to print in tera term
printchar('\n');
_delay_ms(100);
}
}
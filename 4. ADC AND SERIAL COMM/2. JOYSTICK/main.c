#include<avr/io.h>
#include<util/delay.h>
#include"adc.h"
#include"uart.h"
void main()
{
uartinit();
adc_init();
int x,y;
while(1)
{
x=getdata(0x00); // to get vertex X
y=getdata(0x01); // to get vertex y

printnum(x);	//to print in tera term
printchar('\t');

printnum(y);	//to print in tera term
printchar('\n');
_delay_ms(100);
}
}
#include<avr/io.h>
#include<util/delay.h>

void cmd(unsigned char a)
{
PORTB=a;
PORTD=0x04;
_delay_ms(1);
PORTD=0x00;
_delay_ms(1);
}

void data(unsigned char a)
{
PORTB=a;
PORTD=0x05;
_delay_ms(1);
PORTD=0x01;
_delay_ms(1);
}

void main()
{
DDRD=0xff;
DDRB=0xff;

cmd(0x38);
cmd(0x01);
cmd(0x0c);
cmd(0x80);

char s[]="welcome";
int i=0;
while(s[i]!='\0')
{
data(s[i]);
i++;
}
}

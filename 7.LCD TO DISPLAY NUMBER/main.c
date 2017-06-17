#include<avr/io.h>
#include<avr/delay.h>
#include<stdlib.h>
#include<stdio.h>
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
char t[3];
int e=555;
DDRB=0xff;
DDRD=0xff;
cmd(0x0C);
cmd(0x01);
cmd(0x80);
cmd(0x38);

itoa(e,t,10);
char s[10]="welcome";
char d[10]="1,2,3";

int i=0,j=0;
while(s[i]!='\0')
{
data(t[i]);
i++;
}
_delay_ms(500);
cmd(0x01);
cmd(0xc0);
while(d[j]!='\0')
{
data(d[j]);
j++;
}
}
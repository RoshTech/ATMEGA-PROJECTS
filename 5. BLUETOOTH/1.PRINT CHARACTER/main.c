#include<avr/io.h>
#include<util/delay.h>
#include "usart.h"

void main()
{

usart_init();

while(1){
usart_data_transmit('a');
_delay_ms(100);

}


}
#include "stm32f407xx.h"

void delay(void)
	{
		uint32_t i=0;
		for(i=0; i < 500000;i++);
}
	
int main(void)
{
// Enable the GPIO Clock for GPIOD 
	RCC->AHB1ENR |= (1 << 3);
// Set any Control Registers for GPIOD Pin 10
// Moder
	GPIOD->MODER |= (1 << 20);
// OTyper
	GPIOD->OTYPER &= ~(1 << 10);
// OSpeedr
	GPIOD->OSPEEDR &= ~( (1 << 21) | (1 << 20) );
// PUPDr
	GPIOD->PUPDR &= ~( (1 << 21) | (1 << 20) );
while(1)
{
// Turn on the LED (BSRR)
	GPIOD->BSRR = (1 << 10);
// Wait
	delay();
// Turn off the LED (BRR)
	GPIOD->BSRR = (1 << 26);
// Wait
	delay();
}

}

#include "header.h"

volatile int count = 0;

int main(void)
{
	//SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	LEDConfig();
	SW3Config();
	GPIOInterruptConfig();
	
	while(1)
	{
		if(count == 1)
		{
			RedLight();
		}
		else if (count == 2)
		{
			GreenLight();
		}
		else if (count == 3)
		{
			BlueLight();
			count = 0;
		}
	}
}

void PORTC_IRQHandler(void)
{
	count++;
	SetOrClearBit((unsigned int*) PORTC_PCR13, 16u, SET_BIT); //CLEAR FLAG
}

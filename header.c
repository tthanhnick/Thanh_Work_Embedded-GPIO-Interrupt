#include "header.h"

 void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (1U<<position);
	}
	else
	{
		*address &= ~(1U<<position);
	}
	return;
}

 void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (mask<<position);
	}
	else
	{
		*address &= ~(mask<<position);
	}
	return;
}

 void LEDConfig (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	
	SetOrClearMultiBit((unsigned int*) PORT_PCR15, 8u, 1u, SET_BIT); //0b001 GPIO Mode
	SetOrClearMultiBit((unsigned int*) PORT_PCR0, 8u, 1u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR16, 8u, 1u, SET_BIT);
	
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 15u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 0u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 16u, SET_BIT); 
}

 void SW3Config (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTC, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR13, 8u, 1u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 13u, CLEAR_BIT);
	// Turn off light
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 15u, 1u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 0u, 1u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 16u, 1u, SET_BIT);
}

 void RedLight(void)
{
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 0u, 1u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 16u, 1u, SET_BIT);	
}

 void BlueLight(void)
{
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 0u, 1u, CLEAR_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 16u, 1u, SET_BIT);	
}

 void GreenLight(void)
{
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 0u, 1u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 16u, 1u, CLEAR_BIT);	
}

 void InterruptConfig(void)
{
	SetOrClearMultiBit((unsigned int*) PORT_PCR13, 16u, 11u, SET_BIT); //0b1011 - Either Edge
	SetOrClearBit((unsigned int*) NVIC_INTERRUPT, 29u, SET_BIT); //NVIC Interrupt ID 61 Mod 32
}

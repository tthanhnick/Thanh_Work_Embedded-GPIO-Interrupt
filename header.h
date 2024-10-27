#define SET_BIT 1
#define CLEAR_BIT 0

#define PCC_PORTD (0x40065000u + 0x130u) //Peripheral Clock PORT D 
#define PORTD_PCR15 (0x4004C000u + 0x3Cu) // PIN 15 RED
#define PORTD_PCR0 (0x4004C000u + 0x0u) // PIN 0 BLUE
#define PORTD_PCR16 (0x4004C000u + 0x40u) // PIN 16 GREEN
#define GPIOD_PDDR (0x400FF0C0u + 0x14u) // Data Direction Port D
#define GPIOD_PDOR (0x400FF0C0u + 0x0u) // Output register

#define PCC_PORTC (0x40065000u + 0x12Cu) //Peripheral Clock PORT C 
#define PORTC_PCR13 (0x4004B000u + 0x34u) // PIN 13 
#define GPIOC_PDDR (0x400FF080u + 0x14u) // Data Direction Port C
#define GPIOC_PDIR (0x400FF080u + 0x10u) // Input register

#define NVIC_INTERRUPT (0xE000E100u + 4*1) // NVIC Interrupt NVIC ID 61 Div 32

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action);
void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action);
void LEDConfig (void);
void SW3Config (void);
void GPIOInterruptConfig(void);
void PORTC_IRQHandler(void);
void RedLight(void);
void GreenLight(void);
void BlueLight(void);
void PressButton(void);

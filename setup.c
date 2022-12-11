#include "header.h" //Inkluderar headerfilen.

void setup (void){
	
	set(DDRB, LED1); //H�r anv�nder vi v�rat set-makro f�r att ettst�lla LED-bitarna i DDRB-registret. 
	set(DDRB, LED2);
	set(DDRB, LED3);
	
	asm("SEI"); //Assembler-instruktion f�r att aktivera interrupts globalt
	PCICR |= (1<<PCIE0); //Initierar externa PCI-interrupts
	PCMSK0 |= (1<<PCINT5); //Initierar interrupts p� v�r tryckknapps pin
	
	return;
}
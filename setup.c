#include "header.h" //Inkluderar headerfilen.

void setup (void){
	
	set(DDRB, LED1); //Här använder vi vårat set-makro för att ettställa LED-bitarna i DDRB-registret. 
	set(DDRB, LED2);
	set(DDRB, LED3);
	
	asm("SEI"); //Assembler-instruktion för att aktivera interrupts globalt
	PCICR |= (1<<PCIE0); //Initierar externa PCI-interrupts
	PCMSK0 |= (1<<PCINT5); //Initierar interrupts på vår tryckknapps pin
	
	return;
}
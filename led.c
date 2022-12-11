#include "header.h" //Inkluderar headerfilen.

void led_blink (const uint16_t blink_ms){ //Vår sling-funktion. Tar emot delaytiden som ingående argument. 

	LED1_ON; //Tänder LED1
	delay_ms(blink_ms); //Kör delay_ms funktionen från misc.c, med delaytiden som ingående argument.
	LED1_OFF; //Släcker LED1
	delay_ms(blink_ms); //Etc etc...
	
	LED2_ON;
	delay_ms(blink_ms);
	LED2_OFF;
	delay_ms(blink_ms);
	
	LED3_ON;
	delay_ms(blink_ms);
	LED3_OFF;
	delay_ms(blink_ms);
	
	return;
}

#include "header.h" //Inkluderar headerfilen.

void led_blink (const uint16_t blink_ms){ //V�r sling-funktion. Tar emot delaytiden som ing�ende argument. 

	LED1_ON; //T�nder LED1
	delay_ms(blink_ms); //K�r delay_ms funktionen fr�n misc.c, med delaytiden som ing�ende argument.
	LED1_OFF; //Sl�cker LED1
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

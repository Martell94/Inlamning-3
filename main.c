#include "header.h" //Inkluderar headerfilen

bool leds_enabled = false; 
//^Deklareras här för bruk i samtliga funktioner. Sätts till false för att dioder ska vara släckta vid start.

ISR (PCINT0_vect){ //Här definierar vi vad som ska hända när interrupt sker.
	
	if (!BUTTON_PRESSED){ 
		/*Eftersom vi vill att ändringen ska ske på stigande flank lägger vi in denna luriga rad.
		Vi skickas till ISR-funktionen vid interrupt, men först när maskinen inte längre ser en etta på 
		knappens pin (dvs den inte är nedtryckt) ändras värdet på leds_enabled.*/
		leds_enabled = !leds_enabled;
	}
}

int main(void){ //Programmets huvudkod
	
	setup(); //Kör vår setupfunktion.
	
	while (1){ //Körs så länge maskinen är igång.
		
		if (leds_enabled){ //Denna if-sats kollar värdet på leds_enabled, och agerar därefter.
			led_blink(100); //Kör vår slinga med 100ms hastighet.
		}
		else if (!leds_enabled){
			LEDS_OFF; //Släcker samtliga lysdioder.
		}
	}
	
	return 0;
}


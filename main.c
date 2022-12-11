#include "header.h" //Inkluderar headerfilen

bool leds_enabled = false; 
//^Deklareras h�r f�r bruk i samtliga funktioner. S�tts till false f�r att dioder ska vara sl�ckta vid start.

ISR (PCINT0_vect){ //H�r definierar vi vad som ska h�nda n�r interrupt sker.
	
	if (!BUTTON_PRESSED){ 
		/*Eftersom vi vill att �ndringen ska ske p� stigande flank l�gger vi in denna luriga rad.
		Vi skickas till ISR-funktionen vid interrupt, men f�rst n�r maskinen inte l�ngre ser en etta p� 
		knappens pin (dvs den inte �r nedtryckt) �ndras v�rdet p� leds_enabled.*/
		leds_enabled = !leds_enabled;
	}
}

int main(void){ //Programmets huvudkod
	
	setup(); //K�r v�r setupfunktion.
	
	while (1){ //K�rs s� l�nge maskinen �r ig�ng.
		
		if (leds_enabled){ //Denna if-sats kollar v�rdet p� leds_enabled, och agerar d�refter.
			led_blink(100); //K�r v�r slinga med 100ms hastighet.
		}
		else if (!leds_enabled){
			LEDS_OFF; //Sl�cker samtliga lysdioder.
		}
	}
	
	return 0;
}


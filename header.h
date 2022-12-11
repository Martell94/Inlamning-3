#ifndef HEADER_H_ //Headerguards.
#define HEADER_H_

#define F_CPU 16000000UL //16mhz klockfr.
#include "misc.h" //Inkluderar det enda standardbibliotek man n�gonsin kommer beh�va ;)

#define set(reg,bit) reg |= (1<<bit) //Makro f�r att ettst�lla bitar
#define clr(reg,bit) reg &= ~(1<<bit) //Makro f�r att nollst�lla bitar
#define read(reg,bit) (reg & (1<<bit)) //Makro f�r att l�sa bitar

#define LED1 PORTB0 //S�tter LED1 p� PORTB0, motsvarande pin 8
#define LED2 PORTB1 //S�tter LED1 p� PORTB0, motsvarande pin 9
#define LED3 PORTB2 //S�tter LED1 p� PORTB0, motsvarande pin 10

#define BUTTON PORTB5 //Definierar knappens pin.
#define BUTTON_PRESSED read(PINB, BUTTON) //H�r anv�nder vi v�rat read-makro f�r att l�sa av knappens pin. 

#define LED1_ON set(PORTB, LED1) //T�nder LED1
#define LED1_OFF clr(PORTB, LED1) // Sl�cker LED1
#define LED2_ON set(PORTB, LED2) //Etc, etc...
#define LED2_OFF clr(PORTB, LED2)
#define LED3_ON set(PORTB, LED3)
#define LED3_OFF clr(PORTB, LED3)

#define LEDS_ON PORTB |= ((1<<LED1) | (1<<LED2) | (1<<LED3)) //Ettst�ller samtliga LED-bitar
#define LEDS_OFF PORTB &= ~((1<<LED1) | (1<<LED2) | (1<<LED3)) //Nollst�ller samtliga LED-bitar

void setup (void); //H�r finnes funktionsmakron f�r samtliga funktioner. 
void led_blink (const uint16_t blink_ms);

#endif /* HEADER_H_ */
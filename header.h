#ifndef HEADER_H_ //Headerguards.
#define HEADER_H_

#define F_CPU 16000000UL //16mhz klockfr.
#include "misc.h" //Inkluderar det enda standardbibliotek man någonsin kommer behöva ;)

#define set(reg,bit) reg |= (1<<bit) //Makro för att ettställa bitar
#define clr(reg,bit) reg &= ~(1<<bit) //Makro för att nollställa bitar
#define read(reg,bit) (reg & (1<<bit)) //Makro för att läsa bitar

#define LED1 PORTB0 //Sätter LED1 på PORTB0, motsvarande pin 8
#define LED2 PORTB1 //Sätter LED1 på PORTB0, motsvarande pin 9
#define LED3 PORTB2 //Sätter LED1 på PORTB0, motsvarande pin 10

#define BUTTON PORTB5 //Definierar knappens pin.
#define BUTTON_PRESSED read(PINB, BUTTON) //Här använder vi vårat read-makro för att läsa av knappens pin. 

#define LED1_ON set(PORTB, LED1) //Tänder LED1
#define LED1_OFF clr(PORTB, LED1) // Släcker LED1
#define LED2_ON set(PORTB, LED2) //Etc, etc...
#define LED2_OFF clr(PORTB, LED2)
#define LED3_ON set(PORTB, LED3)
#define LED3_OFF clr(PORTB, LED3)

#define LEDS_ON PORTB |= ((1<<LED1) | (1<<LED2) | (1<<LED3)) //Ettställer samtliga LED-bitar
#define LEDS_OFF PORTB &= ~((1<<LED1) | (1<<LED2) | (1<<LED3)) //Nollställer samtliga LED-bitar

void setup (void); //Här finnes funktionsmakron för samtliga funktioner. 
void led_blink (const uint16_t blink_ms);

#endif /* HEADER_H_ */
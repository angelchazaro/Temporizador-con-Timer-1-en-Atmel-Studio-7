/*
	Este código realiza un parpadeo de un pin del puerto B del Arduino Nano (LED interno)
	donde cada intervalo de tiempo es gestionado por un temporizador configurado para los 
	registros del TIMER 1.

	Desarrollado por Angel Cházaro
*/


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int main (void)
{

	DDRB|=0x20;	//LED INTERNO DE ARDUINO COMO SALIDA
	PORTB&=~0x20;	//EL LED INICIA APAGADO

	TCCR1B= 0x05;	//TIMER 1 COMO TEMPORTIZADOR CON PRESCALADOR DE 256 en 0x04, con 0x05 es a 1024
	TIMSK1= 0x01;	//INTERRUPCIÓN POR SOBREFLUJO
	
	sei();	//SE HABILITAN INTERRUPCIONES GLOBALES

	//TCNT1=0x0bdc;	//TEMPORIZADOR A 1000 MS == 1 SEGUNDO
	TCNT1= 0xe17c; 	//TEMPORIZADOR A 500 MS == 1/2 SEGUNDO APROX.
	while(1)
	{
		
	}

}

ISR(TIMER1_OVF_vect)
{
	TCNT1=0xe17c;	//SE CARGA EL VALOR POR CADA INTERRUPCIÓN
	PORTB^=0x20;	//EL LED CAMBIA DE ESTADO POR INTERRUPCIÓN OCURRIDA CADA 1 SEGUNDO
}


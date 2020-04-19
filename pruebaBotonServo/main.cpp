/*
 * pruebaBotonServo.cpp
 *
 * Created: 04/18/2020 5:16:25 p. m.
 * Author : rober
 */ 


#define F_CPU 8000000UL		
#include <avr/io.h>		
#include <stdio.h>		
#include <util/delay.h>		



int main(void)
{
	uint8_t ESTADO = true;
	//Entradas
	DDRA &=~ (1<<PA0);
	DDRA &=~ (1<<PA1);
	DDRA &=~ (1<<PA2);
	DDRA &=~ (1<<PA3);
	DDRA &=~ (1<<PA4);
	
	
	//Salidas
	DDRD |= (1<<PD7);
	DDRD |= (1<<PD5);
	DDRB |= (1<<PB3);
	DDRD |= (1<<PD4);
		
	TCNT1 = 0;		
	ICR1 = 2499;	

	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	TCCR2 |= (0<<FOC2)|(1<<WGM20)|(1<<WGM21)|(0<<COM20)|(1<<COM21)|(1<<CS20)|(0<<CS21)|(1<<CS22);
	uint8_t i = 150;
	uint8_t j = 65;
	while(1)
	{
		
		if (PINA & (1<<PA4))
		{
			if (ESTADO == true)
			{
				PORTB |= (1<<PB3);
				_delay_ms(500);
				PORTB &=~ (1<<PB3);
				while (PINA & (1<<PA4))
				{
					
				}
				ESTADO = !ESTADO;
			}
			else{
				PORTD |= (1<<PD4);
				_delay_ms(500);
				PORTD &=~ (1<<PD4);
				while (PINA & (1<<PA4))
				{
					
				}
				ESTADO = !ESTADO;
			}

		}
		OCR1A = i;
		OCR2 = j;
		while(PINA & (1<<PA0)){
			OCR1A = i;
			_delay_ms(50);
			i = i - 1;
		}
		while(PINA & (1<<PA1)){
			OCR1A = i;
			_delay_ms(50);
			i = i + 1;
		}
		
		while(PINA & (1<<PA2)){
			OCR2 = j;
			_delay_ms(50);
			j = j - 1;
		}
		while(PINA & (1<<PA3)){
			OCR2 = j;
			_delay_ms(50);
			j = j + 1;
		}
			
}
}

/*
 * Audio.c
 *
 * Created: 22/04/2024 12:40:29
 * Author : DCE
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#include "Buzzer.h"

// Función para activar/desactivar el buzzer

#define BUZZER_PIN PB2
#define BUZZER_ON() (PORTB |= (1 << BUZZER_PIN))
#define BUZZER_OFF() (PORTB &= ~(1 << BUZZER_PIN))
#define TOGGLE_BUZZER() (PORTB ^= (1 << BUZZER_PIN))

// Función para reproducir un tono utilizando playSound_noTMR
static void inline playTone(uint16_t frequency, uint16_t duration_ms) {
	uint16_t period_us = F_CPU / frequency; // Calcula el período del tono en microsegundos

	for (uint16_t i = 0; i < duration_ms * F_CPU / period_us; i++) {
		BUZZER_ON(); // Activa el buzzer
		_delay_us(period_us / 2); // Espera la mitad del período
		BUZZER_OFF(); // Desactiva el buzzer
		_delay_us(period_us / 2); // Espera la otra mitad del período
	}
}

// Función principal para reproducir la melodía
static void inline playMelody() {
	// Reproduce una secuencia de notas
	playTone(10, 200); // La
	_delay_ms(50);
	playTone(12, 200); // Si
	_delay_ms(50);
	playTone(14, 200); // Do#
	_delay_ms(50);
	playTone(16, 200); // Re#
	_delay_ms(50);
	playTone(1800, 200); // Mi#
	_delay_ms(50);
	playTone(2000, 200); // Fa#
	_delay_ms(50);
	playTone(2200, 200); // Sol#
	_delay_ms(50);
	playTone(2400, 200); // La#
	_delay_ms(50);
	playTone(2600, 200); // Do
	_delay_ms(50);
	playTone(2800, 200); // Re
	_delay_ms(50);
	playTone(3000, 200); // Mi
	_delay_ms(50);
	playTone(3200, 200); // Fa
	_delay_ms(50);
	playTone(3400, 200); // Sol
	_delay_ms(50);
	playTone(3600, 200); // La
	_delay_ms(50);
	playTone(3800, 200); // Si
	_delay_ms(50);
}



int main(void) {	
	
	init_buzzer();
	
	uint16_t tone=1;
	while (1){
	
	playTone(tone,100);
	_delay_ms(1000);
	tone=(tone +1)% 255;
		
	}
	

	return 0;
}


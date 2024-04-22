/*
 * Audio.c
 *
 * Created: 22/04/2024 12:40:29
 * Author : DCE
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



#define BUZZER_PIN  PB2 //puerto al que está el BUZZER

#define PRESCALER   8    // Prescaler para el temporizador (64 prescale)

void init_buzzer() {
	// Configura el pin del buzzer como salida
	DDRB |= (1 << BUZZER_PIN);

	// Configura el modo de temporizador 0 (Timer0) para PWM
	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Modo PWM rápido
	TCCR0A |= (1 << COM0A0); // Clear OC0A on Compare Match
	TCCR0B |= (1 << CS01); // Configura el prescaler a 8
}

void playSound(uint8_t periodo_ms){
	// Calcula el valor de comparación necesario para el período deseado
	// (Formula: valor = (F_CPU / (prescaler * frequency)) - 1)
	uint8_t valor_comparacion = (F_CPU / (PRESCALER * periodo_ms * 1000UL)) - 1;

	// Establece el valor de comparación
	OCR0A = valor_comparacion;
}


int main(void) {
	init_buzzer();

	while (1){
		//_delay_ms(1000);
		playSound(500);
	}
	

	return 0;
}


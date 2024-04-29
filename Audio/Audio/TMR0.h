/*
 * TMR0.h
 *
 * Created: 29/04/2024 9:56:44
 *  Author: DCE
 */ 


#include <avr/io.h>

#define DIV_CLK_1   1
#define DIV_CLK_8   2
#define DIV_CLK_64  3
#define DIV_CLK_256 4
#define DIV_CLK_1024 5

// Inicialización del modo CTC del Timer0
void inline TMR0_CTC_Init() {
	// Poner WGM01 a 1
	TCCR0A |= (1 << WGM01);

	// Poner WGM00 a 0
	TCCR0A &= ~(1 << WGM00);
}

// Establecer el valor del contador A del Timer0
void inline TMR0_CTC_Set(uint8_t valueCounterA) {
	OCR0A = valueCounterA; // Establece el valor de comparación
}

// Inicializar Timer0 con el divisor de reloj especificado
void inline TMR0_CTC_Start(uint8_t divClock) {
	TCCR0A |= (1 << WGM01); // Configura modo CTC
	TCCR0B |= (divClock & 0x07); // Establece la división del reloj
}

// Habilitar interrupciones para Timer0
void inline TMR0_CTC_EnableInterrupt() {
	TIMSK0 |= (1 << OCIE0A); // Habilita la interrupción
}

// Deshabilitar interrupciones para Timer0
void inline TMR0_CTC_DisableInterrupt() {
	TIMSK0 &= ~(1 << OCIE0A); // Deshabilita la interrupción
}

// Detener Timer0
void inline TMR0_CTC_Stop() {
	TCCR0B &= ~(0x07); // Detiene el temporizador
}




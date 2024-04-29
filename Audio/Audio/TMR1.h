/*
 * TMR1.h
 *
 * Created: 29/04/2024 9:59:14
 *  Author: DCE
 */ 


#ifndef TMR1_H_
#define TMR1_H_

#include <avr/io.h>

#define DIV_CLK_1   1
#define DIV_CLK_8   2
#define DIV_CLK_64  3
#define DIV_CLK_256 4
#define DIV_CLK_1024 5

// Inicialización del modo CTC del Timer1
void inline TMR1_CTC_Init() {
	// Poner WGM12 a 1
	TCCR1A |= (1 << WGM12);

	// Poner WGM10 y WGM11 a 0
	TCCR1B &= ~(1 << WGM13);
	TCCR1B &= ~(1 << WGM11);
}

// Establecer el valor del contador A del Timer1
void inline TMR1_CTC_Set(uint16_t valueCounterA) {
	OCR1A = valueCounterA; // Establece el valor de comparación
}

// Inicializar Timer1 con el divisor de reloj especificado
void inline TMR1_CTC_Start(uint8_t divClock) {
	TCCR1B |= (1 << WGM12) | (1 << WGM13); // Configura modo CTC
	TCCR1B |= (divClock & 0x07); // Establece la división del reloj
}

// Habilitar interrupciones para Timer1
void inline TMR1_CTC_EnableInterrupt() {
	TIMSK1 |= (1 << OCIE1A); // Habilita la interrupción
}

// Deshabilitar interrupciones para Timer1
void inline TMR1_CTC_DisableInterrupt() {
	TIMSK1 &= ~(1 << OCIE1A); // Deshabilita la interrupción
}

// Detener Timer1
void inline TMR1_CTC_Stop() {
	TCCR1B &= ~(0x07); // Detiene el temporizador
}






#endif /* TMR1_H_ */
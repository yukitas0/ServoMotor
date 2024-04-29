/*
 * Buzzer.h
 *
 * Created: 29/04/2024 9:23:06
 *  Author: DCE
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "TMR0.h"
#include "TMR1.h"

#define NOTE_MI     659 // mi: ~659.25 Hz
#define NOTE_DO     523 // do: ~523.25 Hz
#define NOTE_SOL    784 // sol: ~783.99 Hz
#define NOTE_LA     880 // la: ~880.00 Hz
#define NOTE_SI     932 // si: ~932.33 Hz
#define NOTE_LA_S   932 // la#: ~932.33 Hz
#define NOTE_FA     698 // fa: ~698.46 Hz
#define NOTE_RE     587 // re: ~587.33 Hz
#define NOTE_SI_S   740 // si#: ~740.00 Hz
#define NOTE_FA_S   740 // fa#: ~739.99 Hz
#define NOTE_RE_S   622 // re#: ~622.25 Hz
#define NOTE_SOL_S  830 // sol#: ~830.61 Hz
#define NOTE_MI_S   622 // mi#: ~622.25 Hz
#define NOTE_DO_S   554 // do#: ~554.37 Hz


#define BUZZER_PIN  PB2 //puerto al que está el BUZZER

#define PRESCALER   8    // Prescaler para el temporizador (64 prescale)

#define TOGGLEBIT(ADDRESS,BIT)	(ADDRESS ^= (1<<BIT))

/*

static inline void playSound_TMR(uint8_t nTicks_beepFreq, uint16_t nTicks_beepDuration) {
	// Initialize Timer1 for sound duration
	TMR1_CTC_Init(nTicks_beepDuration);

	// Start Timer1
	TMR1_CTC_Start(DIV_CLK_1024);

	// Initialize Timer0 for sound frequency
	TMR0_CTC_Init(nTicks_beepFreq);

	// Start Timer0
	TMR0_CTC_Start(DIV_CLK_1024);

	// Wait for Timer1 to trigger
	while ((TIFR1 & (1 << OCF1A)) == 0);

	// Stop both timers
	TMR0_CTC_Stop();
	TMR1_CTC_Stop();

	// Clear Timer1 interrupt flag
	TIFR1 |= (1 << OCF1A);
}
*/



void init_buzzer() {
	// Configura el pin del buzzer como salida
	DDRB |= (1 << BUZZER_PIN);

	// Configura el modo de temporizador 0 (Timer0) para PWM
	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Modo PWM rápido
	TCCR0A |= (1 << COM0A0); // Clear OC0A on Compare Match
	TCCR0B |= (1 << CS01); // Configura el prescaler a 8
}

static inline void playSound_noTMR(uint8_t period_ms,uint8_t times){
	int i=0;
	for(i=0; i< times ;i++){
		_delay_ms(period_ms);
		TOGGLEBIT(PORTB,BUZZER_PIN);
	}
}
#include "BUZZER.h"

// Función para reproducir la secuencia de notas
void playMario() {
	// Definir las duraciones de cada nota (en milisegundos)
	uint16_t duration = 300; // Duración predeterminada de cada nota
	
	// Introducción de la canción
	playSound_noTMR(NOTE_FA, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	
	// Parte principal de la canción
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_FA, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_RE, duration);
	playSound_noTMR(NOTE_SI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_SI, duration);
	playSound_noTMR(NOTE_LA_S, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);

	// Repetición de la secuencia
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_RE, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_DO, duration);

	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_RE, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_RE, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_RE, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_SOL, duration);

	// Final de la canción
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_SOL_S, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_FA, duration);
	playSound_noTMR(NOTE_FA, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_SI, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_LA, duration);
	playSound_noTMR(NOTE_SOL, duration);
	playSound_noTMR(NOTE_FA, duration);
	playSound_noTMR(NOTE_MI, duration);
	playSound_noTMR(NOTE_DO, duration);
	playSound_noTMR(NOTE_SOL, duration);
}




static inline play_loading(){
	playSound_noTMR(5,5);
	_delay_ms(500);
	playSound_noTMR(3,5);
	_delay_ms(500);
	playSound_noTMR(10,10);
}



/*
//ejemplo de uso 

static inline void playSound_noTMR(uint8_t period_ms,uint8_t times){
	int i=0;
	for(i=0; i< times ;i++){
		_delay_ms(period_ms);
		TOGGLEBIT(PORTB,BUZZER_PIN);
	}
}

static inline play_loading(){
	playSound_noTMR(5,5);
	_delay_ms(500);
	playSound_noTMR(3,5);
	_delay_ms(500);
	playSound_noTMR(10,10);
}

*/

#endif /* BUZZER_H_ */
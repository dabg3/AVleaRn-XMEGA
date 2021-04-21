#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void global_setup_interrupts(void)
{
	// enable global interrupts
	sei();
	// enable all interrupt levels
	PMIC_CTRL |= PMIC_LOLVLEN_bm;
}

void setup_timer(void)
{
	// select clock prescaler (clk/8)
	TCC0_CTRLA = TC_CLKSEL_DIV8_gc;
	// enable overflow/underflow interrupts for timer. Set to high priority
	TCC0_INTCTRLA = TC_OVFINTLVL_LO_gc;
}

ISR(TCC0_OVF_vect) 
{
	//TCC0_INTFLAGS = TC0_OVFIF_bm;
	PORTR_OUTTGL = 1;
}

int main(void)
{
	global_setup_interrupts();
	setup_timer();
	// setup led PR0
	PORTR_DIR = 1;
	while(1) {
	}

}







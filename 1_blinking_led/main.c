#include <stdint.h>

struct io_port {
	uint8_t dir;	
	uint8_t dirset;	
	uint8_t dirclr;	
	uint8_t dirtgl;	
	uint8_t out;	
	uint8_t outset;	
	uint8_t outclr;	
	uint8_t outtgl;	
};

#define PORTD (*(struct io_port *) 0x0660)
#define PORTR (*(struct io_port *) 0x07E0)

#define PIN0_MASK 0x01
#define PIN1_MASK 0x02
#define PIN4_MASK 0x10


int main(void) {
	
	PORTR.dir = PIN0_MASK | PIN1_MASK;
	PORTD.dir = PIN4_MASK;
	PORTR.outset = PIN1_MASK;
	PORTD.outset = PIN4_MASK;

	while(1) {
		for(uint16_t i=0; i < 30000; i++){}
		if (PORTR.out == PIN1_MASK) {
			PORTR.outtgl = PIN0_MASK | PIN1_MASK;
		} else if (PORTR.out == PIN0_MASK) {
			PORTR.outtgl = PIN1_MASK;	
			PORTD.outtgl = PIN4_MASK;
		} else {
			PORTD.outtgl = PIN4_MASK;
			PORTR.outtgl = PIN0_MASK;
		}
	}

}

#include <stdint.h>

typedef uint8_t register8_t;

typedef struct PORT_struct {
	register8_t DIR;	
	register8_t DIRSET;	
	register8_t DIRCLR;	
	register8_t DIRTGL;	
	register8_t OUT;	
	register8_t OUTSET;	
	register8_t OUTCLR;	
	register8_t OUTTGL;	
} port_t;

#define PORTD (*(port_t *) 0x0660)
#define PORTR (*(port_t *) 0x07E0)

#define PIN0_MASK 0x01
#define PIN1_MASK 0x02
#define PIN4_MASK 0x10


int main(void) {
	
	PORTR.DIR = PIN0_MASK | PIN1_MASK;
	PORTD.DIR = PIN4_MASK;
	PORTR.OUTSET = PIN1_MASK;
	PORTD.OUTSET = PIN4_MASK;

	while(1) {
		for(uint16_t i=0; i < 30000; i++){}
		if (PORTR.OUT == PIN1_MASK) {
			PORTR.OUTTGL = PIN0_MASK | PIN1_MASK;
		} else if (PORTR.OUT == PIN0_MASK) {
			PORTR.OUTTGL = PIN1_MASK;	
			PORTD.OUTTGL = PIN4_MASK;
		} else {
			PORTD.OUTTGL = PIN4_MASK;
			PORTR.OUTTGL = PIN0_MASK;
		}
	}

}

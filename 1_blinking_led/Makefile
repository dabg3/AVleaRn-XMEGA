MCU=atxmega256a3bu
F_CPU=2000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
CFLAGS_RAW=-std=c99 -Wall -g -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=on
SRCS=main.c

all:
	${CC} ${CFLAGS_RAW} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -c flip2 -U application:w:${TARGET}.hex:i 

clean:
	rm -f *.bin *.hex

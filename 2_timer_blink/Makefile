MCU=atxmega256a3bu
F_CPU=2000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS_NO_OPT=-std=c99 -Wall -g -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
BIN_FOLDER=bin
TARGET=${BIN_FOLDER}/timer_blink
SRCS=main.c

all:
	@mkdir -p ${BIN_FOLDER}
	${CC} ${CFLAGS_NO_OPT} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -c flip2 -U application:w:${TARGET}.hex:i 

clean:
	rm -rf ${BIN_FOLDER}

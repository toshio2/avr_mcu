DEVICE				= atmega328p
F_CPU				= 16000000UL
CC					= avr-gcc
OBJCOPY				= avr-objcopy
CFLAGS				= -Wall -g -Os -mmcu=${DEVICE} -DF_CPU=${F_CPU} -I.
TARGET				= main
SRCS				= main.c
UPLOAD_SPEED		= 115200
PORT				= /dev/ttyACM0
PROGRAMMER			= arduino

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

upload:
	avrdude -p ${DEVICE} -c${PROGRAMMER} -P${PORT} -b${UPLOAD_SPEED} -Uflash:w:${TARGET}.hex:a


clean:
	rm -f *.bin

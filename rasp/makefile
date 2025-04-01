TARGET = hellorasberry switch device_gpio interrupt
all : ${TARGET}
CFLAGS = -lwiringPi

% :	%.c
	cc -o $@ $< ${CFLAGS}

clean:
	rm ${TARGET}s
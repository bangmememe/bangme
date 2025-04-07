TARGET = hellorasberry switch device_gpio interrupt ledpwm tonbuzzer hardtonbuzzer i2crgbled switchi2crgbled i2cservo
all : ${TARGET}
CFLAGS = -lwiringPi

% :	%.c
	cc -o $@ $< ${CFLAGS}

clean:
	rm ${TARGET}s
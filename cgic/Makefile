CFLAGS=-g -Wall
CC=/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-gcc
AR=/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-ar
RANLIB=/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-ranlib
LIBS=-L./ -lcgic

all: libcgic.a cgictest.cgi  led.cgi capture

install: libcgic.a
	cp libcgic.a /usr/local/lib
	cp cgic.h /usr/local/include
	@echo libcgic.a is in /usr/local/lib. cgic.h is in /usr/local/include.

libcgic.a: cgic.o cgic.h
	rm -f libcgic.a
	$(AR) rc libcgic.a cgic.o
	$(RANLIB) libcgic.a

#mingw32 and cygwin users: replace .cgi with .exe

cgictest.cgi: cgictest.o libcgic.a
	/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-gcc cgictest.o -o cgictest.cgi ${LIBS}

led.cgi: led.o libcgic.a
	/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-gcc led.o -o led.cgi ${LIBS}

capture: capture.o libcgic.a
	/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-gcc capture.o -o capture ${LIBS}

clean:
	rm -f *.o *.a led.cgi cgictest.cgi capture cgicunittest

test:
	/home/s5pv210/test0108/opt/FriendlyARM/toolschain/4.5.1/bin/arm-none-linux-gnueabi-gcc -D UNIT_TEST=1 cgic.c -o cgicunittest
	./cgicunittest

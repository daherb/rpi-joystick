default: demo joy2mouse joy2key
demo: demo.c wiring.c
	gcc -o demo -I../wiringPi/wiringPi -L../wiringPi/wiringPi -lwiringPi demo.c wiring.c
joy2mouse: joy2mouse.c wiring.c
	gcc -o joy2mouse -I../wiringPi/wiringPi -L../wiringPi/wiringPi -lwiringPi -lX11 -lXtst joy2mouse.c wiring.c
joy2key: joy2key.c wiring.c
	gcc -o joy2key -I../wiringPi/wiringPi -L../wiringPi/wiringPi -lwiringPi -lX11 -lXtst joy2key.c wiring.c
clean:
	rm -Rf demo joy2mouse joy2key *~ *.o

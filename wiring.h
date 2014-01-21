#ifndef WIRING_H
#define WIRING_H 1

#include <wiringPi.h>
#define UP_1 3
#define DOWN_1 5
#define LEFT_1 7
#define RIGHT_1 8
#define FIRE_1 10
#define UP_2 11
#define DOWN_2 13
#define LEFT_2 15
#define RIGHT_2 16
#define FIRE_2 18

extern int pins[];

extern void init();

#endif /* WIRING_H */

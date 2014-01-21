#include "wiring.h"
int pins[]={3, 5, 7, 8, 10, 11, 13, 15, 16, 18};

void init()
{
  wiringPiSetupPhys();
  int ct = 0 ;
  for (; ct<10; ct++)
    {
      int wipin = pins[ct];
      //      printf("Reseting pin %d\n",wipin);
      digitalWrite(wipin,LOW);
      pinMode(wipin, INPUT);
      pullUpDnControl(wipin, PUD_OFF);
    } 
}

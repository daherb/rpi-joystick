#include <stdio.h>
#include <unistd.h>
#include "wiring.h"

void starter(char *b, char *dir)
{
  printf("%s %s %s %s\n",b ,b ,b, dir);
}
void up_rise_starter()
{
  starter("/\\","rising");
}
void up_fall_starter()
{
  starter("/\\","falling");
}
void down_rise_starter()
{
  starter("\\/","rising");
}
void down_fall_starter()
{
  starter("\\/","falling");
}
void left_rise_starter()
{
  starter("<","rising");
}
void left_fall_starter()
{
  starter("<","falling");
}
void right_rise_starter()
{
  starter(">","rising");
}
void right_fall_starter()
{
  starter(">","falling");
}
void fire_rise_starter()
{
  starter("Fire","rising");
}

void fire_fall_starter()
{
  starter("Fire","falling");
}

int main()
{
  init();
  wiringPiISR(UP_1,INT_EDGE_RISING,&up_rise_starter);
  wiringPiISR(DOWN_1,INT_EDGE_RISING,&down_rise_starter);
  wiringPiISR(LEFT_1,INT_EDGE_RISING,&left_rise_starter);
  wiringPiISR(RIGHT_1,INT_EDGE_RISING,&right_rise_starter);
  wiringPiISR(FIRE_1,INT_EDGE_RISING,&fire_rise_starter);
  wiringPiISR(UP_1,INT_EDGE_FALLING,&up_fall_starter);
  wiringPiISR(DOWN_1,INT_EDGE_FALLING,&down_fall_starter);
  wiringPiISR(LEFT_1,INT_EDGE_FALLING,&left_fall_starter);
  wiringPiISR(RIGHT_1,INT_EDGE_FALLING,&right_fall_starter);
  wiringPiISR(FIRE_1,INT_EDGE_FALLING,&fire_fall_starter);

  while(1)
    {
      sleep(1);
    }
  return 0;
}

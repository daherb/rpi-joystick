#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include "wiring.h"

#define DELTA_X 1
#define DELTA_Y 1

Display *display;
//int screen;

void up_handler()
{
  printf("/\\\n");
  XTestFakeRelativeMotionEvent(display,0,-DELTA_Y,0);
  XFlush(display);
}
void down_handler()
{
  printf("\\/\n");
  XTestFakeRelativeMotionEvent(display,0,DELTA_Y,0);
  XFlush(display);
}
void left_handler()
{
  printf("<<\n");
  XTestFakeRelativeMotionEvent(display,-DELTA_X,0,0);
  XFlush(display);
}
void right_handler()
{
  printf(">>\n");
  XTestFakeRelativeMotionEvent(display,DELTA_X,0,0);
  XFlush(display);
}
void fire_handler()
{
  printf("><\n");
  XTestFakeButtonEvent(display,1,True,0);
  XTestFakeButtonEvent(display,1,False,1);
  XFlush(display);
}
int main()
{
  init();
  display = XOpenDisplay(NULL);
  //  screen = -1;
  wiringPiISR(UP_1,INT_EDGE_RISING,&up_handler);
  wiringPiISR(DOWN_1,INT_EDGE_RISING,&down_handler);
  wiringPiISR(LEFT_1,INT_EDGE_RISING,&left_handler);
  wiringPiISR(RIGHT_1,INT_EDGE_RISING,&right_handler);
  wiringPiISR(FIRE_1,INT_EDGE_RISING,&fire_handler);
  while(1)
    {
      sleep(1);
    }
  return 0;
}

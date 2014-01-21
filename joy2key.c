#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include "wiring.h"

#define DELTA_X 1
#define DELTA_Y 1

Display *display;
//int screen;
int up_key;
int down_key;
int left_key;
int right_key;
int space_key;
void press_key(int code)
{
  XTestFakeKeyEvent(display,code,True,0);
  XFlush(display);
  XTestFakeKeyEvent(display,code,False,1);
  XFlush(display);
}
void up_handler()
{
#ifdef DEBUG
  printf("/\\\n");
#endif
  press_key(up_key);
}
void down_handler()
{
#ifdef DEBUG
  printf("\\/\n");
#endif
  press_key(down_key);
}
void left_handler()
{
#ifdef DEBUG
  printf("<<\n");
#endif
  press_key(left_key);
}
void right_handler()
{
#ifdef DEBUG
  printf(">>\n");
#endif
  press_key(right_key);
}
void fire_handler()
{
#ifdef DEBUG
  printf("><\n");
#endif
  press_key(space_key);
}
int main()
{
  init();
  display = XOpenDisplay(NULL);
  //  screen = -1;
  up_key = XKeysymToKeycode(display,XK_Up);
  down_key = XKeysymToKeycode(display,XK_Down);
  left_key = XKeysymToKeycode(display,XK_Left);
  right_key = XKeysymToKeycode(display,XK_Right);
  space_key = XKeysymToKeycode(display,XK_space);
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

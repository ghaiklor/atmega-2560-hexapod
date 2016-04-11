#include "Spider.h"
#include "SimpleTimer.h"

int PINS[6][2] = {{28, 29}, {27, 26}, {46, 47}, {48, 49}, {50, 51}, {25, 24}};

Spider spider;
SimpleTimer timer;

void walk() {
  spider.walk();
}

void setup() {
  spider.attach(PINS);
  spider.setSpeed(15);
  timer.setInterval(20, walk);
}

void loop() {
  static int angle = 0;

  angle++;
  if (angle > 359) angle = 0;

  timer.run();
}

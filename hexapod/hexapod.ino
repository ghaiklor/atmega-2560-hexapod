#include "Spider.h"
#include "SimpleTimer.h"

int PINS[6][2] = {{28, 29}, {27, 26}, {46, 47}, {48, 49}, {50, 51}, {25, 24}};

Spider spider;
SimpleTimer timer;

void walk() {
  spider.walk();
}

void updateAngle() {
  static int angle = 0;

  angle++;
  if (angle > 359) angle = 0;
  spider.setAngle(angle);
}

void setup() {
  spider.attach(PINS);
  spider.setSpeed(15);
  delay(3000);

  timer.setInterval(15, walk);
  timer.setInterval(15, updateAngle);
}

void loop() {
  timer.run();
}

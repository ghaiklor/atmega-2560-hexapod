#include "Spider.h"

int PINS[6][2] = {{28, 29}, {27, 26}, {46, 47}, {48, 49}, {50, 51}, {25, 24}};

Spider spider;

void setup() {
  spider.attach(PINS);
  spider.setSpeed(10);
}

void loop() {
  static int end = millis() + 5000;

  if (millis() < end) {
    spider.walk();
    delay(20);
  } else {
    spider.setSpeed(0);
    spider.calibrate();
  }
}

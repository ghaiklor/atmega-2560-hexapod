#include "Spider.h"

Spider spider;

void setup() {
  spider.attach();
  spider.forward();
}

void loop() {
  static int end = millis() + 5000;

  if (millis() < end) {
    spider.walk();
    delay(20);
  } else {
    spider.stop();
    spider.calibrate();
  }
}

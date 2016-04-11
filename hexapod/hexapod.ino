#include "Spider.h"

#define KNEE_1_PIN 28
#define HIP_1_PIN 29
#define KNEE_2_PIN 27
#define HIP_2_PIN 26
#define KNEE_3_PIN 46
#define HIP_3_PIN 47
#define KNEE_4_PIN 48
#define HIP_4_PIN 49
#define KNEE_5_PIN 50
#define HIP_5_PIN 51
#define KNEE_6_PIN 25
#define HIP_6_PIN 24

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

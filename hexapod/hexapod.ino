#include "Spider.h"
#include "SimpleTimer.h"

int PINS[6][2] = {{28, 29}, {27, 26}, {46, 47}, {48, 49}, {50, 51}, {25, 24}};

Spider spider;
SimpleTimer timer;

void walkSpider() {
  spider.walk();
}

void setup() {
  spider.attach(PINS);
  spider.setSpeed(1);
  timer.setInterval(20, walkSpider);
}

void loop() {
//  timer.run();
}

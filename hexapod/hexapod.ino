#include "Spider.h"
#include "SimpleTimer.h"

int PINS[6][2] = {{28, 29}, {27, 26}, {46, 47}, {48, 49}, {50, 51}, {25, 24}};

Spider spider;
SimpleTimer timer;

void walkSpider() {
  spider.walk();
}

void randomParams() {
  spider.setSpeed(random(5, 10));
  spider.setAngle(random(0, 45));
}

void setup() {
  randomSeed(analogRead(A0));
  spider.attach(PINS);
  spider.setSpeed(10);
  timer.setInterval(20, walkSpider);
  timer.setInterval(10000, randomParams);
}

void loop() {
  timer.run();
}

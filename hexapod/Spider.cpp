/*
    Spider.h - Library for controlling the spider.
    Created by Eugene Obrezkov aka ghaiklor.
*/
#include "Arduino.h"
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

Spider::Spider() {
  _legs[0].attach(KNEE_1_PIN, HIP_1_PIN);
  _legs[1].attach(KNEE_2_PIN, HIP_2_PIN);
  _legs[2].attach(KNEE_3_PIN, HIP_3_PIN);
  _legs[3].attach(KNEE_4_PIN, HIP_4_PIN);
  _legs[4].attach(KNEE_5_PIN, HIP_5_PIN);
  _legs[5].attach(KNEE_6_PIN, HIP_6_PIN);
}

void Spider::layDown() {
  for (int i = 0; i < 6; i++) {
    _legs[i].rotate(0, 90);
  }
}

void Spider::layUp() {
  for (int i = 0; i < 6; i++) {
    _legs[i].rotate(90, 90);
  }
}

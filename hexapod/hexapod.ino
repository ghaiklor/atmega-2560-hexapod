#include "Leg.h"

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

Leg legs[6];

void setup() {
  randomSeed(analogRead(A0));

  legs[0].attach(KNEE_1_PIN, HIP_1_PIN);
  legs[1].attach(KNEE_2_PIN, HIP_2_PIN);
  legs[2].attach(KNEE_3_PIN, HIP_3_PIN);
  legs[3].attach(KNEE_4_PIN, HIP_4_PIN);
  legs[4].attach(KNEE_5_PIN, HIP_5_PIN);
  legs[5].attach(KNEE_6_PIN, HIP_6_PIN);

  for (int i = 0; i < 6; i++) {
    legs[i].center();
  }
}

void loop() {
  int angle = random(20, 160);
  for (int i = 0; i < 6; i++) {
    legs[i].rotate(angle, angle);
  }

  delay(2000);
}


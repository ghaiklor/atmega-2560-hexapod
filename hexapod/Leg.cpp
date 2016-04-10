/*
   Leg.h - Library for controlling the specific legs in your spider.
   Created by Eugene Obrezkov aka ghaiklor
*/

#include "Arduino.h"
#include "Leg.h"

Leg::Leg() {}

void Leg::attach(byte kneePin, byte hipPin) {
  _kneePin = kneePin;
  _hipPin = hipPin;

  _kneeServo.attach(_kneePin);
  _hipServo.attach(_hipPin);

  calibrate(90, 90);
  reset();
}

void Leg::rotateKnee(byte deg) {
  _kneeServo.write(deg);
}

void Leg::rotateHip(byte deg) {
  _hipServo.write(deg);
}

void Leg::calibrate(byte kneeInitDeg, byte hipInitDeg) {
  _kneeInitDeg = kneeInitDeg;
  _hipInitDeg = hipInitDeg;
}

void Leg::reset() {
  _kneeServo.write(_kneeInitDeg);
  _hipServo.write(_hipInitDeg);
}

void Leg::test() {
  rotateKnee(0);
  delay(500);

  rotateKnee(180);
  delay(500);

  rotateHip(0);
  delay(500);

  rotateHip(180);
  delay(500);

  reset();
}


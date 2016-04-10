/*
   Leg.h - Library for controlling the specific legs in your spider.
   Created by Eugene Obrezkov aka ghaiklor
*/

#include "Arduino.h"
#include "Leg.h"

Leg::Leg(int kneePin, int hipPin) {
  _kneePin = kneePin;
  _hipPin = hipPin;

  _knee.attach(_kneePin, 800, 2200);
  delay(40);

  _hip.attach(_hipPin, 800, 2200);
  delay(40);

  this->writeToKnee(1500);
  this->writeToHip(1500);
}

void Leg::writeToKnee(int microseconds) {
  _knee.writeMicroseconds(microseconds);
}

void Leg::writeToHip(int microseconds) {
  _hip.writeMicroseconds(microseconds);
}

void Leg::rotateKnee(int deg) {
  _knee.write(deg);
}

void Leg::rotateHip(int deg) {
  _hip.write(deg);
}


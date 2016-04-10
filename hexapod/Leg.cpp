/*
    Leg.cpp - Library for controlling the specific legs in your spider.
    Created by Eugene Obrezkov aka ghaiklor.
*/
#include "Arduino.h"
#include "Leg.h"

#define MIN_PULSE_WIDTH 1000
#define MAX_PULSE_WIDTH 2000

Leg::Leg() {}

void Leg::attach(byte kneePin, byte hipPin) {
  _kneeServo.attach(kneePin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  _hipServo.attach(hipPin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

void Leg::rotate(byte kneeDeg, byte hipDeg) {
  rotateKnee(kneeDeg);
  rotateHip(hipDeg);
}

void Leg::rotateKnee(byte deg) {
  _kneeServo.write(deg);
}

void Leg::rotateHip(byte deg) {
  _hipServo.write(deg);
}

void Leg::center() {
  rotate(90, 90);
}


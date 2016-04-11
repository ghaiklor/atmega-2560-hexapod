#include "Leg.h"

void Leg::attach(byte kneePin, byte hipPin) {
  _kneeServo.attach(kneePin, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  _hipServo.attach(hipPin, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
}

void Leg::rotateKnee(byte deg) {
  _kneeServo.write(deg);
}

void Leg::rotateHip(byte deg) {
  _hipServo.write(deg);
}

void Leg::rotate(byte kneeDeg, byte hipDeg) {
  rotateKnee(kneeDeg);
  rotateHip(hipDeg);
}

byte Leg::getKneeDeg() {
  return _kneeServo.read();
}

byte Leg::getHipDeg() {
  return _hipServo.read();
}

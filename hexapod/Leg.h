#ifndef _Leg_h_
#define _Leg_h_

#include "Arduino.h"
#include "Servo.h"

#define SERVO_MIN_PULSE_WIDTH 1000
#define SERVO_MAX_PULSE_WIDTH 2000

class Leg {
  private:
    Servo _kneeServo;
    Servo _hipServo;
  public:
    void attach(byte kneePin, byte hipPin);
    void rotateKnee(byte deg);
    void rotateHip(byte deg);
    void rotate(byte kneeDeg, byte hipDeg);
    byte getKneeDeg();
    byte getHipDeg();
};

#endif

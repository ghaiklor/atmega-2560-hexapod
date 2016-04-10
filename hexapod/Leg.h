/*
   Leg.h - Library for controlling the specific legs in your spider.
   Created by Eugene Obrezkov aka ghaiklor.
*/
#ifndef _Leg_h_
#define _Leg_h_

#include "Arduino.h"
#include "Servo.h"

class Leg {
  public:
    Leg();
    void attach(byte kneePin, byte hipPin);
    void rotateKnee(byte deg);
    void rotateHip(byte deg);
    void calibrate(byte kneeInitDeg, byte hipInitDeg);
    void reset();
    void test();
  private:
    byte _kneePin;
    byte _hipPin;
    byte _kneeInitDeg;
    byte _hipInitDeg;
    Servo _kneeServo;
    Servo _hipServo;
};

#endif

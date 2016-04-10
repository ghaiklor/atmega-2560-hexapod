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
    void rotate(byte kneeDeg, byte hipDeg);
    void rotateKnee(byte deg);
    void rotateHip(byte deg);
    void center();
  private:
    Servo _kneeServo;
    Servo _hipServo;
};

#endif


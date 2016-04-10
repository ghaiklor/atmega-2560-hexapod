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
    Leg(int kneePin, int hipPin);
    void writeToKnee(int microseconds);
    void writeToHip(int microseconds);
    void rotateKnee(int deg);
    void rotateHip(int deg);
  private:
    Servo _knee;
    Servo _hip;
    int _kneePin;
    int _hipPin;
};

#endif

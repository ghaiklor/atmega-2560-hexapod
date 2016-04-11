#ifndef _Spider_h_
#define _Spider_h_

#include "Arduino.h"
#include "Leg.h"

class Spider {
  private:
    int _angle = 0;
    byte _rotate = 0;
    byte _speed = 0;
    int _stride = 0;
    Leg _legs[6];

  public:
    int getAngle();
    void setAngle(int angle);
    byte getRotate();
    void setRotate(byte rotate);
    byte getSpeed();
    void setSpeed(byte speed);
    Leg getLeg(byte index);
    void attach(int pins[6][2]);
    void calibrate();
    void walk();
};

#endif

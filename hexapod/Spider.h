#ifndef _Spider_h_
#define _Spider_h_

#include "Arduino.h"
#include "Leg.h"

class Spider {
  private:
    int _angle = 0;
    int _rotate = 0;
    int _speed = 0;
    int _stride = 0;
    Leg _legs[6];
  public:
    int getAngle();
    void setAngle(int angle);
    int getRotate();
    void setRotate(int rotate);
    int getSpeed();
    void setSpeed(int speed);
    void attach();
    void calibrate();
    void forward();
    void backward();
    void stop();
    void walk();
};

#endif

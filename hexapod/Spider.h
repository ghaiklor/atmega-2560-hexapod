#ifndef _Spider_h_
#define _Spider_h_

#include "Arduino.h"
#include "Leg.h"

class Spider {
  private:
    int _angle;
    int _rotate;
    int _speed;
    int _stride;
    Leg _legs[6];
  public:
    Spider();
    void attach();
    void checkLegs();
    void stop();
    void forward();
    void backward();
    void clockwise();
    void counterClockwise();
    void rotate(int angle);
};

#endif

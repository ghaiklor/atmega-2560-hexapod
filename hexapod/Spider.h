#ifndef _Spider_h_
#define _Spider_h_

#include "Arduino.h"
#include "Leg.h"

#define KNEE_1_PIN 28
#define HIP_1_PIN 29
#define KNEE_2_PIN 27
#define HIP_2_PIN 26
#define KNEE_3_PIN 46
#define HIP_3_PIN 47
#define KNEE_4_PIN 48
#define HIP_4_PIN 49
#define KNEE_5_PIN 50
#define HIP_5_PIN 51
#define KNEE_6_PIN 25
#define HIP_6_PIN 24

class Spider {
  private:
    int _angle = 0;
    int _rotate = 0;
    int _speed = 0;
    int _stride = 0;
    Leg _legs[6];
  public:
    void attach();
    void calibrate();
    void forward();
    void backward();
    void stop();
    void walk();
};

#endif

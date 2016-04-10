/*
    Spider.h - Library for controlling the spider.
    Created by Eugene Obrezkov aka ghaiklor.
*/
#ifndef _Spider_h_
#define _Spider_h_

#include "Arduino.h"
#include "Leg.h"

class Spider {
  public:
    Spider();
    void layDown();
    void layUp();
  private:
    Leg _legs[6];
};

#endif


#include "Spider.h"

int Spider::getAngle() {
  return int(_angle);
}

void Spider::setAngle(int angle) {
  if (angle < 0) angle = 0;
  if (angle > 359) angle -= 360;

  _angle = int(angle);
}

byte Spider::getRotate() {
  return byte(_rotate);
}

void Spider::setRotate(byte rotate) {
  if (rotate > 0) rotate = 1;
  if (rotate < 0) rotate = -1;

  _rotate = byte(rotate);
}

byte Spider::getSpeed() {
  return byte(_speed);
}

void Spider::setSpeed(byte speed) {
  if (speed < -15) speed = -15;
  if (speed > 15) speed = 15;

  _speed = byte(speed);
}

Leg Spider::getLeg(byte index) {
  return Leg(_legs[index]);
}

void Spider::attach(int pins[6][2]) {
  for (int i = 0; i < 6; i++) {
    _legs[i].attach(pins[i][0], pins[i][1]);
  }
}

void Spider::calibrate() {
  for (int i = 0; i < 6; i++) {
    _legs[i].rotate(90, 90);
  }
}

void Spider::walk() {
  static int step = 0;

  float a;
  double xa, knee, hip;

  if (_speed == 0) {
    _stride -= 25;
    if (_stride < 0) _stride = 0;
  } else {
    _stride += 25;
    if (_stride > 450) _stride = 450;
  }

  for (int i = 0; i < 6; i++) {
    a = float(60 * i + _angle);
    if (a > 359) a -= 360;

    a = a * PI / 180;
    xa = _stride * _rotate;
    if (_rotate == 0) xa = sin(a) * -_stride;

    a = i % 2 == 0 ? float(step) : float(step + 180);
    if (a > 359) a -= 360;
    a = a * PI / 180;
    knee = sin(a) * _stride;
    hip = cos(a) * xa;

    _legs[i].rotate(map(1500 + int(knee), MIN_PULSE_WIDTH, MAX_PULSE_WIDTH, 0, 180), map(1500 + int(hip), MIN_PULSE_WIDTH, MAX_PULSE_WIDTH, 0, 180));
  }

  step += _speed;
  if (step > 359) step -= 360;
  if (step < 0) step += 360;
}

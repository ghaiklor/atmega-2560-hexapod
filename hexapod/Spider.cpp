#include "Spider.h"

int Spider::getAngle() {
  return int(_angle);
}

void Spider::setAngle(int angle) {
  _angle = int(angle);
}

byte Spider::getRotate() {
  return byte(_rotate);
}

void Spider::setRotate(byte rotate) {
  _rotate = byte(rotate);
}

byte Spider::getSpeed() {
  return byte(_speed);
}

void Spider::setSpeed(byte speed) {
  _speed = byte(speed);
}

Leg Spider::getLeg(byte index) {
  return Leg(_legs[index]);
}

void Spider::attach(int pins[6][2]) {
  _legs[0].attach(pins[0][0], pins[0][1]);
  _legs[1].attach(pins[1][0], pins[1][1]);
  _legs[2].attach(pins[2][0], pins[2][1]);
  _legs[3].attach(pins[3][0], pins[3][1]);
  _legs[4].attach(pins[4][0], pins[4][1]);
  _legs[5].attach(pins[5][0], pins[5][1]);
}

void Spider::calibrate() {
  for (int i = 0; i < 6; i++) _legs[i].rotate(90, 90);
}

void Spider::walk() {
  float A;
  double Xa, Knee, Hip;
  static int Step;

  if (_angle < 0) _angle = 0;
  if (_angle > 360) _angle = 360;

  if (_speed == 0) {
    _stride -= 25;
    if (_stride < 0) _stride = 0;
  } else {
    _stride += 25;
    if (_stride > 450) _stride = 450;
  }

  for (int i = 0; i < 6; i++) {
    A = float(60 * i + _angle);
    if (A > 359) A -= 360;

    A = A * PI / 180;
    Xa = _stride * _rotate;
    if (_rotate == 0) {
      Xa = sin(A) * -_stride;
    }

    A = i % 2 == 0 ? float(Step) : float(Step + 180);
    if (A > 359) A -= 360;
    A = A * PI / 180;
    Knee = sin(A) * _stride;
    Hip = cos(A) * Xa;

    _legs[i].rotate(map(1500 + int(Knee), MIN_PULSE_WIDTH, MAX_PULSE_WIDTH, 0, 180), map(1500 + int(Hip), MIN_PULSE_WIDTH, MAX_PULSE_WIDTH, 0, 180));
  }

  Step += _speed;
  if (Step > 359) Step -= 360;
  if (Step < 0) Step += 360;
}

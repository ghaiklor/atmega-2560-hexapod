#include "Spider.h"

void Spider::attach() {
  _legs[0].attach(KNEE_1_PIN, HIP_1_PIN);
  _legs[1].attach(KNEE_2_PIN, HIP_2_PIN);
  _legs[2].attach(KNEE_3_PIN, HIP_3_PIN);
  _legs[3].attach(KNEE_4_PIN, HIP_4_PIN);
  _legs[4].attach(KNEE_5_PIN, HIP_5_PIN);
  _legs[5].attach(KNEE_6_PIN, HIP_6_PIN);
}

void Spider::calibrate() {
  for (int i = 0; i < 6; i++) _legs[i].rotate(90, 90);
}

void Spider::forward() {
  _speed = 10;
}

void Spider::backward() {
  _speed = -10;
}

void Spider::stop() {
  _speed = 0;
}

void Spider::walk() {
  float A;
  double Xa, Knee, Hip;
  static int Step;

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

    _legs[i].rotate(map(1500 + int(Knee), SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH, 0, 180), map(1500 + int(Hip), SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH, 0, 180));
  }

  Step += _speed;
  if (Step > 359) Step -= 360;
  if (Step < 0) Step += 360;
}

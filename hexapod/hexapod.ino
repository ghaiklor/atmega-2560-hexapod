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

Leg legs[6];

int currentAngle = 0; // determines the direction/angle that the robot will walk in
int currentRotate = 0;  // rotate mode: -1 = anticlockwise, +1 = clockwise, 0 = no rotation
int currentSpeed = 0;  // walking speed: in range from -15 to +15
int currentStride = 0; // size of step: exceeding 400 may cause the legs to hit each other

void setup() {
  legs[0].attach(KNEE_1_PIN, HIP_1_PIN);
  legs[1].attach(KNEE_2_PIN, HIP_2_PIN);
  legs[2].attach(KNEE_3_PIN, HIP_3_PIN);
  legs[3].attach(KNEE_4_PIN, HIP_4_PIN);
  legs[4].attach(KNEE_5_PIN, HIP_5_PIN);
  legs[5].attach(KNEE_6_PIN, HIP_6_PIN);

  for (int i = 0; i < 6; i++) {
    legs[i].test();
  }
  //  servos[0].attach(servosPins[0], 800, 2200);
  //  delay(40);
  //
  //  servos[1].attach(servosPins[1], 800, 2200);
  //  delay(40);
  //
  //  servos[2].attach(servosPins[2], 800, 2200);
  //  delay(40);
  //
  //  servos[3].attach(servosPins[3], 800, 2200);
  //  delay(40);
  //
  //  servos[4].attach(servosPins[4], 800, 2200);
  //  delay(40);
  //
  //  servos[5].attach(servosPins[5], 800, 2200);
  //  delay(40);
  //
  //  servos[6].attach(servosPins[6], 800, 2200);
  //  delay(40);
  //
  //  servos[7].attach(servosPins[7], 800, 2200);
  //  delay(40);
  //
  //  servos[8].attach(servosPins[8], 800, 2200);
  //  delay(40);
  //
  //  servos[9].attach(servosPins[9], 800, 2200);
  //  delay(40);
  //
  //  servos[10].attach(servosPins[10], 800, 2200);
  //  delay(40);
  //
  //  servos[11].attach(servosPins[11], 800, 2200);
  //  delay(40);
  //
  //  for (int i = 0; i < 12; i++) {
  //    servos[i].writeMicroseconds(initServosValues[i]);
  //  }

  // A little timeout before it starts moving
  delay(3000);
}

void loop() {
  //  if (currentAngle < 0) currentAngle += 360;
  //  if (currentAngle > 359) currentAngle -= 360;
  //
  //  Walk();
  //
  //  delay(15);
}

void Walk() {
  float A; // temporary value for angle calculations
  double Xa, Knee, Hip; // results of trigometric functions
  static int Step; // position of legs in circular motion from 0 to 360

  // return all legs to default position when stopped
  if (currentSpeed == 0) {
    currentStride -= 25;
    if (currentStride < 0) currentStride = 0;
  } else {
    currentStride += 25;
    if (currentStride > 450) currentStride = 450;
  }

  // calculate positions for odd numbered legs 1,3,5
  for (int i = 0; i < 6; i += 2) {
    A = float(60 * i + currentAngle); // angle of leg on the body + angle of travel
    if (A > 359) A -= 360; // keep value within 0-360

    A = A * PI / 180; // convert degrees to radians for SIN function

    Xa = currentStride * currentRotate; // Xa value for rotation
    if (currentRotate == 0) {
      Xa = sin(A) * -currentStride; // Xa hip position multiplier for walking at an angle
    }

    A = float(Step); // angle of leg
    A = A * PI / 180; // convert degrees to radians for SIN function
    Knee = sin(A) * currentStride;
    Hip = cos(A) * Xa;

    //    servos[i * 2].writeMicroseconds(initServosValues[i * 2] + int(Knee)); // update knee  servos 1,3,5
    //    servos[i * 2 + 1].writeMicroseconds(initServosValues[i * 2 + 1] + int(Hip)); // update hip servos 1,3,5
  }

  // calculate positions for even numbered legs 2,4,6
  for (int i = 1; i < 6; i += 2) {
    A = float(60 * i + currentAngle); // angle of leg on the body + angle of travel
    if (A > 359) A -= 360; // keep value within 0-360

    A = A * PI / 180; // convert degrees to radians for SIN function
    Xa = currentStride * currentRotate; // Xa value for rotation
    if (currentRotate == 0) {
      Xa = sin(A) * -currentStride; // Xa hip position multiplier for walking at an angle
    }

    A = float(Step + 180); // angle of leg
    if (A > 359) A -= 360; // keep value within 0-360
    A = A * PI / 180; // convert degrees to radians for SIN function
    Knee = sin(A) * currentStride;
    Hip = cos(A) * Xa;

    //    servos[i * 2].writeMicroseconds(initServosValues[i * 2] + int(Knee)); // update knee  servos 2,4,6
    //    servos[i * 2 + 1].writeMicroseconds(initServosValues[i * 2 + 1] + int(Hip)); // update hip servos 2,4,6
  }

  Step += currentSpeed;
  if (Step > 359) Step -= 360;
  if (Step < 0) Step += 360;
}


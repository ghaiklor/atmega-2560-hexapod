#include <Servo.h>

Servo servos[12];

// Array of pins that are connected to legs
int servosPins[12] = {
  28, 29, // Knee and Hip 1
  27, 26, // Knee and Hip 2
  46, 47, // Knee and Hip 3
  48, 49, // Knee and Hip 4
  50, 51, // Knee and Hip 5
  25, 24  // Knee and Hip 6
};

// Start values for legs (initial values)
int initServosValues[12] = {
  1500, 1550,  // Start value for leg 1
  1550, 1450,  // Start value for leg 2
  1500, 1400,  // Start value for leg 3
  1500, 1550,  // Start value for leg 4
  1500, 1500,  // Start value for leg 5
  1500, 1400   // Start value for leg 6
};

int currentAngle = 0; // determines the direction/angle that the robot will walk in
int currentRotate = 0;  // rotate mode: -1 = anticlockwise, +1 = clockwise, 0 = no rotation
int currentSpeed = 0;  // walking speed: in range from -15 to +15
int currentStride = 0; // size of step: exceeding 400 may cause the legs to hit each other

void setup() {
  servos[0].attach(servosPins[0], 800, 2200);
  delay(40);

  servos[1].attach(servosPins[1], 800, 2200);
  delay(40);

  servos[2].attach(servosPins[2], 800, 2200);
  delay(40);

  servos[3].attach(servosPins[3], 800, 2200);
  delay(40);

  servos[4].attach(servosPins[4], 800, 2200);
  delay(40);

  servos[5].attach(servosPins[5], 800, 2200);
  delay(40);

  servos[6].attach(servosPins[6], 800, 2200);
  delay(40);

  servos[7].attach(servosPins[7], 800, 2200);
  delay(40);

  servos[8].attach(servosPins[8], 800, 2200);
  delay(40);

  servos[9].attach(servosPins[9], 800, 2200);
  delay(40);

  servos[10].attach(servosPins[10], 800, 2200);
  delay(40);

  servos[11].attach(servosPins[11], 800, 2200);
  delay(40);

  for (int i = 0; i < 12; i++) {
    servos[i].writeMicroseconds(initServosValues[i]);
  }

  // A little timeout before it starts moving
  delay(3000);
}

void loop() {
  if (currentAngle < 0) currentAngle += 360;
  if (currentAngle > 359) currentAngle -= 360;

  Walk();

  delay(15);
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

    servos[i * 2].writeMicroseconds(initServosValues[i * 2] + int(Knee)); // update knee  servos 1,3,5
    servos[i * 2 + 1].writeMicroseconds(initServosValues[i * 2 + 1] + int(Hip)); // update hip servos 1,3,5
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

    servos[i * 2].writeMicroseconds(initServosValues[i * 2] + int(Knee)); // update knee  servos 2,4,6
    servos[i * 2 + 1].writeMicroseconds(initServosValues[i * 2 + 1] + int(Hip)); // update hip servos 2,4,6
  }

  Step += currentSpeed;
  if (Step > 359) Step -= 360;
  if (Step < 0) Step += 360;
}


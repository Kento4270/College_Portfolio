#pragma once
#include "vex.h"
#define D_PI (3.14)

void PIDFwdEnc(double desireddistance) {
  const double kP = 1;
  const double kI = 0;
  const double kD = 1;
  const double wheeldia = 3.25; //Isaac robot
  double Avg = 0;
  double Dis = 0;
  double motorvoltage = 0;
  double circumference = 0;
  double degree = 0;
  double eDot = 0;
  double eInt = 0;
  double error = 0;
  double prevError = desireddistance;
  
  Brain.Timer.reset();
  while (1) {
    Avg = (EncoderLeft.position(deg) + (-EncoderRight.position(deg))) / 2;
    Dis = wheeldia * D_PI * (Avg / 360);
    error = desireddistance - Dis;
    eDot = (error - prevError);
    eInt = eInt + error;
    motorvoltage = kP * error + kI * eInt + kD * eDot;
    cout << "Distance " << Dis << endl;

    if (Gyro.acceleration(xaxis) <= 0.45 && Gyro.acceleration(xaxis) >= -0.45) {
      if (Brain.Timer.value() > 1) {
        return;
      }
    } else {
      Brain.Timer.reset();
    }

    LeftDrive.spin(fwd, motorvoltage, volt);
    RightDrive.spin(fwd, motorvoltage, volt);
    cout << Dis << endl;
    prevError = error;
    task::sleep(20);
  }
  return;
}
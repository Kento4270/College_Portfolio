#pragma once
#include "vex.h"
#define D_PI (3.14)

void PIDTurnGyro(int desireddegree) {
  const double kP = 0.5;
  const double kI = 0;
  const double kD = 0.1;
  double motorvoltage = 0;
  double eDot = 0;
  double eInt = 0;
  double error = 0;
  double prevError = -desireddegree;

  Brain.Timer.reset();
  while (1) {
    cout << error << endl;
    error = (-desireddegree) + (Gyro.heading(deg));
    if (fabs(error) <= 180) {
      error = -(error);
    }
    eDot = (error - prevError);
    eInt = eInt + error;
    motorvoltage = kP * error + kI * eInt + kD * eDot;

    if (Gyro.acceleration(yaxis) <= 0.3 && Gyro.acceleration(yaxis) >= -0.3) {
      if (Brain.Timer.value() > 0.7) {
        return;
      }
    } else {
      Brain.Timer.reset();
    }
    LeftDrive.spin(fwd, motorvoltage, volt);
    RightDrive.spin(fwd, -motorvoltage, volt);
    prevError = error;
    task::sleep(20);
  }
  return;
}
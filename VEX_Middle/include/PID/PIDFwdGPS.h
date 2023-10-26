#pragma once
#include "vex.h"
#include "PrintPosition.h"

void PIDFwdGPS(int desireddistance) {
  const double kP = 0.7;
  const double kI = 0;
  const double kD = 0;
  double motorvoltage = 0;
  double eDot = 0;
  double eInt = 0;
  double error = 0;
  double prevError = 0;

  PrintPosition();
  Brain.Timer.reset();
  cout << "yo" << endl;

  while (1) {
    error = -(desireddistance) + GPS.xPosition(mm);
    eDot = (error - prevError);
    eInt = eInt + error;
    motorvoltage = kP * error + kI * eInt + kD * eDot;
    cout << motorvoltage << endl;
    LeftDrive.spin(fwd, motorvoltage, volt);
    RightDrive.spin(fwd, motorvoltage, volt);

    if (motorvoltage <= 0.3 && motorvoltage >= -0.3) {
      if (Brain.Timer.value() > 3) {
        cout << "no" << endl;
        return;
      }
    } else {
      Brain.Timer.reset();
    }

    if (motorvoltage > 12) {
      Controller.Screen.newLine();
      Controller.Screen.print("OverVolt!");
    }
    prevError = error;
    task::sleep(20);
  }
  return;
}
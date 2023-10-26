#pragma once
#include "vex.h"

void DriveToggleFunc(int* pH_Counter) {
  if(Controller.ButtonUp.pressing()) {
    if (*pH_Counter == 0) {
      *pH_Counter = 1;
      wait(150, msec);
    } else {
      *pH_Counter = 0;
      wait(150, msec);
    }
  }
  return;
}

void DriveSelFunc(int* pH_Counter, double* pRightMotors_axis, double* pLeftMotors_axis) {
  if (*pH_Counter == 0 && *pRightMotors_axis == 0 && *pLeftMotors_axis == 0) {
    RightDrive.stop(coast);
    LeftDrive.stop(coast);
  } else if (*pH_Counter == 0) {
    RightDrive.spin(fwd, *pRightMotors_axis * 1, pct);
    LeftDrive.spin(fwd, *pLeftMotors_axis * 1, pct);
  } else if (*pRightMotors_axis == 0 && *pLeftMotors_axis == 0) {
    RightDrive.stop(hold);
    LeftDrive.stop(hold);
  } else {
    RightDrive.spin(fwd, *pRightMotors_axis * 0.6, pct);
    LeftDrive.spin(fwd, *pLeftMotors_axis * 0.6, pct);
  }
  return;
}
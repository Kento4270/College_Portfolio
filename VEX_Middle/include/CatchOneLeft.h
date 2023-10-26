#pragma once
#include "vex.h"
#include "PID/PIDFwdEnc.h"
#include "PID/PIDTurnGyro.h"

void CatchOneLeft(void) {
  BackClaw.set(false);
  FrontClaw.set(false);
  Lift.stop(hold);

  RightDrive.spin(fwd, 600, rpm);
  LeftDrive.spin(fwd, 600, rpm);
  while (FrontSW.value() == 1) {
    wait(20, msec);
  }
  FrontClaw.set(true);
  RightDrive.spin(reverse, 600, rpm);
  LeftDrive.spin(reverse, 600, rpm);
  wait(1, sec);
  RightDrive.spin(reverse, 200, rpm);
  LeftDrive.spin(reverse, 200, rpm);
  wait(2, sec);
  RightDrive.stop(brake);
  LeftDrive.stop(brake);
 // PIDFwdEnc(.2);
  Lift.spin(fwd, 100, rpm);
  wait(1.5, sec);
  Lift.stop(hold);
  Gyro.setHeading(0, deg);
  PIDTurnGyro(270);
  RightDrive.spin(reverse, 200, rpm);
  LeftDrive.spin(reverse, 200, rpm);
  while (BackSW.value() == 1) {
    wait(20, msec);
  }
  RightDrive.stop(brake);
  LeftDrive.stop(brake);
  BackClaw.set(true);

  RightDrive.spin(fwd, 100, rpm);
  LeftDrive.spin(fwd, 100, rpm);
  Intake.spin(fwd, 600, rpm);
  wait(3, sec);
  RightDrive.stop(brake);
  LeftDrive.stop(brake);
  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);
  BackClaw.set(false);
  Lift.stop(hold);
}
#pragma once
#include "vex.h"
#include "PID/PIDFwdEnc.h"
#include "PID/PIDTurnGyro.h"

void CatchOneAuton(void) {
  int i = 0;
  Lift.stop(hold);
  FrontClaw.set(false);

  RightDrive.spin(fwd, 600, rpm);
  LeftDrive.spin(fwd, 600, rpm);
  while (FrontSW.value() == 1) {
    wait(20, msec);
  }
  FrontClaw.set(true);
  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);
  PIDFwdEnc(-32);
  PIDTurnGyro(270);
  RightDrive.spin(reverse, 200, rpm);
  LeftDrive.spin(reverse, 200, rpm);
  while (BackSW.value() == 1) {
    wait(20, msec);
  }
  BackClaw.set(true);
  PIDTurnGyro(180);
  Lift.spin(fwd, 100, rpm);
  wait(1.5, sec);
  Lift.stop(hold);

  RightDrive.spin(fwd, 100, rpm);
  LeftDrive.spin(fwd, 100, rpm);
  Intake.spin(fwd, 600, rpm);
  wait(3, sec);
  RightDrive.stop(brake);
  LeftDrive.stop(brake);
  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);


  PIDFwdEnc(-18);

    RightDrive.stop(brake);
  LeftDrive.stop(brake);
  wait(500,msec);
  RightDrive.spin(fwd,100, rpm);
  LeftDrive.spin(fwd, 100, rpm);
  wait(1.6, sec);
  RightDrive.stop(brake);
  LeftDrive.stop(brake);
  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);
  BackClaw.set(false);
  Lift.stop(hold);
  return;
}
#pragma once
#include "vex.h"
#include "PID/PIDTurnGyro.h"
#include "PID/PIDFwdEnc.h"

void CatchTwoAuton(void) {
  double dis = 0;
  double avg = 0;

  BackClaw.set(false);
  FrontClaw.set(false);
  Lift.stop(hold);
  
  RightDrive.spin(reverse, 600, rpm);
  LeftDrive.spin(reverse, 600, rpm);

  while (BackSW.value() == 1) {
    wait(20, msec);
  }

  BackClaw.set(true);

  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);

  /*RightDrive.spin(fwd, 600, rpm);
  LeftDrive.spin(fwd, 600, rpm);

  while (dis < 12) {
    avg = (EncoderLeft.position(deg) + (-EncoderRight.position(deg))) / 2;
    dis = 3.25 * 3.14 * (avg / 360);
    wait(20, msec);
  }*/

  PIDFwdEnc(14);

  RightDrive.stop(brake);
  LeftDrive.stop(brake);
  Gyro.setHeading(0, deg);
  PIDTurnGyro(124);
  RightDrive.spin(fwd, 600, rpm);
  LeftDrive.spin(fwd, 600, rpm);

  while (FrontSW.value() == 1) {
    wait(20, msec);
  }

  FrontClaw.set(true);

  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);
  PIDFwdEnc(-24);
  RightDrive.stop(brake);
  LeftDrive.stop(brake);


  return;
}
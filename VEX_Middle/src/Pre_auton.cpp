#include "vex.h"

void pre_auton(void) {
  FrontClaw.set(true);
  vexcodeInit();
  Controller.Screen.newLine();
  Controller.Screen.print("Calibrating...");

  GPS.calibrate();
  while (GPS.isCalibrating()) {
    wait(100, msec);
  }
  Gyro.calibrate();
  while (Gyro.isCalibrating()) {
    wait(100, msec);
  }
  EncoderLeft.setPosition(0, deg);
  EncoderRight.setPosition(0, deg);
  cout << "GPS.xPosition: " << GPS.xPosition(mm) << "\n";
  cout << "GPS.orientation: " << GPS.orientation(yaw, deg) << "\n";
  cout << "EncoderLeft.position: " << EncoderLeft.position(deg) << "\n";
  cout << "EncoderRight.position: " << EncoderRight.position(deg) << "\n";
  cout << "Gyro.heading: " << Gyro.heading(deg) << "\n";
  Controller.Screen.clearLine(14);
  Controller.Screen.print("Done!");
  return;
}
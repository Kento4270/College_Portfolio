#pragma once
#include "vex.h"

void GyroTester(void) {
  while (1) {
    cout << "x: " << Gyro.acceleration(xaxis) << endl;
    cout << "y: " << Gyro.acceleration(yaxis) << endl;
    cout << "z: " << Gyro.acceleration(zaxis) << endl;
    wait(20, msec);
  }
  return;
}
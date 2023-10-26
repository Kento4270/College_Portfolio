#include "vex.h"

void FieldCentric(double* x, double* y) {
  double GyroVal = imu.heading() * M_PI / 180;
  *x = *x * cos(GyroVal) - *y * sin(GyroVal);
  *y = *y * cos(GyroVal) + *x * sin(GyroVal);
}
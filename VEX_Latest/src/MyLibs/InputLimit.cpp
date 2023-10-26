#include "vex.h"

void InputLimit(double* x, double* y) {
  double theta = 0;

  if(1 < sqrt(*x * *x + *y * *y)) {
    getCtrlDeg(*x, *y, &theta);
    *x = sin(theta * M_PI / 180);
    *y = cos(theta * M_PI / 180);
  }
}
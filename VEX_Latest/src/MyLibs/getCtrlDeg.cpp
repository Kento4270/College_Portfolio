#include "vex.h"

void getCtrlDeg(int x, int y, double* CtrlDeg) {
  if(x == 0 && y >= 0) {
    *CtrlDeg = 0;
  } else if(x >= 0 && y >= 0) {
    *CtrlDeg = 90 - atan(y / x) * 180 / D_PI;
  } else if (x >= 0 && y <= 0) {
    *CtrlDeg = 90 - atan(y / x) * 180 / D_PI;
  } else if (x <= 0 && y <= 0) {
    *CtrlDeg = 270 - atan(y / x) * 180 / D_PI;
  } else if (x <= 0 && y >= 0) {
    *CtrlDeg = 270 - atan(y / x) * 180 / D_PI;
  } else {
    std::cout << "Get CtrlDeg: THERE IS A BUG!!\n";
  }
}
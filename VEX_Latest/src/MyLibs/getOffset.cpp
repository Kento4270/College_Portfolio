#include "vex.h"

void getOffset(double CtrlDeg, double* Offset) {
  if(imu.heading(deg) < CtrlDeg) {
    *Offset = 360 - CtrlDeg + imu.heading(deg);
  } else if(CtrlDeg < imu.heading(deg)) {
    *Offset = imu.heading(deg) - CtrlDeg;
  } else if(imu.heading(deg) == CtrlDeg) {
    *Offset = 0;
  } else if(std::abs(imu.heading(deg) - CtrlDeg) == 180) {
    *Offset = 180;
  } else {
    std::cout << "Get Offset: THERE IS A BUG!!\n"; //CHANGE THIS AFTER YOU VERIFIED
  }
}
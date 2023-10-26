#include "CatchOneLeft.h"
#include "CatchTwoAutonRight.h"
#include "CatchOneAuton.h"
#include "PID/PIDFwdEnc.h"
#include "vex.h"
#include "GyroTester.h"


void autonomous(void) {
  //  if (selector.value(pct) >= 0 && selector.value(pct) <= 33) {
  //    CatchTwoAuton();
  //  } else if (selector.value(pct) >= 34 && selector.value(pct) <= 66) {
  //    CatchOneAuton();
  //  } else {
  //    CatchOneLeft();
  //  }
  PIDFwdEnc(24);
  return;
}
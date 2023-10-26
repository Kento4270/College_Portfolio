#pragma once
#include "vex.h"

void LiftFunc(void) {
  if(Controller.ButtonR1.pressing()) {
    Lift.spin(fwd, 100, rpm);
  } else if(Controller.ButtonR2.pressing()) {
    Lift.spin(reverse, 100, rpm);
  } else {
    Lift.stop(hold);
  }
  return;
}
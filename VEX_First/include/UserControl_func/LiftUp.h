#ifndef INCLUDE_LIFT_UP
#define INCLUDE_LIFT_UP

#include "Libralies/robot-config.h"

using vex::pct;
using vex::reverse;
using vex::rpm;
using vex::hold;

void LiftUp() {
  if (LiftPot.value(pct) > 44) {
    Lift.spin(reverse, 100, rpm);
  } else {
    Lift.stop(hold);
  }
}

#endif
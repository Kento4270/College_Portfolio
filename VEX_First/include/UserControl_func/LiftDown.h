#ifndef INCLUDE_LIFT_DOWN
#define INCLUDE_LIFT_DOWN

#include "Libralies/robot-config.h"

using vex::pct;
using vex::fwd;
using vex::rpm;
using vex::hold;

void LiftDown() {
  if (LiftPot.value(pct) < 72) {
    Lift.spin(fwd, 100, rpm);
  } else {
    Lift.stop(hold);
  }
}

#endif
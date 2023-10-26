#ifndef INCLUDE_GRABBER_TOGGLE_FUNC
#define INCLUDE_GRABBER_TOGGLE_FUNC

#include "Libralies/robot-config.h"

using vex::fwd;
using vex::rpm;
using vex::reverse;
using vex::deg;
using vex::pct;
using vex::hold;


void GrabberToggle(int *Counter) {
  Brain.Timer.reset();

  while (*Counter == 0) {
    Grabber.spin(fwd, 100, rpm);
    if (Grabber.isSpinning() == false && Brain.Timer.value() > 0.7) {
      Grabber.rotateFor(reverse, 100, deg, 100, rpm);
      return;
    }
    if (GrabberPot.value(pct) >= 77) {
      *Counter = 1;
      Grabber.stop(hold);
      return;
    }
  }
  while (*Counter == 1) {
    Grabber.spin(reverse, 100, rpm);
    if (Grabber.isSpinning() == false && Brain.Timer.value() > 0.7) {
      Grabber.rotateFor(fwd, 100, deg, 100, rpm);
      return;
    }
    if (GrabberPot.value(pct) <= 6) {
      *Counter = 0;
      Grabber.stop(hold);
      return;
    }
  }
}

#endif
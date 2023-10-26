#pragma once
#include "vex.h"

void IntakeFunc(int* pF_Counter, int* pR_Counter) {
  if(Controller.ButtonA.pressing()) {
    if (*pF_Counter == 0) {
      Intake.spin(fwd, 600, rpm);
      *pF_Counter = 1;
      wait(150, msec);
    } else {
      Intake.stop(coast);
      *pF_Counter = 0;
      wait(150, msec);
    }
    return;
  }

  if(Controller.ButtonB.pressing()) {
    if (*pR_Counter == 0) {
      Intake.spin(reverse, 500, rpm);
      *pR_Counter = 1;
      wait(150, msec);
    } else {
      Intake.stop(coast);
      *pR_Counter = 0;
      wait(150, msec);
    }
  }
  return;
}
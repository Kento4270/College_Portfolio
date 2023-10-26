#include "Libralies/vex.h"
#include "UserControl_func/GrabberToggleFunc.h"
#include "UserControl_func/BackPistonToggle.h"
#include "UserControl_func/TopPistonToggle.h"
#include "UserControl_func/LiftUp.h"
#include "UserControl_func/LiftDown.h"

using vex::pct;
using vex::reverse;
using vex::rpm;
using vex::hold;
using vex::fwd;
using vex::msec;
using vex::coast;
using vex::deg;

void usercontrol(void) {
  double X_axis = 0;
  double Y_axis = 0;

  double const DeadZone = 0.05;

  int Count = 0;

  while (1) {
    Controller.ButtonX.pressed(TopPistonToggle);
    Controller.ButtonB.pressed(BackPistonToggle);

    




    if (Controller.ButtonY.pressing()) {
      GrabberToggle(&Count);
    }

    if (Controller.ButtonR1.pressing()) {
      LiftUp();
    }

    if (Controller.ButtonR2.pressing()) {
      LiftDown();
    }

    if (!Controller.ButtonR1.pressing() && !Controller.ButtonR2.pressing()) {
      Lift.stop(hold);
    }

    //Deadzone statement for RightDrive
    if(abs(Controller.Axis1.value()) >= DeadZone){
      Y_axis = Controller.Axis1.value();
    } else {
      Y_axis = 0;
    }

    //Deadzone statement for LeftDrive
    if(abs(Controller.Axis3.value()) >= DeadZone){
      X_axis = Controller.Axis3.value();
    } else {
      X_axis = 0;
    }

    //Arcade drive
    LeftDrive.spin(fwd, X_axis + Y_axis * 0.3, pct);
    RightDrive.spin(fwd, X_axis - Y_axis * 0.3, pct);
  //startRotateFor is just gonna prepare for rotating, once the other started moving by using rotateFor it also gonna move, at the exact same time.
    wait(20, msec);
  }
  return;
}
#include "Libralies/vex.h"
#include "main_func/UserControl.h"
#include "main_func/Pre_auton.h"
#include "main_func/Autonomous.h"


using vex::competition;
using vex::msec;
using vex::coast; 


competition Competition;

int main(void) {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
    //Emergency stop, if down and key pressed at the same time it kills all functions are working.
    if (Controller.ButtonDown.pressing() == true) {
      while (1) {
      RightDrive.stop(coast);
      LeftDrive.stop(coast);
      Grabber.stop(coast);
      Lift.stop(coast);
      }
    }
  }
  return 0;
}


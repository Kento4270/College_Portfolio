#include "Libralies/vex.h"

using vex::fwd;
using vex::rpm;
using vex::brake;
using vex::reverse;
using vex::msec;
using vex::sec;

void autonomous(void) {
  
}

/*void autonomous(void) {
  Brain.Timer.reset();
  while (1) {
    LeftDrive.spin(reverse, 600, rpm);
    RightDrive.spin(reverse, 600, rpm);

    if (BackSwitch.value() == false) {
      LeftDrive.spin(fwd, 600, rpm);
      RightDrive.spin(fwd, 600, rpm);
      wait(3, sec);
      LeftDrive.stop(brake);
      RightDrive.stop(brake);
      return;
    }
    if (Brain.Timer.value() > 4.0) {
      LeftDrive.stop(brake);
      RightDrive.stop(brake);
    }
  wait(20, msec);
  }
  return;
}*/

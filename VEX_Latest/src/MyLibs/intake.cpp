#include "vex.h"

int intakeCounter = 0;

// void intake() {
//   if(Controller.ButtonA.pressing()) {
//     if(intakeCounter == 0) {
//       Intake.spin(fwd, null, rpm);
//       intakeCounter = 1;
//       wait(150, msec);
//     } else if(intakeCounter == 1) {
//       Intake.stop(coast);
//       intakeCounter = 0;
//       wait(150, msec);
//     }
//   }
// }
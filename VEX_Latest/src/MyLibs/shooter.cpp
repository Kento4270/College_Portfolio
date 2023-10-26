#include "vex.h"

int shooterCounter = 0;

// void shooter() {
//   if(Controller.ButtonR1.pressing()) {
//     if(shooterCounter == 0) {
//       FlyR.spin(fwd, null, rpm);
//       FlyL.spin(fwd, null, rpm);
//       shooterCounter = 1;
//       wait(150, msec);
//     } else if(shooterCounter == 1) {
//       FlyR.stop(coast);
//       FlyL.stop(coast);
//       shooterCounter = 0;
//       wait(150, msec);
//     }
//   }
// }
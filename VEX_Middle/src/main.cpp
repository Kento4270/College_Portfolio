#include "vex.h"

void autonomous(void);
void pre_auton(void);
void usercontrol(void);

competition Competition;

int main() {  
  pre_auton();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  while (true) {
    wait(20, msec);
  }
  return 0;
}

#include "vex.h"

void usercontrol(void) {
  double x = 0;
  double y = 0;
  double z = 0;


  while (1) {
    x = Controller.Axis3.value() * 100 / 127; //127 ~ -127
    y = Controller.Axis4.value() * 100 / 127;
    z = Controller.Axis1.value() * 100 / 127;
    InputLimit(&x, &y);
    FieldCentric(&x, &y);
    roller();
    intake();
    shooter();
    std::cout << x << "\n";
    std::cout << y << "\n";
    // LeftFront.spin(fwd, x + y + z, pct);
    // RightFront.spin(fwd, -x + y + z, pct);
    // RightBack.spin(fwd, x + y + z, pct);
    // LeftBack.spin(fwd, -x + y + z, pct);
    wait(20, msec);
  }
}
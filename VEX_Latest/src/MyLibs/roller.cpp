#include "vex.h"

void ColorDetection_B() {
  if(Optic.color() == red) {
    Roller.spin(fwd, 600, rpm);
  } else if(Optic.color() == blue) {
    Roller.stop(hold);
  }
}

void ColorDetection_R(){
  if(Optic.color() == blue) {
    Roller.spin(fwd, 600, rpm);
  } else if(Optic.color() == red) {
    Roller.stop(hold);
  }
}

void roller() {
  if(Controller.ButtonL1.pressing()) {
    ColorDetection_R();
  } else if(Controller.ButtonL2.pressing()) {
    ColorDetection_B();
  }
}
#include "Libralies/vex.h"

using vex::reverse;
using vex::coast;
using vex::rpm;
using vex::pct;

void pre_auton(void) {
  
  vexcodeInit();
  TopPiston.set(false);
  BackPiston.set(false);
  return;
}
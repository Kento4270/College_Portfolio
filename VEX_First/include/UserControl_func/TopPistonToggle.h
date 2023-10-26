#ifndef INCLUDE_TOP_PISTON_TOGGLEFILE
#define INCLUDE_TOP_PISTON_TOGGLEFILE

#include "Libralies/robot-config.h"

void TopPistonToggle() {
  TopPiston.set(!TopPiston.value());
  return;
}

#endif 
#ifndef INCLUDE_BACK_PISTON_TOGGLE
#define INCLUDE_BACK_PISTON_TOGGLE

#include "Libralies/robot-config.h"

void BackPistonToggle() {
  BackPiston.set(!TopPiston.value());
  return;
}

#endif
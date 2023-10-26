#pragma once
#include "vex.h"

void FrontToggle(void) {
  FrontClaw.set(!FrontClaw.value());
  return;
}
#pragma once
#include "vex.h"

void BackToggle(void) {
  BackClaw.set(!BackClaw.value());
  return;
}
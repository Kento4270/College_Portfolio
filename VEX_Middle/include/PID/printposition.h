#pragma once
#include "vex.h"

void PrintPosition() {
  cout << "X: " << (int)GPS.xPosition(mm) << "\n";
  cout << "Y: " << (int)GPS.yPosition(mm) << "\n";
  cout << "Deg: " << (int)GPS.orientation(yaw, deg) << "\n";
  cout << "\n";
  return;
}
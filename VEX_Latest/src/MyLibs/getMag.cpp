#include "vex.h"

void getMag(int x, int y, double* Mag) {
  *Mag = x * x + y * y;
  *Mag = sqrt(*Mag) / 127 * 100;
  if(*Mag > 100) {
    *Mag = 100;
  }
}
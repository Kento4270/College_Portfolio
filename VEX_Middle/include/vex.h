#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

using vex::task, vex::msec, vex::rpm, vex::fwd, vex::pct, vex::hold, vex::reverse, vex::brake, std::cout, std::endl,
vex::mm, vex::ratio18_1, vex::PORT11, vex::PORT9, vex::PORT7, vex::PORT3, vex::PORT2, vex::PORT21, vex::PORT8, vex::PORT6, 
vex::PORT1, vex::brain, vex::motor, vex::controller, vex::motor_group, vex::gps, vex::encoder, vex::ratio6_1, vex::potV2, 
vex::digital_out, vex::ratio36_1, vex::competition, vex::volt, vex::yaw, vex::deg, vex::coast, vex::triport, vex::PORT20,
vex::inertial, vex::PORT14, vex::PORT13, vex::digital_in, vex::sec, vex::PORT15, vex::PORT5, vex::xaxis, vex::PORT18,
vex::yaxis, vex::zaxis;
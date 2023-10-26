#include "vex.h"
#include "UCHeader/BackToggle.h"
#include "UCHeader/FrontToggle.h"
#include "UCHeader/Lift.h"
#include "UCHeader/Deadzone.h"
#include "UCHeader/Intake.h"
#include "UCHeader/DriveSelFunc.h"

void usercontrol(void) {
  int F_Counter = 0;
  int R_Counter = 0;
  int H_Counter = 0;
  const double DeadZone = 0.05;
  double LeftMotors_axis = 0;
  double RightMotors_axis = 0;

  Controller.ButtonL1.pressed(BackToggle);
  Controller.ButtonL2.pressed(FrontToggle);
  while (1) {
    IntakeFunc(&F_Counter, &R_Counter);

    LiftFunc();

    DeadzoneFunc(&DeadZone, &RightMotors_axis, &LeftMotors_axis);

    DriveToggleFunc(&H_Counter);

    DriveSelFunc(&H_Counter, &RightMotors_axis, &LeftMotors_axis);
    
    wait(20, msec);
  }
  return;
}
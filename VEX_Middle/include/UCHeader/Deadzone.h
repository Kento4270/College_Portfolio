#pragma once
#include "vex.h"

void DeadzoneFunc(const double* pDeadZone, double* pRightMotors_axis, double* pLeftMotors_axis) {
  if(abs(Controller.Axis2.value()) >= *pDeadZone){
    *pRightMotors_axis = Controller.Axis2.value();
  } else {
    *pRightMotors_axis = 0;
  }

  if(abs(Controller.Axis3.value()) >= *pDeadZone){
    *pLeftMotors_axis = Controller.Axis3.value();
  } else {
    *pLeftMotors_axis = 0;
  }
  return;
}
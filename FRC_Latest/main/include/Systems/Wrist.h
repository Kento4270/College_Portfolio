// #pragma once

// #include "Basic.h"
// #include "Intake.h"
// #include "Elevator.h"

// class Wrist {

// public:

//   //multithread this function to execute
//   static void run();

// private:

//   enum class Pos {
//     Up, Down
//   };

//   static void SetPosition(Intake::state kState, Elevator::Pos kPos, Elevator::Obj kObj);

//   //returns the value which was 0 offsetted and converted to the range of 0 - 360
//   //the original range was 0 - 1
//   static double getWristDeg(double Raw_WristDeg);
  
//   //consts for getWristDeg();
//   static float const EncZero, EncMax, Deg_Down_Cone, Deg_Down_Cube, Deg_Up, Deg_Mid_Cone, Deg_High_Cone, Deg_LoadingStation;
// };

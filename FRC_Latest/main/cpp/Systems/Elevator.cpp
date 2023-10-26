// #include "Systems/Elevator.h"
// #include "Config.h"
// #include "Math.h"

// const float Elevator::kP = 0.0003f, Elevator::kD = 0.00005f, Elevator::kG = 0.02f, Elevator::EncMax = 16291, 
// Elevator::Desired_Point_Low_Cone = 400, Elevator::Desired_Point_Mid_Cone = 10930, Elevator::Desired_Point_High_Cone = 16248,
// Elevator::Desired_Point_Low_Cube = 400, Elevator::Desired_Point_Mid_Cube = 6979, Elevator::Desired_Point_High_Cube = 16248;

// Elevator::Pos Elevator::kPos = Elevator::Pos::Low;
// Elevator::Obj Elevator::kObj = Elevator::Obj::Cone;

// void Elevator::run() {
//   if (Buttons.GetRawButton(4)) {
//     kObj = Obj::Cone;
//     kPos = Pos::High;
//   } else if (Buttons.GetRawButton(7)) {
//     kObj = Obj::Cone;
//     kPos = Pos::Mid;
//   } else if (Buttons.GetRawButton(10)) {
//     kObj = Obj::Cone;
//     kPos = Pos::Low;
//   } else if (Buttons.GetRawButton(5)) {
//     kObj = Obj::Cube;
//     kPos = Pos::High;
//   } else if (Buttons.GetRawButton(8)) {
//     kObj = Obj::Cube;
//     kPos = Pos::Mid;
//   } else if (Buttons.GetRawButton(11)) {
//     kObj = Obj::Cube;
//     kPos = Pos::Low;
//   }
//   SetPosition(kPos, kObj);
// }

// void Elevator::SetPosition(Pos kPos, Obj kObj) {
//   double error = 0;
//   static double eprev = 0;
//   if (kObj == Obj::Cone) {
//     if (kPos == Pos::Low)
//       error = Desired_Point_Low_Cone - Encoder::Elevator.Get();
//     else if (kPos == Pos::Mid)
//       error = Desired_Point_Mid_Cone - Encoder::Elevator.Get();

//     else if (kPos == Pos::High)
//       error = Desired_Point_High_Cone - Encoder::Elevator.Get();

//   } else if (kObj == Obj::Cube) {
//     if (kPos == Pos::Low)
//       error = Desired_Point_Low_Cube - Encoder::Elevator.Get();
//     else if (kPos == Pos::Mid)
//       error = Desired_Point_Mid_Cube - Encoder::Elevator.Get();
//     else if (kPos == Pos::High)
//       error = Desired_Point_High_Cube - Encoder::Elevator.Get();
//   }
//   double Power = Math::getPID(error, kP, kD, eprev);
//   Power = std::clamp(Power, (double)(-1 + kG), (double)(1 - kG));
//   // Power = std::clamp(Power, -0.3, 0.3);

//   Motor::Elevator.Set(Power + kG);
//   // frc::SmartDashboard::PutNumber("error of elevator", error);
//   frc::SmartDashboard::PutNumber("Power", Power);
//   frc::SmartDashboard::PutNumber("Elevator value", Encoder::Elevator.Get());
// }

// Elevator::Pos Elevator::getPos() {
//   return kPos;
// }

// Elevator::Obj Elevator::getObj() {
//   return kObj;
// }
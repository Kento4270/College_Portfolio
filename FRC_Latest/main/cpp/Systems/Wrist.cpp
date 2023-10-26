// #include "Systems/Wrist.h"
// #include "Systems/Intake.h"
// #include "Systems/Elevator.h"
// #include "Config.h"
// #include "Math.h"

// float const Wrist::EncZero = 0.92, Wrist::EncMax = 1, Wrist::Deg_Down_Cube = 280, Wrist::Deg_Up = 10,
// Wrist::Deg_Down_Cone = 291, Wrist::Deg_Mid_Cone = 200, Wrist::Deg_High_Cone = 294, Wrist::Deg_LoadingStation = 350; //297

// void Wrist::run() {

//   Pos kPos = Pos::Down;
//   int Timer = 400;
//   // if (Timer >= 400) {
//   //   if (Buttons.GetRawButton(5) && kPos == Pos::Down) {
//   //     kPos = Pos::Up;
//   //     Timer = 0;
//   //   } else if (Buttons.GetRawButton(5) && kPos == Pos::Up) {
//   //     kPos = Pos::Down;
//   //     Timer = 0;
//   //   }
//   // }

//   SetPosition(Intake::getState(), Elevator::getPos(), Elevator::getObj());
//   // Timer += 20;
//   // frc::SmartDashboard::PutNumber("WristEncoderVal", Encoder::Wrist.GetAbsolutePosition());
// }

// void Wrist::SetPosition(Intake::state kState, Elevator::Pos kPos, Elevator::Obj kObj) {
//   double Power = 0;
//   static double eprev = 0;
//   double error = 0;

//   double Deg = 360 - getWristDeg(Encoder::Wrist.GetAbsolutePosition()); //360 - is to flip the degree
//   double const kG = 0.015 * std::sin(Deg * M_PI / 180);



//   if (kObj == Elevator::Obj::Cone && kPos == Elevator::Pos::High) {
//     // if (kPos == Elevator::Pos::High) {
//     //   error = Math::getShortestDis(Deg, Deg_High_Cone);
//     //   Power = Math::getPID(error, 0.01, 0, eprev);
//     error = Math::getShortestDis(Deg, Deg_High_Cone);
//     Power = Math::getPID(error, 0.01, 0, eprev);
//     // } else if (kPos == Elevator::Pos::Mid) {
//     //   error = Math::getShortestDis(Deg, Deg_Mid_Cone);
//     //   Power = Math::getPID(error, 0.01, 0, eprev);
//     // }
//   } else if (kState == Intake::state::Off) {
//     error = Math::getShortestDis(Deg, Deg_Up);
//     Power = Math::getNewPID(error, 0.003, 2);
//   } else if (kState == Intake::state::Intake_Cone) {
//     error = Math::getShortestDis(Deg, Deg_Down_Cone);
//     Power = Math::getPID(error, 0.01, 0, eprev);
//   } else if (kState == Intake::state::Intake_Cube) {
//     error = Math::getShortestDis(Deg, Deg_High_Cone);
//     Power = Math::getPID(error, 0.01, 0, eprev);
//   } else if (kState == Intake::state::Loadng_station) {
//     error = Math::getShortestDis(Deg, Deg_LoadingStation);
//     Power = Math::getPID(error, 0.01, 0, eprev);
//   }
//   frc::SmartDashboard::PutNumber("Deg", Deg);
//   // frc::SmartDashboard::PutNumber("State", (int)kPos);
//   frc::SmartDashboard::PutNumber("Error", error);
//   frc::SmartDashboard::PutNumber("Power", Power);
//   // frc::SmartDashboard::PutNumber("WristEncoderVal", Encoder::Wrist.GetAbsolutePosition());
//   // Power = std::clamp(Power,-0.3,0.3);
//   Power = std::clamp(Power, (double)(-1 + kG), (double)(1 - kG));
//   Motor::Wrist.Set(Power + kG);
// }

// double Wrist::getWristDeg(double Raw_WristDeg) {
//   return fmod(Raw_WristDeg - (double)EncZero + (double)EncMax, (double)EncMax) * 360;
// }
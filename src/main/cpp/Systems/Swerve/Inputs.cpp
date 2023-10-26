#include "Systems/Inputs.h"
#include "Basic.h"
#include "Config.h"

std::array<double, 4> Inputs::Axis = {}, Inputs::WheelDeg = {};
double Inputs::LDeg = 0, Inputs::LMag = 0, Inputs::Heading = 0, Inputs::A = 0, Inputs::X = 0, Inputs::Y = 0, Inputs::B = 0, Inputs::Circle = 0, Inputs::Plus = 0, Inputs::Minus = 0, Inputs::Square = 0, Inputs::Home = 0, Inputs::R = 0, Inputs::RT = 0, Inputs::L = 0, Inputs::LT = 0;
bool Inputs::isIMUreset = false;

void Inputs::run() {
  if (frc::RobotState::IsTeleop()) {
    // Inputs::getHeading();
    // Inputs::getWheelDeg();
    // Inputs::getAxis();
    // Inputs::getMagDeg();
    Inputs::getButtons();
  }
}

// void Inputs::getHeading() {
//   static bool flag = false;
//   static double InitialYaw = 0;
//   if (flag == false) {
//     // frc::SmartDashboard::PutNumber("ehe", true);
//     flag = true;
//     InitialYaw = 180 + Math::getInvertedAxis(navx.GetYaw()); //The robot is looking at nodes. 180 deg off
//   } else if (Con.GetRawButton(14)) {
//     isIMUreset = true;
//     InitialYaw = Math::getInvertedAxis(navx.GetYaw());
//   }
//   double const Rotation = Math::getInvertedAxis(navx.GetYaw()) - InitialYaw;
//   Heading = Math::getHeading(Rotation);
  // frc::SmartDashboard::PutBoolean("flag", flag);
  // frc::SmartDashboard::PutNumber("InitialYaw", InitialYaw);
  // frc::SmartDashboard::PutNumber("GetYaw", IMU.GetYaw());
  // frc::SmartDashboard::PutNumber("Heading", Heading);
// }

// void Inputs::getWheelDeg() {
//   WheelDeg[Swerve::WheelType::FR] = fmod(Enc::FR.GetAbsolutePosition() - Const::EncZero[Swerve::WheelType::FR] + Const::EncMax, Const::EncMax) / Const::EncMax * 360;
//   WheelDeg[Swerve::WheelType::FL] = fmod(Enc::FL.GetAbsolutePosition() - Const::EncZero[Swerve::WheelType::FL] + Const::EncMax, Const::EncMax) / Const::EncMax * 360;
//   WheelDeg[Swerve::WheelType::BR] = fmod(Enc::BR.GetAbsolutePosition() - Const::EncZero[Swerve::WheelType::BR] + Const::EncMax, Const::EncMax) / Const::EncMax * 360;
//   WheelDeg[Swerve::WheelType::BL] = fmod(Enc::BL.GetAbsolutePosition() - Const::EncZero[Swerve::WheelType::BL] + Const::EncMax, Const::EncMax) / Const::EncMax * 360;
// }

// void Inputs::getAxis() {
//   Axis[AxisType::LY] = Math::getInvertedAxis(Math::setDeadZone(Con.GetRawAxis(1)));
//   Axis[AxisType::LX] = Math::setDeadZone(Con.GetRawAxis(0));
//   Axis[AxisType::RX] = Math::setDeadZone(Con.GetRawAxis(2));
//   Axis[AxisType::RY] = Math::getInvertedAxis(Math::setDeadZone(Con.GetRawAxis(3)));
// }

// void Inputs::getMagDeg() {
//   LMag = Math::getMag(Axis[AxisType::LX], Axis[AxisType::LY]);
//   LDeg = Math::getUnitDeg(Axis[AxisType::LX], Axis[AxisType::LY]);
// }

void Inputs::getButtons() {
  A = Con.GetRawButton(3);
  B = Con.GetRawButton(2);
  X = Con.GetRawButton(4);
  Y = Con.GetRawButton(1);
  Plus = Con.GetRawButton(10);
  Minus = Con.GetRawButton(9);
  Square = Con.GetRawButton(14);
  Home = Con.GetRawButton(13);
  R = Con.GetRawButton(6);
  RT = Con.GetRawButton(8);
  L = Con.GetRawButton(5);
  LT = Con.GetRawButton(7);
}
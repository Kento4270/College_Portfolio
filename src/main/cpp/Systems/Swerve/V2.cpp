#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

float const Swerve::V2::kP = 0.004, Swerve::V2::kD = 0, Swerve::V2::V2MagMultiplier = 0.6, Swerve::V2::HeadingOffAcceptedRange = 2;
const std::array<int, 4> Swerve::V2Deg = {135, 45, 225, 315};

void Swerve::V2::RelativeTurning() {
  static double PreviousHeading = 0, eprev = 0;
  static bool flag = false, PID_flag = false;
  static units::time::second_t Timer = frc::Timer::GetFPGATimestamp();

  if (Axis[(int)AxisType::RX] == 0) {

    if (isIMUreset) {
      // frc::SmartDashboard::PutNumber("IMUreset", true);
      isIMUreset = false;
      PreviousHeading = 0;
    } else if (!(Con.GetPOV() == -1)) {
      PreviousHeading = Con.GetPOV();
    }

    if (frc::Timer::GetFPGATimestamp() > Timer + 0.5_s) {
      if (flag == false) {
        flag = true;
        PreviousHeading = Heading;
      }
      double ErrorDis = Math::getShortestDis(Heading, PreviousHeading);
      // frc::SmartDashboard::PutNumber("ErrorDis", ErrorDis);
      if (std::abs(ErrorDis) > HeadingOffAcceptedRange) {
        Math::InitPreverror(ErrorDis, PID_flag, eprev);
        V2Mag = std::clamp(Math::getPID(ErrorDis, kP, kD, eprev), -getV2MagLimiter(), getV2MagLimiter());
      } else {
        V2Mag = 0;
      }
    } else {
      V2Mag = 0;
    }
  } else {
    flag = false;
    V2Mag = std::clamp(Axis[(int)AxisType::RX] * Swerve::V2::V2MagMultiplier, -getV2MagLimiter(), getV2MagLimiter());
    Timer = frc::Timer::GetFPGATimestamp();
  }
  // frc::SmartDashboard::PutNumber("V2Mag", V2Mag);
  // frc::SmartDashboard::PutNumber("PrevHeading", PreviousHeading);
}

// void Swerve::V2::RelativeTurning() {
//   static double Accum_TurnDeg = 0;

//   double TurnDeg = Axis[(int)AxisType::RX] * 4;
//   Accum_TurnDeg -= TurnDeg;
//   double Desired_Heading = Inputs::getHeading(Accum_TurnDeg) + 180; //offset from inityaw
//   frc::SmartDashboard::PutNumber("Desired_Heading", Desired_Heading);
//   double error = Math::getShortestDis(Heading, Desired_Heading);
//   V2Mag = Math::getPID(error, 0.02);
//   // V2Mag = Math::getNewPID(error, 0.004, 2.3);
// }

double Swerve::V2::convertToUnitCicleDeg(double const Input) {
  return fmod(450 - Input, (double)360);
}

void Swerve::V2::setex_ey() {
  double V1Deg_Unit = 0;
  std::array<double, 4> V2Deg_Unit = {}; //deg based on unit circle for vector

  V1Deg_Unit = convertToUnitCicleDeg(V1Deg);
  for (int i = 0; i < 4; ++i) {
    V2Deg_Unit[i] = convertToUnitCicleDeg(V2Deg[i]);
  }

  V1ex = Math::getex(V1Deg_Unit, V1Mag);
  V1ey = Math::getey(V1Deg_Unit, V1Mag);

  for (int i = 0; i < 4; ++i) {
    V2ex[i] = Math::getex(V2Deg_Unit[i], V2Mag);
    V2ey[i] = Math::getey(V2Deg_Unit[i], V2Mag);
  }

  // frc::SmartDashboard::PutNumber("V1ex", V1ex);
  // frc::SmartDashboard::PutNumber("V2ex", V2ex[(int)WheelType::FR]);
  // frc::SmartDashboard::PutNumber("V1ey", V1ey);
  // frc::SmartDashboard::PutNumber("V2ey", V2ey[(int)WheelType::FR]);
}

double Swerve::V2::getV2MagLimiter() {
  // std::array<double, 4> V3ex, V3ey, result = {};
  // double Min_Limit = 0;
  
  // for (int i = 0; i < 4; ++i) {
  //   V3ex[i] = V1ex + V2ex[i];
  //   V3ey[i] = V1ey + V2ey[i];

  //   result[i] = std::sqrt(Math::getMag(V3ex[i], V3ey[i]) - V1Mag * V1Mag);
  //   if (result[i] < Min_Limit || i == 0)
  //     Min_Limit = result[i];
  // }
  // frc::SmartDashboard::PutNumber("Min_Limit", Min_Limit);
  // frc::SmartDashboard::PutNumber("FR result", result[(int)WheelType::FR]);
  // frc::SmartDashboard::PutNumber("FL result", result[(int)WheelType::FL]);
  // frc::SmartDashboard::PutNumber("BR result", result[(int)WheelType::BR]);
  // frc::SmartDashboard::PutNumber("BL result", result[(int)WheelType::BL]);
  return 1;
}
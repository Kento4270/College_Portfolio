#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

const std::array<float, 4> Swerve::Inputs::EncZero = {279, 5, 156, 286};
float const Swerve::Inputs::EncMax = 360;

void Swerve::Inputs::run() {
  static bool flag = false;
  static double InitialYaw = 0;
  if (flag == false) {
    // frc::SmartDashboard::PutNumber("ehe", true);
    flag = true;
    InitialYaw = 180 + getInvertedAxis(navx.GetYaw()); //The robot is looking at nodes. 180 deg off
  } else if (Con.GetRawButton(14)) {
    isIMUreset = true;
    InitialYaw = getInvertedAxis(navx.GetYaw());
  }
  // frc::SmartDashboard::PutBoolean("flag", flag);
  // frc::SmartDashboard::PutNumber("InitialYaw", InitialYaw);
  // frc::SmartDashboard::PutNumber("GetYaw", IMU.GetYaw());

  WheelDeg[(int)WheelType::FR] = getWheelDeg(Encoder::FR.GetAbsolutePosition(), WheelType::FR);
  WheelDeg[(int)WheelType::FL] = getWheelDeg(Encoder::FL.GetAbsolutePosition(), WheelType::FL);
  WheelDeg[(int)WheelType::BR] = getWheelDeg(Encoder::BR.GetAbsolutePosition(), WheelType::BR);
  WheelDeg[(int)WheelType::BL] = getWheelDeg(Encoder::BL.GetAbsolutePosition(), WheelType::BL);

  // frc::SmartDashboard::PutNumber("Raw WheelDeg BL", Encoder::BL.GetAbsolutePosition());
  // frc::SmartDashboard::PutNumber("Raw WheelDeg BR", Encoder::BR.GetAbsolutePosition());
  // frc::SmartDashboard::PutNumber("Raw WheelDeg FR", Encoder::FR.GetAbsolutePosition());
  // frc::SmartDashboard::PutNumber("Raw WheelDeg FL", Encoder::FL.GetAbsolutePosition());

  double const Rotation = getInvertedAxis(navx.GetYaw()) - InitialYaw;
  Heading = getHeading(Rotation);

  frc::SmartDashboard::PutNumber("Heading", Heading);

  Axis[(int)AxisType::LY] = getInvertedAxis(setDeadZone(Con.GetRawAxis(1)));
  Axis[(int)AxisType::LX] = setDeadZone(Con.GetRawAxis(0));
  Axis[(int)AxisType::RX] = setDeadZone(Con.GetRawAxis(2));
  Axis[(int)AxisType::RY] = getInvertedAxis(setDeadZone(Con.GetRawAxis(3)));
  
  LMag = getMag(Axis[(int)AxisType::LX], Axis[(int)AxisType::LY]);
  LDeg = Math::getUnitDeg(Axis[(int)AxisType::LX], Axis[(int)AxisType::LY]);
}

double Swerve::Inputs::getWheelDeg(double Raw_WheelDeg, WheelType m_EncType) {
  return fmod(Raw_WheelDeg - EncZero[(int)m_EncType] + EncMax, EncMax) / EncMax * 360;
}

float Swerve::Inputs::setDeadZone(float const axis) {
  float a = 0.03;
  if (std::abs(axis) < a) {
    return 0;
    } else {
      if (axis > 0) {
      return (axis - a) / (1 - a);
    } else {
      return (axis + a) / (1 - a);
    }
  }
}

float Swerve::Inputs::getInvertedAxis(double const axis) {
  if (axis != 0) {
    return -axis;
  } else {
    return 0;
  }
}

double Swerve::Inputs::getMag(double const x, double const y) {
  double Mag = sqrt(x * x + y * y);
  return Mag;
}

double Swerve::Inputs::getHeading(double const Rotation) {
  if (Rotation < 0) {
    return fmod(-Rotation, (double)360);
  } else {
    return 360 + fmod(-Rotation, (double)360);
  }
}
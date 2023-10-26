#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

float const Swerve::V3::ekP = 0.55;

void Swerve::V3::setV3Deg() {
  for (int i = 0; i < 4; ++i) {
    if (V1Mag == 0 && V2Mag == 0) {
      V3Deg[(int)WheelType::FR] = 135;
      V3Deg[(int)WheelType::FL] = 45;
      V3Deg[(int)WheelType::BR] = 45;
      V3Deg[(int)WheelType::BL] = 135;  
    } else {
      V3Deg[i] = Math::getUnitDeg(V1ex + V2ex[i], V1ey + V2ey[i]);
    }
  }
}

void Swerve::V3::setV3DegError() {
  std::array<double, 4> ShortestDistance = {};

  for (int i = 0; i < 4; ++i) {
    ShortestDistance[i] = Math::getShortestDis(WheelDeg[i], V3Deg[i]);
    // frc::SmartDashboard::PutNumber("ShortestDistance", ShortestDistance[(int)WheelType::FR]);
    if (std::abs(ShortestDistance[i]) > 90) {
      if (i == 0)
        Motor::FR.SetInverted(true);
      else if (i == 1)
        Motor::FL.SetInverted(true);
      else if (i == 2)
        Motor::BR.SetInverted(false);
      else if (i == 3)
        Motor::BL.SetInverted(false);
      
      if (ShortestDistance[i] > 0) {
        Error[i] = -(180 - ShortestDistance[i]);
      } else {
        Error[i] = 180 + ShortestDistance[i];
      }
    } else {
      if (i == 0)
        Motor::FR.SetInverted(false);
      else if (i == 1)
        Motor::FL.SetInverted(false);
      else if (i == 2)
        Motor::BR.SetInverted(true);
      else if (i == 3)
        Motor::BL.SetInverted(true);

      Error[i] = ShortestDistance[i];
    }
    

    // frc::SmartDashboard::PutNumber("FR V3Deg", V3Deg[(int)WheelType::FR]);
    // frc::SmartDashboard::PutNumber("FL V3Deg", V3Deg[(int)WheelType::FL]);
    // frc::SmartDashboard::PutNumber("BR V3Deg", V3Deg[(int)WheelType::BR]);
    // frc::SmartDashboard::PutNumber("BL V3Deg", V3Deg[(int)WheelType::BL]);
  }
}

void Swerve::V3::setV3Mag() {
  for (int i = 0; i < 4; ++i) {
    V3Mag[i] = Math::getMag(V1ex + V2ex[i], V1ey + V2ey[i]);
  }
}

void Swerve::V3::setPID() {
  static std::array<bool, 4> flag = {};
  static std::array<double, 4> eprev = {};

  for (int i = 0; i < 4; ++i) {
    Math::InitPreverror(Error[i], flag[i], eprev[i]);
    TurnPower[i] = Math::getNewPID(Error[i], ekP, 2000);
  }
  Motor::FRSpin.Set(TurnPower[(int)WheelType::FR]);
  Motor::FLSpin.Set(TurnPower[(int)WheelType::FL]);
  Motor::BRSpin.Set(TurnPower[(int)WheelType::BR]);
  Motor::BLSpin.Set(TurnPower[(int)WheelType::BL]);

  frc::SmartDashboard::PutNumber("V3Mag FR", V3Mag[(int)WheelType::FR]);
  frc::SmartDashboard::PutNumber("V3Mag FL", V3Mag[(int)WheelType::FL]);
  frc::SmartDashboard::PutNumber("V3Mag BR", V3Mag[(int)WheelType::BR]);
  frc::SmartDashboard::PutNumber("V3Mag BL", V3Mag[(int)WheelType::BL]);
  frc::SmartDashboard::PutNumber("TurnPower FR", TurnPower[(int)WheelType::FR]);
  frc::SmartDashboard::PutNumber("TurnPower FL", TurnPower[(int)WheelType::FL]);
  frc::SmartDashboard::PutNumber("TurnPower BR", TurnPower[(int)WheelType::BR]);
  frc::SmartDashboard::PutNumber("TurnPower BL", TurnPower[(int)WheelType::BL]);

  for (int i = 0; i < 4; ++i) {
    V3Mag[i] = std::clamp(V3Mag[i], (double)-1, (double)1);
  }

  Motor::FR.Set(V3Mag[(int)WheelType::FR]);
  Motor::FL.Set(V3Mag[(int)WheelType::FL]);
  Motor::BR.Set(V3Mag[(int)WheelType::BR]);
  Motor::BL.Set(V3Mag[(int)WheelType::BL]);
}
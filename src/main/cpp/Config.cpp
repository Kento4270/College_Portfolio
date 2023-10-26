#include "Config.h"

namespace Motor {
  rev::CANSparkMax FR(5, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax BR(8, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax FL(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax BL(4, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax FRSpin(6, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax BRSpin(7, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax FLSpin(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax BLSpin(3, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax Elevator(10, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax Intake(9, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax Wrist(15, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
}

namespace Encoder {
  frc::Encoder Elevator(8, 9);
  frc::DutyCycleEncoder Wrist(0);
  ctre::phoenix::sensors::CANCoder BL(24);
  ctre::phoenix::sensors::CANCoder BR(25);
  ctre::phoenix::sensors::CANCoder FL(27);
  ctre::phoenix::sensors::CANCoder FR(26);
}

AHRS navx (frc::SPI::Port::kMXP);
frc::GenericHID Con(0);
frc::GenericHID Buttons(1);
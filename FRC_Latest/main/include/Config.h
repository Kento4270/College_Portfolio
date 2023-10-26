#pragma once

//this contains the objects of Motors, Sensors, Joycon, IMU...

#include "Basic.h"
#include <rev/CANSparkMax.h>
#include <frc/GenericHID.h>
#include <frc/Encoder.h>
#include <frc/DutyCycleEncoder.h>
#include <ctre/phoenix/sensors/CANCoder.h>
#include <ctre/phoenix/sensors/Pigeon2.h>

namespace Motor {
  extern rev::CANSparkMax FR, BR, FL, BL, FRSpin, BRSpin, FLSpin, BLSpin, Elevator, Intake, Wrist;
}

namespace Encoder {
  extern frc::Encoder Elevator;
  extern frc::DutyCycleEncoder Wrist;
  extern ctre::phoenix::sensors::CANCoder BL, BR, FL, FR;
}

extern frc::GenericHID Con;
// extern ctre::phoenix::sensors::Pigeon2 IMU;
extern AHRS navx;
extern frc::GenericHID Buttons;
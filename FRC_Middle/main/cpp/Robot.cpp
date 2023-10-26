// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <rev/CANSparkMax.h>
#include <ctre/phoenix/sensors/CANCoder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <iostream>
#include <thread>
// rev::CANSparkMax RFmotor(19, rev::CANSparkMaxLowLevel::MotorType::kBrushless); //using
// rev::CANSparkMax SpinRFmotor(20, rev::CANSparkMaxLowLevel::MotorType::kBrushless); //using
// ctre::phoenix::sensors::CANCoder RFEnc(24); //using
frc::Joystick Joystick(1);
void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  std::cout << "hi";
}
void Robot::TeleopPeriodic() {
    frc::SmartDashboard::PutNumber("DirectionDegrees", Joystick.GetDirectionDegrees());
  frc::SmartDashboard::PutNumber("Magnitude", Joystick.GetMagnitude());
  frc::SmartDashboard::PutNumber("Throttle", Joystick.GetThrottle());
  frc::SmartDashboard::PutNumber("ThrottleChannel", Joystick.GetThrottleChannel());
  frc::SmartDashboard::PutBoolean("Top", Joystick.GetTop());
  frc::SmartDashboard::PutBoolean("TopPressed", Joystick.GetTopPressed());
  frc::SmartDashboard::PutBoolean("TopRelease", Joystick.GetTopReleased());
  frc::SmartDashboard::PutBoolean("Trigger", Joystick.GetTrigger());
  frc::SmartDashboard::PutBoolean("TriggerPressed", Joystick.GetTriggerPressed());
  frc::SmartDashboard::PutBoolean("TriggerReleased", Joystick.GetTriggerReleased());
  frc::SmartDashboard::PutNumber("Twist", Joystick.GetTwist());
  frc::SmartDashboard::PutNumber("TwistChannel", Joystick.GetTwistChannel());
  frc::SmartDashboard::PutNumber("X", Joystick.GetX());
  frc::SmartDashboard::PutNumber("Xchannel", Joystick.GetXChannel());
  frc::SmartDashboard::PutNumber("Y", Joystick.GetY());
  frc::SmartDashboard::PutNumber("Ychannel", Joystick.GetYChannel());
  frc::SmartDashboard::PutNumber("Z", Joystick.GetZ());
  frc::SmartDashboard::PutNumber("Zchannel", Joystick.GetZChannel());
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

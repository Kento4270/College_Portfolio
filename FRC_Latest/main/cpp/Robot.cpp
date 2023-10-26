// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "Systems/Swerve.h"
#include "Systems/Intake.h"
#include "Config.h"
#include "Systems/Elevator.h"
#include "Systems/Wrist.h"
#include "Math.h"
#include "Systems/Kill.h"
#include "Systems/LED.h"
#include "Systems/Control.h"
#include "Systems/Inputs.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  // Motor::Elevator.SetInverted(true);
  // Motor::Wrist.SetInverted(true);
  // std::thread t1(Elevator::run);
  // t1.detach();
  // Elevator::kPos = Elevator::Pos::High;
  // Elevator::kObj = Elevator::Obj::Cube;
  // sleep_for(2s);
  // Motor::Intake.Set(-1);
  // sleep_for(1s);
  // Motor::Intake.StopMotor();
  // Elevator::kPos = Elevator::Pos::Low;
  // Elevator::kObj = Elevator::Obj::Cube;
  // // Elevator::SetPosition(Pos::High)
  // Motor::Wrist.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FR.Set(-0.4);
  // Motor::BR.Set(-0.4);
  // Motor::FL.Set(0.4);
  // Motor::BL.Set(0.4);
  // sleep_for(1.6s);
  // Motor::FRSpin.StopMotor();
  // Motor::FLSpin.StopMotor();
  // Motor::BRSpin.StopMotor();
  // Motor::BLSpin.StopMotor();
  // Motor::FR.StopMotor();
  // Motor::FL.StopMotor();
  // Motor::BR.StopMotor();
  // Motor::BL.StopMotor();
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // frc::SmartDashboard::PutNumber("hehehe", true);
  Motor::Elevator.SetInverted(true);
  Motor::Wrist.SetInverted(true);
  Encoder::FR.ConfigSensorDirection(true);
  Encoder::FL.ConfigSensorDirection(true);
  Encoder::BR.ConfigSensorDirection(true);
  Encoder::BL.ConfigSensorDirection(true);
  Motor::Wrist.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::FR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::FL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::BR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::BL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::FRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::FLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::BRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  Motor::BLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  Motor::FR.SetSmartCurrentLimit(40);
  Motor::FL.SetSmartCurrentLimit(40);
  Motor::BR.SetSmartCurrentLimit(40);
  Motor::BL.SetSmartCurrentLimit(40);
  Motor::FRSpin.SetSmartCurrentLimit(40);
  Motor::FLSpin.SetSmartCurrentLimit(40);
  Motor::BRSpin.SetSmartCurrentLimit(40);
  Motor::BLSpin.SetSmartCurrentLimit(40);
  Motor::Elevator.SetSmartCurrentLimit(40);
  Motor::Wrist.SetSmartCurrentLimit(40);
}
void Robot::TeleopPeriodic() {
  Kill();
  Swerve::run();
  Inputs::run();
  Control::run();
}

void Robot::DisabledInit() {
  Motor::FR.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::FL.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::BR.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::BL.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::FRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::FLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::BRSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  Motor::BLSpin.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
  
  // //Reset on the specific position
  // Encoder::Elevator.Reset();
  // Encoder::Wrist.Reset();
  // Motor::Intake.SetSmartCurrentLimit(2);

  // Motor::Elevator.SetInverted(true);
  // Motor::Wrist.SetInverted(true);
  // std::thread t1(Intake::run);
  // t1.detach();
  // std::thread t2(Wrist::run);
  // t2.detach();
  // std::thread t3(Elevator::run);
  // t3.detach();
  // Motor::FR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::BL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  // Motor::FR.Set(0.1);
  // Motor::FL.Set(0.1);
  // Motor::BR.Set(0.1);
  // Motor::BL.Set(0.1);

  // std::thread t1(Wrist::run);
  // t1.detach();
  // Motor::Wrist.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  // Motor::FR.Set(-0.2);
  // Motor::BR.Set(-0.2);
  // Motor::FL.Set(0.2);
  // Motor::BL.Set(0.2);
}
void Robot::TestPeriodic() {
  LED();
  // Motor::Wrist.Set(-0.6);
  // Motor::FRSpin.Set(0.3);
  // Motor::FLSpin.Set(0.3);
  // Motor::BRSpin.Set(0.3);
  // Motor::BLSpin.Set(0.3);
  // frc::SmartDashboard::PutNumber("Elevator position", Encoder::Elevator.Get());
  // frc::SmartDashboard::PutNumber("Wrist absolute deg", Encoder::Wrist.GetAbsolutePosition());
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

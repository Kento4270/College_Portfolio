#include "Systems/Control.h"
#include "Systems/Inputs.h"
#include "Basic.h"
#include "Robot.h"
#include "Config.h"
#include "Math.h"

double Control::Elevator_error = 0, Control::Wrist_error = 0;
int const Control::ElevatorLowPoint = 400, Control::ElevatorCubeMidPoint = 6979, Control::ElevatorConeMidPoint = 15348,
    Control::ElevatorCubeHiPoint = 16248, Control::ElevatorConeHiPoint = 16248, Control::LoadStatPoint = 400;
float const Control::WristEncZero = 0.92, Control::WristEncMax = 1, Control::Deg_Up = 10, Control::LowDeg = 266, Control::CubeMidDeg = 291, Control::ConeMidDeg = 280, Control::CubeHiDeg = 300, Control::ConeHiDeg = 296, Control::LoadStatDeg = 350,
Control::kP = 0.0003f, Control::kD = 0.00005f; //Lowdeg and conemid may be swapped
Control::Elevator Control::m_Elevator = Elevator::Lo;
Control::Intake Control::m_Intake = Intake::Off;
Control::Wrist Control::m_Wrist = Wrist::Disable;

void Control::run() {
  if (frc::RobotState::IsTeleop()) {
    Control::EleBind();
    Control::IntakeBind();
    Control::setMotor();
  } else if (frc::RobotState::IsAutonomous()) {
    Control::setMotor();
  }
}

void Control::setEle(Elevator kElevator) {
  m_Elevator = kElevator;
}

void Control::setIntake(Intake kIntake) {
  m_Intake = kIntake;
}

void Control::setWrist(Wrist kWrist) {
  m_Wrist = kWrist;
}

void Control::EleBind() {
  if (Buttons.GetRawButton(4)) {
    setEle(Elevator::CubeHi);
  } else if (Buttons.GetRawButton(7)) {
    setEle(Elevator::CubeMid);
  } else if (Buttons.GetRawButton(10) || Buttons.GetRawButton(11)) {
    setEle(Elevator::Lo);
  } else if (Buttons.GetRawButton(5)) {
    setEle(Elevator::ConeHi);
  } else if (Buttons.GetRawButton(8)) {
    setEle(Elevator::ConeMid);
  }
}

void Control::IntakeBind() {
  if (Inputs::LT) {
    setIntake(Intake::On);
  } else {
    setIntake(Intake::Off);
  }
}

void Control::setMotor() {
  double WristDeg = 360 - getWristDeg(Encoder::Wrist.GetAbsolutePosition());
  // frc::SmartDashboard::PutNumber("WristDeg", WristDeg);
  double EPower = 0;
  double WPower = 0;
  static double eprev = 0;
  double const kG = 0.015 * std::sin(WristDeg * M_PI / 180);
  if (m_Elevator == Elevator::Lo) {
    Elevator_error = ElevatorLowPoint - Encoder::Elevator.Get();
    if (Inputs::L && isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, LowDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  } else if (m_Elevator == Elevator::CubeMid) {
    Elevator_error = ElevatorCubeMidPoint - Encoder::Elevator.Get();
    if (isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, CubeMidDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  } else if (m_Elevator == Elevator::CubeHi) {
    Elevator_error = ElevatorCubeHiPoint - Encoder::Elevator.Get();
    if (isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, CubeHiDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  } else if (m_Elevator == Elevator::ConeMid) {
    Elevator_error = ElevatorConeMidPoint - Encoder::Elevator.Get();
    if (isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, ConeMidDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  } else if (m_Elevator == Elevator::ConeHi) {
    Elevator_error = ElevatorConeHiPoint - Encoder::Elevator.Get();
    if (isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, ConeHiDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  } else if (m_Elevator == Elevator::LoadStat) {
    Elevator_error = LoadStatPoint - Encoder::Elevator.Get();
    if (Inputs::A && isElevatorDone() == true) {
      setWrist(Wrist::Enable);
      Wrist_error = Math::getShortestDis(WristDeg, LoadStatDeg);
    } else {
      setWrist(Wrist::Disable);
    }
  }
  if (m_Wrist == Wrist::Disable) {
    Wrist_error = Math::getShortestDis(WristDeg, Deg_Up);
  }
  EPower = Math::getPID(Elevator_error, kP, kD, eprev);
  Motor::Elevator.Set(EPower + kG);
  WPower = Math::getPID(Wrist_error, 0.01, 0, eprev);
  Motor::Wrist.Set(WPower + kG);
  if (m_Intake == Intake::On) {
    if (m_Elevator == Elevator::ConeHi || m_Elevator == Elevator::ConeMid || m_Elevator == Elevator::CubeHi || m_Elevator == Elevator::CubeMid) {
      if (Inputs::L || Inputs::R) {
        Motor::Intake.Set(1);
      }
    } else if (m_Elevator == Elevator::Lo) {
      if (Inputs::RT || Inputs::A) {
        Motor::Intake.Set(-1);
      }
    }
  }
}

bool Control::isElevatorDone() {
  static units::time::second_t Timer = frc::Timer::GetFPGATimestamp();
  if (std::abs(Elevator_error) < 6000) {
    if (frc::Timer::GetFPGATimestamp() > Timer + 0.5_s) { //tune this number
      return true;
    } else {
      Timer = frc::Timer::GetFPGATimestamp();
      return false;
    }
  } else {
    return false;
  }
}

bool Control::isWristDone() {
  static units::time::second_t Timer = frc::Timer::GetFPGATimestamp();
  if (frc::Timer::GetFPGATimestamp() > Timer + 0.5_s) {
    if (std::abs(Wrist_error) < 5) { //tune this number
      return true;
    } else {
      Timer = frc::Timer::GetFPGATimestamp();
      return false;
    }
  } else {
    return false;
  }
}

double Control::getWristDeg(double Raw_WristDeg) {
  return fmod(Raw_WristDeg - (double)WristEncZero + (double)WristEncMax, (double)WristEncMax) * 360;
}
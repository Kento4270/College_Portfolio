#pragma once

#include "Basic.h"


//use class here
struct Control {
  enum class Elevator {
    CubeHi, CubeMid, Lo, ConeHi, ConeMid, LoadStat
  };
  enum class Intake {
    On, Off
  };
  enum class Wrist {
    Enable, Disable
  };
  static double Elevator_error, Wrist_error;
  static Elevator m_Elevator;
  static Intake m_Intake;
  static Wrist m_Wrist;
  static void EleBind();
  static void IntakeBind();
  static void setMotor();
  static bool isElevatorDone();
  static bool isWristDone();
  static void run();
  static void setEle(Elevator kElevator);
  static void setIntake(Intake kIntake);
  static void setWrist(Wrist kWrist);
  static double getWristDeg(double Raw_WristDeg);
  static int const ElevatorLowPoint, ElevatorCubeMidPoint, ElevatorConeMidPoint, ElevatorCubeHiPoint, ElevatorConeHiPoint, LoadStatPoint;
  static float const WristEncZero, WristEncMax, Deg_Up, LowDeg, CubeMidDeg, ConeMidDeg, CubeHiDeg, ConeHiDeg, LoadStatDeg, kP, kD;
};
#pragma once

#include "Basic.h"

//Inputs caluculate the values from Joycons, Cancoder, IMU.
struct Inputs {
  enum AxisType {
    RX, RY, LX, LY
  };
  static std::array<double, 4> Axis, WheelDeg;
  static double LDeg, LMag, Heading, A, X, Y, B, Circle, Plus, Minus, Square, Home, R, RT, L, LT;
  static bool isIMUreset;

  static void getHeading();
  static void getWheelDeg();
  static void getAxis();
  static void getMagDeg();
  static void getButtons();
  static void run();
  struct Const {
    static double const Length, Width;
    static const float EncMax;
    static const std::array<float, 4> EncZero;
  };
};
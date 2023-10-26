#pragma once

#include "Basic.h"

class Swerve {

public:
  //multithread this function to execute
  static void run();
  enum class WheelType {
    FR, FL, BR, BL
  };
private:
  static const std::array<int, 4> V2Deg;

  static std::array<double, 4> Axis, WheelDeg, V3Mag, V3Deg, TurnPower, MovePower, V2ex, V2ey;
  static double LDeg, LMag, Heading, V2Mag, V1Deg, V1Mag, V1ex, V1ey;
  static bool isIMUreset;

  enum class AxisType {
    RX, RY, LX, LY
  };

  //V1 is a vector of moving robot
  struct V1 {
    static void setV1Deg();
    static void setV1Mag();
  };

  //V2 is a vector of turning robot
  struct V2 {
    static const float HeadingOffAcceptedRange, V2MagMultiplier, kP, kD;
    static void RelativeTurning();
    static double getV2MagLimiter();
    static void setex_ey();
    static double convertToUnitCicleDeg(double const Input);
  };

  //V3 is a vector combined with V1 and V2 (moving and turning)
  struct V3 {
    static const float ekP;
    static std::array<double, 4> Error;
    static void setV3Deg();
    static void setV3DegError();
    static void setV3Mag();
    static void setPID();
  };

  //Inputs caluculate the values from Joycons, Cancoder, IMU.
  struct Inputs {

    //put this function in Swerve::run(while looped) to caluculate the values
    static void run();
    
    //returns the 0 offsetted degree of wheels
    static double getWheelDeg(double Raw_WheelDeg, WheelType m_EncType);

    //returns the deadzoned (range of -1 to 1) axis
    static float setDeadZone(float const axis);

    //returns the inverted axis
    static float getInvertedAxis(double const axis);

    //returns the magnitude based on ex and ey of a vector
    static double getMag(double const x, double const y);

    //returns the value which was converted from rotation(-infinte to infinite) to heading (0 - 360)
    static double getHeading(double const Rotation);

    //Constants for getwheelDeg
    static const float EncMax;
    static const std::array<float, 4> EncZero;

  };

};
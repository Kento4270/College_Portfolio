#include "Math.h"

namespace Math {
  double getPID(double const error, double const kP, double const kD, double& eprev) {
    double output = 0;
    double eDot = std::abs(error - eprev);
    if (error > 0) {
      output = error * kP - kD * eDot;
    } else {
      output = error * kP + kD * eDot;
    }
    eprev = error;
    return output;
  }

  double getPID(double const error, double const kP) {
    double output = error * kP;
    return output;
  }

  double getNewPID(double const error, double const ekP, double const intensity) {
    if (intensity == 0) {
      return 0;
    }
    double output = error * std::abs(error) * ekP / intensity;
    return output;
  }

  double getShortestDis(double const measurement, double const input) {
    if (std::abs(input - measurement) <= 180) {
      return input - measurement;
    } else {
      if (input - measurement > 0) {
        return -(360 - input + measurement);
      } else {
        return 360 - measurement + input;
      }
    }
  }

  double getUnitDeg(double const x, double const y) {
    if (x == 0 && y == 0) {
      return 0;
    } else if (x == 0 && y > 0) {
      return 0;
    } else if (x == 0 && y < 0) {
      return 180;
    } else if (x >= 0 && y >= 0) {
      return 90 - atan(y / x) * 180 / M_PI;
    } else if (x >= 0 && y <= 0) {
      return 90 - atan(y / x) * 180 / M_PI;
    } else if (x <= 0 && y <= 0) {
      return 270 - atan(y / x) * 180 / M_PI;
    } else if (x <= 0 && y >= 0) {
      return 270 - atan(y / x) * 180 / M_PI;
    }
    return 0;
  }

  void InitPreverror(double error, bool& flag, double& eprev) {
    if (flag == false) {
      flag = true;
      eprev = -error;
    }
  }

  double setFieldOriented(double ConVal, double Heading) {
    double FieldOrientedDeg = fmod(ConVal + (360 - Heading), 360);
    return FieldOrientedDeg;
  }

  double getex(double const deg, double const mag) {
    return std::cos(deg * M_PI / (double)180) * mag;
  }

  double getey(double const deg, double const mag) {
    return std::sin(deg * M_PI / (double)180) * mag;
  }

  double getMag(double const x, double const y) {
    return std::sqrt(x * x + y * y);
  }

  double setDeadZone(double const axis) {
    float const a = 0.03;
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

  double getInvertedAxis(double const axis) {
    if (axis != 0) {
      return -axis;
    } else {
      return 0;
    }
  }

  double getHeading(double const Rotation) {
    if (Rotation < 0) {
      return fmod(-Rotation, (double)360);
    } else {
      return 360 + fmod(-Rotation, (double)360);
    }
  }

  double convertToUnitCicleDeg(double const Input) {
    return fmod(450 - Input, (double)360);
  }
}
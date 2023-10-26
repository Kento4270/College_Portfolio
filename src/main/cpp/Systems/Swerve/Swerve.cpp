#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

std::array<double, 4> Swerve::Axis = {}, Swerve::WheelDeg = {}, Swerve::V3Mag = {}, Swerve::V3Deg = {}, Swerve::TurnPower = {}, Swerve::MovePower = {}, Swerve::V2ex = {}, Swerve::V2ey = {}, Swerve::V3::Error = {};
double Swerve::LDeg = 0, Swerve::LMag = 0, Swerve::Heading = 0, Swerve::V2Mag = 0, Swerve::V1Deg = 0, Swerve::V1Mag = 0, Swerve::V1ey = 0, Swerve::V1ex = 0;
bool Swerve::isIMUreset = false;

void Swerve::run() {
  Inputs::run();
  V1::setV1Deg();
  V1::setV1Mag();
  V2::RelativeTurning();
  V2::setex_ey();
  V3::setV3Deg();
  V3::setV3DegError();
  V3::setV3Mag();
  V3::setPID();
}
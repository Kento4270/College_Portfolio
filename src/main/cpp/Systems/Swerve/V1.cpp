#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

void Swerve::V1::setV1Deg() {
  double const FieldOriented_LDeg = Math::setFieldOriented(LDeg, Heading);
  V1Deg = FieldOriented_LDeg;

  // frc::SmartDashboard::PutNumber("V1deg", V1Deg);
}

void Swerve::V1::setV1Mag() {
  V1Mag = std::clamp(LMag, (double)-1, (double)1);

  // frc::SmartDashboard::PutNumber("V1Mag", V1Mag);
}
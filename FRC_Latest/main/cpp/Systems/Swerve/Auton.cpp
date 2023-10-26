#include "Systems/Swerve.h"
#include "Math.h"
#include "Config.h"

// void setWheelsTo(double const Input) {
//   std::array<double, 4> Error = {}, PrevError = {}, TurnPower = {}, WheelDeg = {};
//   std::array<bool, 4> flag = {};
//   WheelDeg[(int)Swerve::WheelType::FR] = getWheelDeg(Encoder::FR.GetAbsolutePosition(), Swerve::WheelType::FR);
//   WheelDeg[(int)Swerve::WheelType::FL] = getWheelDeg(Encoder::FL.GetAbsolutePosition(), Swerve::WheelType::FL);
//   WheelDeg[(int)Swerve::WheelType::BR] = getWheelDeg(Encoder::BR.GetAbsolutePosition(), Swerve::WheelType::BR);
//   WheelDeg[(int)Swerve::WheelType::BL] = getWheelDeg(Encoder::BL.GetAbsolutePosition(), Swerve::WheelType::BL);
//   for (int i = 0; i < 4; ++i) {
//     Error[i] = Math::getShortestDis(WheelDeg[i], Input);
//     Math::InitPreverror(Error[i], flag[i], PrevError[i]);
//     TurnPower[i] = Math::getNewPID(Error[i], 0.55, 2000);
//   }
//   Motor::FRSpin.Set(TurnPower[(int)Swerve::WheelType::FR]);
//   Motor::FLSpin.Set(TurnPower[(int)Swerve::WheelType::FL]);
//   Motor::BRSpin.Set(TurnPower[(int)Swerve::WheelType::BR]);
//   Motor::BLSpin.Set(TurnPower[(int)Swerve::WheelType::BL]);
// }
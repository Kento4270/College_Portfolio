#include "vex.h"

void turnPID(double DesiredDeg, double* turnVolt) {
  const double kP = 0;
  const double kI = 0;
  const double kD = 0;
  const int dt = 20; //20ms inbetween each jobs.
  const double constVolt = 1;//1~12 volt, stationary offset.
  double eInt = 0;
  double error = 0;
  double prevError = DesiredDeg;
  bool isIntegral = false;

  Brain.Timer.reset();
  while (1) {
    error = -DesiredDeg + imu.heading(deg);
    if(std::abs(error) <= 180) {
      error = -error;
    } else {
      error = 360 - error;
    }
    //fix integral part
    if(isIntegral == true) {
      eInt = eInt + error;
      isIntegral = false;
    } else {
      eInt = 0;
    }
    *turnVolt = kP * error + kI * eInt + kD * (error - prevError) * dt + constVolt;
    prevError = error;

    // if(imu.acceleration(yaxis) <= 0.45 && imu.acceleration(yaxis) >= -0.45) {
    //   if(Brain.Timer.value() > 1 && error < 10 && error > -10) {
    //     return;
    //   } else if(Brain.Timer.value() > 1) {
    //     isIntegral = true;
    //   }
    // } else {
    //   Brain.Timer.reset();
    // }
    //acceleration value and error restriction value have to be changed after you test
    wait(20, msec);
  }
}
#include "vex.h"
void imuModule(double desiredDeg, double imuPrevError, double* imuMotorvoltage);
void encModule(double desiredValue, double encPrevError, double* encMotorvoltage);

void test(double desiredDeg, double desiredValue) {
  double encMotorvoltage = 0;
  double imuMotorvoltage = 0;
  double encPrevError = 0;
  double imuPrevError = 0;

  //EncoderGroup.resetRotation();
  Brain.Timer.reset();
  encPrevError = desiredValue;
  imuPrevError = desiredDeg;
  while (1) {
    encModule(desiredValue, encPrevError, &encMotorvoltage);
    imuModule(desiredDeg, imuPrevError, &imuMotorvoltage);



    wait(20, msec);
  }
}

void encModule(double desiredValue, double encPrevError, double* encMotorvoltage) {
  const double kP = 0;
  const double kI = 0;
  const double kD = 0;
  //const double WheelDia = 3.25;
  double Dis = 0;
  double eInt = 0;
  double error = 0;
  //Dis = WheelDia * D_PI * ((LeftEncoder.position(deg) + (-BottomEncoder.position(deg))) / 2 / 360);
  error = desiredValue - Dis;
  *encMotorvoltage = kP * error + kI * (eInt + error) + kD * (error - encPrevError);
  encPrevError = error;
}

void imuModule(double desiredDeg, double imuPrevError, double* imuMotorvoltage) {
  const double kP = 0;
  const double kI = 0;
  const double kD = 0;
  double eInt = 0;
  double error = 0;
  if(imu.heading(deg) >= desiredDeg && imu.heading(deg) < (180 + desiredDeg)) {
    error = desiredDeg - imu.heading(deg);
  } else if(imu.heading(deg) >= (180 + desiredDeg) && imu.heading(deg) < desiredDeg) {
    error = 360 - imu.heading(deg);
  }
  *imuMotorvoltage = kP * error + kI * (eInt + error) + kD * (error - imuPrevError);
  imuPrevError = error;
}
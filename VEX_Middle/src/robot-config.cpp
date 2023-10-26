#include "vex.h"

brain Brain;

controller Controller;

motor BackLeft    = motor(PORT9,ratio6_1,true);
motor MiddleLeft  = motor(PORT7,ratio6_1,true);
motor FrontLeft   = motor(PORT18,ratio6_1,true);

motor BackRight   = motor(PORT21,ratio6_1,false); //true enables reverse direction of motor.
motor MiddleRight = motor(PORT8,ratio6_1,false);
motor FrontRight  = motor(PORT6,ratio6_1,false);

motor Lift = motor(PORT2, ratio36_1,false);
motor Intake = motor(PORT1, ratio6_1,false);

motor_group LeftDrive = motor_group(BackLeft, MiddleLeft, FrontLeft);
motor_group RightDrive = motor_group(BackRight, MiddleRight, FrontRight);

digital_in FrontSW = digital_in(Brain.ThreeWirePort.F);

digital_out FrontClaw = digital_out(Brain.ThreeWirePort.H);
digital_out BackClaw = digital_out(Brain.ThreeWirePort.A);

gps GPS = gps(PORT11, 0, 0, mm, 0); //Set offset by moving robot while reading its value.

triport Expander = triport(PORT20);

inertial Gyro = inertial(PORT15);

potV2 selector = potV2(Brain.ThreeWirePort.G);

encoder EncoderRight = encoder(Expander.E);
encoder EncoderLeft = encoder(Expander.C);
digital_in BackSW = digital_in(Expander.G);

void vexcodeInit(void) {
  return;
}
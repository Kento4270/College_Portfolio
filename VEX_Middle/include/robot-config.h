#pragma once

using vex::brain, vex::controller, vex::motor, vex::motor_group, vex::gps, vex::encoder, vex::potV2, vex::digital_out, 
vex::inertial, vex::digital_in;

extern brain Brain;
extern controller Controller;

extern motor BackLeft;
extern motor BackRight;
extern motor MiddleLeft;
extern motor MiddleRight;
extern motor FrontLeft;
extern motor FrontRight;

extern motor Lift;
extern motor Intake;

extern motor_group LeftDrive;
extern motor_group RightDrive;

extern potV2 selector;

extern gps GPS;

extern inertial Gyro;

extern digital_out FrontClaw;
extern digital_out BackClaw;

extern digital_in FrontSW;
extern digital_in BackSW;

extern encoder EncoderRight;
extern encoder EncoderLeft;

void vexcodeInit(void);
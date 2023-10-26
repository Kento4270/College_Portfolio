#ifndef INCLUDE_ROBOT_CONFIG
#define INCLUDE_ROBOT_CONFIG

using vex::brain;
using vex::controller;
using vex::motor;
using vex::motor_group;
using vex::digital_out;
using vex::pot;
using vex::digital_in;
using vex::gps;

extern brain Brain;

extern controller Controller;

extern motor FrontLeft;
extern motor FrontRight;
extern motor MiddleLeft;
extern motor MiddleRight;
extern motor BackLeft;
extern motor BackRight;

extern motor Lift;
extern motor Grabber;

extern motor_group LeftDrive;
extern motor_group RightDrive;

extern digital_out TopPiston;
extern digital_out BackPiston;

extern pot GrabberPot;
extern pot LiftPot;

extern pot TestPot;

extern digital_in BackSwitch;

extern gps GPS;

// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#endif
#include "Libralies/vex.h"

using vex::brain;
using vex::PORT20;
using vex::PORT19;
using vex::PORT4;
using vex::PORT7;
using vex::PORT8;
using vex::PORT9;
using vex::PORT3;
using vex::PORT11;
using vex::PORT10;
using vex::ratio6_1;
using vex::ratio36_1;
using vex::ratio18_1;
using vex::digital_in;
using vex::gps;
using vex::mm;
using vex::vision;
using signature = vision::signature;
using code = vision::code;

//using signature = vision::signature;
//using code = vision::code;

brain Brain;

controller Controller;

motor BackLeft    = motor(PORT20,ratio6_1,false);
motor MiddleLeft  = motor(PORT19,ratio6_1,false);
motor FrontLeft   = motor(PORT14,ratio6_1,false);

motor BackRight   = motor(PORT8,ratio6_1,true); //true enables reverse direction of motor.
motor MiddleRight = motor(PORT9,ratio6_1,true);
motor FrontRight  = motor(PORT10,ratio6_1,true);

motor_group LeftDrive = motor_group(BackLeft, MiddleLeft, FrontLeft);
motor_group RightDrive = motor_group(BackRight, MiddleRight, FrontRight);

motor Grabber     = motor(PORT18,ratio36_1,false);
motor Lift        = motor(PORT11,ratio18_1,false);

digital_out TopPiston = digital_out(Brain.ThreeWirePort.C);
digital_out BackPiston = digital_out(Brain.ThreeWirePort.D);

digital_in BackSwitch = digital_in(Brain.ThreeWirePort.C);

pot GrabberPot = pot(Brain.ThreeWirePort.A);
pot LiftPot = pot(Brain.ThreeWirePort.B);

pot TestPot = pot(Brain.ThreeWirePort.H); //no pot is attached to H port, attach it later.

gps GPS = gps(PORT9, 1.50, 2.60, mm, 0);

// VEXcode device constructors

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
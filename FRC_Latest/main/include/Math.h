#pragma once

#include "Basic.h"

//math functions used across all the files

namespace Math {
  
  //returns degree based on unit circle
  double getUnitDeg(double const x, double const y);

  //returns value from normal PID
  double getPID(double const error, double const kP, double const kD, double& eprev);
  
  //simple pid
  double getPID(double const error, double const kP);

  //returns value from New PID, intensity changes the shape
  double getNewPID(double const error, double const ekP, double const intensity);

  //it becomes positive when going right
  //returns value which goes the shortest path
  double getShortestDis(double const measurement, double const input);
  
  //Sets the preverror same as error only once (to make derivative zero)
  void InitPreverror(double error, bool& flag, double& eprev);

  //returns the degree of heading which is Field Oriented.
  double setFieldOriented(double ConVal, double Heading);

  //returns ex from deg and mag
  double getex(double const deg, double const mag);

  //returns ey from deg and mag
  double getey(double const deg, double const mag);

  double getMag(double const x, double const y);

  static double convertToUnitCicleDeg(double const Input);
  
  static double getHeading(double const Rotation);//returns the value which was converted from rotation(-infinte to infinite) to heading (0 - 360)
  
  static double setDeadZone(double const axis);//returns the deadzoned (range of -1 to 1) axis
  
  static double getInvertedAxis(double const axis);//returns the inverted axis
}
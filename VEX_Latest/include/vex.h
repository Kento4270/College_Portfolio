#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include "v5.h"
#include "v5_vcs.h"
#include <cmath>
#define D_PI (3.14159265359)

using namespace vex;


void usercontrol();
void autonomous();
void pre_auton();
//void G1func(double* G1, double Offset, double Mag);
//void G2func(double* G2, double Offset, double Mag);
//void turnPID(double DesiredDeg, double* turnVolt);
void getCtrlDeg(int x, int y, double* CtrlDeg);
//void getMag(int x, int y, double* Mag);
//void getOffset(double CtrlDeg, double* Offset);
void FieldCentric(double* x, double* y);
void ColorDetection_R();
void ColorDetection_B();
void InputLimit(double* x, double* y);
void intake();
void roller();
void shooter();



extern brain Brain;
extern controller Controller;
extern motor RightFront;
extern motor RightBack;
extern motor LeftFront;
extern motor LeftBack;
extern motor Roller;
extern motor Intake;
extern motor FlyL;
extern motor FlyR;
extern encoder Right;
extern encoder Left;
extern encoder Mid;
extern inertial imu;
extern optical Optic;

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
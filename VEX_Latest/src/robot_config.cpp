#include "vex.h"
#include "EncoderGroup.h"

brain Brain;
controller Controller;

motor RightFront(PORT16, ratio6_1, true);
motor RightBack(PORT5, ratio6_1, true);
motor LeftFront(PORT2, ratio6_1, false);
motor LeftBack(PORT1, ratio6_1, false);
motor FlyR(PORT13, ratio18_1, false);
motor FlyL(PORT12, ratio18_1, false);
motor Intake(PORT18, ratio18_1, false);
motor Roller(PORT19, ratio18_1, false);

triport Expander(PORT11);

encoder Mid(Expander.E);
encoder Left(Expander.C);
encoder Right(Expander.A);

inertial imu(PORT7);
optical Optic(PORT8);


//EncoderGroupClass EncoderGroup(&RightEncoder, &LeftEncoder);
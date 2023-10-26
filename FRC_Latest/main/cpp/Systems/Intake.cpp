// #include "Config.h"
// #include "Systems/Intake.h"

// Intake::state Intake::kState;
// double const Intake::Intake_Power_Cone = 1, Intake::Intake_Power_Cube = -0.4, Intake::Outtake_Cube = 1, Intake::Outtake_Cone = -1, Intake::Intake_Loading_station = -0.5;

// void Intake::run() {
//   // int Timer = 400;
//   // if (Timer >= 400) {
//   //   if ((Buttons.GetRawButton(11) && kState == state::Intake_On) || (Buttons.GetRawButton(8) && kState == state::Outtake_On)) {
//   //     kState = state::Off;
//   //     Timer = 0;
//   //   } else if (Buttons.GetRawButton(8)) {
//   //     kState = state::Outtake_On;
//   //     Timer = 0;
//   //   } else if (Buttons.GetRawButton(11)) {
//   //     kState = state::Intake_On;
//   //     Timer = 0;
//   //   }
//   // }
//   if (Con.GetRawButton(7)) {
//     kState = state::Intake_Cone;
//   } else if (Con.GetRawButton(8)) {
//     kState = state::Intake_Cube;
//   } else if (Con.GetRawButton(5)) {
//     kState = state::Outtake_Cone;
//   } else if (Con.GetRawButton(6)) {
//     kState = state::Outtake_Cube;
//   } else if (Con.GetRawButton(3)) {
//     kState = state::Loadng_station;
//   } else {
//     kState = state::Off;
//   }
//   Set();
//   // Timer += 20;
// }

// void Intake::Set() {
//   if (kState == state::Intake_Cone) {
//     Motor::Intake.Set(Intake_Power_Cone);
//   } else if (kState == state::Intake_Cube) {
//     // Motor::Intake.Set(Intake_Power_Cube);
//   } else if (kState == state::Outtake_Cone) {
//     Motor::Intake.Set(Outtake_Cone);
//   } else if (kState == state::Outtake_Cube) {
//     Motor::Intake.Set(Outtake_Cube);
//   } else if (kState == state::Loadng_station) {
//     Motor::Intake.Set(Intake_Loading_station);
//   } else if (kState == state::Off) {
//     Motor::Intake.StopMotor();
//   }
// }

// Intake::state Intake::getState() {
//   return kState;
// }
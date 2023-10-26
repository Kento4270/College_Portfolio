#include "Systems/LED.h"
#include "Config.h"

frc::Spark LED_Controller(0);

void LED() {
  if (Buttons.GetRawButton(9)) {
    LED_Controller.Set(0.89);
  } else if (Buttons.GetRawButton(12)) {
    LED_Controller.Set(0.73);
  } else {
    LED_Controller.Set(0.93);
  }
}
#include "Systems/Kill.h"
#include "Config.h"

void Kill() {
  if (Con.GetRawButton(9) && Con.GetRawButton(10)) {
    std::cout << "Program Terminated" << std::endl;
    std::cout << "Program Terminated" << std::endl;
    std::cout << "Program Terminated" << std::endl;
    exit(0);
  }
}
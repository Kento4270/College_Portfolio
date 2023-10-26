#pragma once
#include "vex.h"

class EncoderGroupClass {
private:
  encoder* RightEncoderPtr;
  encoder* LeftEncoderPtr;
  encoder* MiddleEncoderPtr;
public:
  void resetRotation();
  EncoderGroupClass(encoder* const RightEncoderObj, encoder* const LeftEncoderObj, encoder* const MiddleEncoderObj);
};

extern EncoderGroupClass EncoderGroup;
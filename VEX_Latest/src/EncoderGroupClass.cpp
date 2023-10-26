#include "vex.h"
#include "EncoderGroup.h"

EncoderGroupClass::EncoderGroupClass(encoder *const RightEncoderObj, encoder *const LeftEncoderObj, encoder *const MiddleEncoderObj) {
  RightEncoderPtr = RightEncoderObj;
  LeftEncoderPtr = LeftEncoderObj;
  MiddleEncoderPtr = MiddleEncoderObj;
};

void EncoderGroupClass::resetRotation() {
  RightEncoderPtr->resetRotation();
  LeftEncoderPtr->resetRotation();
  MiddleEncoderPtr->resetRotation();
};
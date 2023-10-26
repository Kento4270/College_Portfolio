#include "vex.h"

void func() {
  double XDis = 0;
  double YDis = 0;
  //double WheelDia = 2.75;
  double Theta = 0;
  double Hypo = 0;
  double Heading = 0;
  double PrevDistance = 0;  
  double TotalDistance = 0; 
  double OppoY = 0;
  double AdjX = 0; 
  double XCoord = 0;
  double YCoord = 0;
  double Prev_X = 0; 
  double Prev_Y = 0;
  //double Rotation_Val = 0;

  while (1) {
    // XDis = WheelDia * D_PI * (BottomEncoder.position(deg) / 360);
    // YDis = WheelDia * D_PI * (LeftEncoder.position(deg) / 360);
    ///Rotation_Val = 
    if(XDis > 0 && YDis > 0) {
      Theta = atan(YDis / XDis) * 180 / D_PI;
      Heading = 90 - Theta;
      Hypo = sqrt(XDis * XDis + YDis * YDis);
    } else if(XDis > 0 && YDis < 0){
      Theta = atan(YDis / XDis) * 180 / D_PI;
      Heading = 270 + Theta; 
      Hypo = sqrt(XDis * XDis + YDis * YDis);
    } else if(XDis < 0 && YDis < 0){
      Theta = atan(YDis / XDis) * 180 / D_PI;
      Heading = 270 - Theta;
      Hypo = sqrt(XDis * XDis + YDis * YDis); 
    } else if(XDis < 0 && YDis > 0){
      Theta = atan(YDis / XDis) * 180 / D_PI;
      Heading = 90 + Theta;
      Hypo = sqrt(XDis * XDis + YDis * YDis); 
    }
    OppoY = Hypo * sin(Theta);
    AdjX = Hypo * cos(Theta);

    TotalDistance = Hypo + PrevDistance;
    PrevDistance = TotalDistance; 

    XCoord = AdjX + Prev_X;
    Prev_X = XCoord;
    YCoord = OppoY + Prev_Y;
    Prev_Y = YCoord;

    std::cout << OppoY<< "\n";
    std::cout << AdjX << "\n";
    wait(20, msec);
  }
 
}
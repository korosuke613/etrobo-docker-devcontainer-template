#ifndef __ONOFFCONTROLLER__
#define __ONOFFCONTROLLER__

#include "LineTracer.h"

class OnOffController : public LineTracer {
 public:
  OnOffController() = default;
  void calcurate(const int& brightness, int& leftPwm, int& rightPwm);
  void setParam(const int& threthold_, const int& forward_, const int& turn_);

 private:
  int threthold; // OnOff閾値
  int forward; // 前進値
  int turn; // 回転値
};

#endif

#include "OnOffController.h"

void OnOffController::calcurate(const int& brightness, int& leftPwm,
                                int& rightPwm) {
  if (brightness > threthold) {
    leftPwm = forward + turn;
    rightPwm = forward - turn;
    return;
  } else {
    leftPwm = forward - turn;
    rightPwm = forward + turn;
  }
}

void OnOffController::setParam(const int& threthold_, const int& forward_,
                               const int& turn_) {
  threthold = threthold_;
  forward = limitPwm(forward_);
  turn = limitPwm(turn_);
}

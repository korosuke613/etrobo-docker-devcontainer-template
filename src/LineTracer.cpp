#include "LineTracer.h"

int LineTracer::limitPwm(const int& power) {
  if (power > 100) {
    return 100;
  } else if (power < -100) {
    return -100;
  }

  return power;
}
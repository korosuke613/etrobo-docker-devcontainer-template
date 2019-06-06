#ifndef __LINETRACER__
#define __LINETRACER__

class LineTracer {
 public:
  LineTracer() = default;
  virtual void calcurate(const int& brightness, int& leftPwm, int& rightPwm) = 0;

 protected:
  int limitPwm(const int& power);
};

#endif

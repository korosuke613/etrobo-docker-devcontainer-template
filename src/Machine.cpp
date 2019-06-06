#include "Machine.h"

void Machine::calibration() {
  // スピーカ音量設定
  controller.speakerSetVolume(100);

  // 黒色の光設定
  controller.printDisplay(4, "Set black brightness");
  black = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);

  // 白色の光設定
  controller.printDisplay(4, "Set white brightness");
  white = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);

  // forward値、turn値の設定
  onOffController.setParam((black + white) / 2, 30, 10);
}

void Machine::run() {
  while (1) {
    if (controller.buttonIsPressedEnter() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      break;
    }
    controller.tslpTsk(4);
  }

  controller.speakerPlayTone(controller.noteFs6, 100);

  int leftPwm = 0;
  int rightPwm = 0;
  while (1) {
    if (controller.buttonIsPressedBack() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      controller.leftWheel.setPWM(0);
      controller.rightWheel.setPWM(0);
      break;
    }

    auto brightness = controller.getBrightness();
    onOffController.calcurate(brightness, leftPwm, rightPwm);
    controller.leftWheel.setPWM(leftPwm);
    controller.rightWheel.setPWM(rightPwm);

    controller.tslpTsk(4);
  }
}

int Machine::setBrightness() {
  while (1) {
    if (controller.buttonIsPressedEnter() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      break;
    }
    auto brightness = controller.getBrightness();
    controller.printDisplay(5, "BRIGHTNESS: %d", brightness);

    controller.tslpTsk(4); /* 4ms wait */
  }

  int result = 0;
  constexpr int num = 10;
  for (int i = 0; i < num; i++) {
    result += controller.getBrightness();
    controller.tslpTsk(4); /* 4ms wait */
  }
  result /= num;

  return result;
}
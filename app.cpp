/**
 * ファイル名 : app.c
 *
 * 概要 : ETロボコンのTOPPERS/HRP2用Cサンプルプログラム
 *
 * 注記 : Bluetooth通信リモートスタート機能付き
 */
#include "ev3api.h"

#include "Controller.h"
#include "Machine.h"
#include "app.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* メインタスク */
void main_task(intptr_t unused) {
  Controller controller;
  controller.printDisplay(1, "hackev_on_off_linetrace");
  controller.printDisplay(2, " create from KatLab-MiyazakiUniv");

  // キャリブレーション開始
  controller.ledSetColorOrange();
  Machine machine{controller};
  machine.calibration();

  // 待ち時間
  controller.tslpTsk(100);
  controller.ledSetColorGreen();

  // 走行
  machine.run();
}

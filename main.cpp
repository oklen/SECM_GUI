#include "mainwindow.h"
#include <QApplication>
#include "tabb.h"
#include "uxccdw.h"
#include "selecter.h"
#include "QDesktopServices"
#include "QUrl"
#include "sigma/sigmacontrol.h"
#include "picontorl.h"
#pragma comment(lib, "E:/SECM-User-Interface/PI/PI_GCS2_DLL_x64.lib")
#include "controlpad.h"
#include "settingwindow.h"
#include "axiscontrols.h"
#include "sigmagroup.h"
#include "pigroup.h"
#include "debugwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    sigmaGroup *sp = new sigmaGroup;
//    sp->show();
//    PIGroup *pp = new PIGroup;
//    pp->show();
//    AxisControls *ac=new AxisControls;
//    ac->show();

//    ControlPad cp;
//    cp.show();
    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qt-material-widgets/components/qtmaterialtabs.h>
#include<qt-material-widgets/components/qtmaterialflatbutton.h>
#include "leftstatus.h"
#include "tabb.h"
#include <QMouseEvent>
#include <QPainter>
#include <QVariantAnimation>
#include <QPropertyAnimation>
#include <QLabel>
#include "jaicontrol.h"
#include "controlpad.h"
#include "debugwin.h"
#include "settingwindow.h"
#include "pigroup.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    ~MainWindow();
    ControlPad * controlpad;
    JaiControl* jaicontrol;
    DebugWin *dw;
    SettingWindow * sw;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

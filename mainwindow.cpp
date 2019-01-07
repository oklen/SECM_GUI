#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),jaicontrol(new JaiControl),
    dw(new DebugWin),sw(new SettingWindow)/*,
    controlpad(new ControlPad)*/
{
    ui->setupUi(this);
    jaicontrol->uxCCD = ui->widget_3;
    ui->widget_2->tb[1].childshow = dw;
    ui->widget_2->tb[2].childshow = sw;
    dw->setParent(this);
    dw->move(180,70);
    sw->move(180,70);
    dw->hide();
    sw->cps = dw->sigmaGp->cPs;
    sw->cps->pi = dw->pi->pi;
    sw->cps->ls[10].setText(dw->pi->pi->DeviceName);
    sw->cps->setParent(sw);
    sw->cps->move(0,0);
    sw->setParent(this);
//    dw->show();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.setBrush(QColor(50,50,50));
    mpainter.drawRect(rect());
    mpainter.end();
}


MainWindow::~MainWindow()
{
    delete dw->pi;
    delete dw->sigmaGp;
    sw->setParent(nullptr);
    delete ui;
}

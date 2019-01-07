#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
}

void SettingWindow::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.setBrush(QColor(50,50,50));
    mpainter.drawRect(rect());
    mpainter.end();
}

SettingWindow::~SettingWindow()
{
    cps = nullptr;
    delete ui;
}

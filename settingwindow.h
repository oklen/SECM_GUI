#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "comportsetting.h"
#include <QPainter>
namespace Ui {
class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    comPortSetting *cps=nullptr;
    void paintEvent(QPaintEvent* event);
    ~SettingWindow();

private:
    Ui::SettingWindow *ui;
};

#endif // SETTINGWINDOW_H

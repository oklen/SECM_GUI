#ifndef DEBUGWIN_H
#define DEBUGWIN_H

#include <QWidget>
#include "commandtype.h"
#include <QDoubleSpinBox>
#include "addandsub.h"
#include <QPainter>
#include "sigmagroup.h"
namespace Ui {
class DebugWin;
}

class DebugWin : public QWidget
{
    Q_OBJECT

public:
    explicit DebugWin(QWidget *parent = nullptr);
    ~DebugWin();
    void paintEvent(QPaintEvent* event);
    ADDandSub *aands;
    QBrush mb;
    sigmaGroup *sigmaGp;
    PIGroup* pi;
    friend class SettingWindow;
private:
    Ui::DebugWin *ui;

};

#endif // DEBUGWIN_H

#ifndef AXISCONTROLS_H
#define AXISCONTROLS_H

#include <QWidget>
#include "qt-material-widgets/components/qtmaterialiconbutton.h"
#include "qt-material-widgets/components/qtmaterialslider.h"
#include "mylabel.h"
#include "uxinputline.h"
#include <QIcon>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QPushButton>
#include "commandtype.h"

class AxisControls : public QWidget
{
    Q_OBJECT
public:
    explicit AxisControls(QWidget *parent = nullptr);
    mylabel *DigLabel,*targetlabel,*steplabel,*axis,*hudlabel,*unit,*unit2,*unit3,*hudshow,*unit4;
    QPushButton *left,*right,*targetcon,*stepcon,*hudcon;
    QSlider *slider;
    uxinputline *targetinput,*stepinput,*hudinput;
    double maxvalue,step=0.1,nowvalue;
signals:
    void vUpdate(int v);
    void vUpdate(double v);
public slots:
};

#endif // AXISCONTROLS_H

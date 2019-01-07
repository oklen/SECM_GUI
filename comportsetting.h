#ifndef COMPORTSETTING_H
#define COMPORTSETTING_H

#include <QWidget>
#include "comoper.h"
#include <QComboBox>
#include "mylabel.h"
#include "sigma/sigmacontrol.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "commandtype.h"
#include "qt-material-widgets/components/qtmaterialraisedbutton.h"
#include "picontorl.h"

class comPortSetting : public QWidget
{
    Q_OBJECT
public:
    explicit comPortSetting(sigmaControl *sigma=nullptr,QWidget *parent = nullptr);
    sigmaControl * sigma=nullptr;
    PIContorl *pi=nullptr;
    bool test(int index);
    QComboBox *PortNames,*PortNames2;
    QtMaterialRaisedButton *testButton,*testButton2,*testButton3;
//    mylabel *cComPorts,*paraSet,*ByteSizeLabel,*ParirtyLabel,*StopBitsLabel,*bandrateLabel,
//    *statsLabel;
    mylabel* ls;
signals:

public slots:
};

#endif // COMPORTSETTING_H

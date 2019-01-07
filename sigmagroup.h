#ifndef SIGMAGROUP_H
#define SIGMAGROUP_H

#include <QObject>
#include "axgroupbase.h"
#include "sigma/sigmacontrol.h"
#include "comportsetting.h"
#include <QKeyEvent>
#define zmaxvalue 41779600
#define xmaxvalue 7260770
#define ymaxvalue 7246810

class sigmaGroup : public axGroupBase
{
    Q_OBJECT
public:
    explicit sigmaGroup(QWidget *parent = nullptr);
    sigmaControl* sigma;
    comPortSetting* cPs;
    void keyPressEvent(QKeyEvent* event);
signals:

public slots:
       void processRmL(int index);
       virtual void processRmR(int index);
       virtual void processAmS(int index);
       virtual void processAmR(int index);
       virtual void doUpdate();
       void updateUI();
       void stop();
};

#endif // SIGMAGROUP_H

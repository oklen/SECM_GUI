#ifndef AXGROUPBASE_H
#define AXGROUPBASE_H

#include <QObject>
#include "axiscontrols.h"
#include <QTimer>
#include "commandtype.h"
#include <QHBoxLayout>
#include <QDebug>
#include "controls.h"
#include <atomic>
#include <QMutex>

class axGroupBase : public QWidget
{
    Q_OBJECT
public:
    explicit axGroupBase(QWidget *parent = nullptr,int interval=100);
    AxisControls* ax[3];
    Controls* controls=nullptr;
    QHBoxLayout *hlayout = new QHBoxLayout;
    const int movet[3][3]={
        {1,0,0},{0,1,0},{0,0,1}
    };
    std::atomic_bool sliderDown;
    ~axGroupBase();
    bool connected = false;
private:
    QTimer timer;
signals:

public slots:
    virtual void processRmL(int index)=0;
    virtual void processRmR(int index)=0;
    virtual void processAmS(int index)=0;
    virtual void processAmR(int index)=0;
    virtual void doUpdate()=0;
    virtual void updateUI()=0;
};

#endif // AXGROUPBASE_H

#ifndef CONTROLS_H
#define CONTROLS_H
#include "commandtype.h"
#include <QLabel>

class Controls:public QObject{
    Q_OBJECT
public:
    virtual void moveA(cmd* cd)=0;
    virtual void moveR(cmd* cd)=0;
    virtual void stop()=0;
    virtual void updatePos()=0;
    virtual void moveDone()=0;
    virtual void returnOrigin()=0;
    virtual bool testStatus()=0;
    virtual ~Controls(){}
    double sPos[3];
signals:
    void posUpdate();
    void workDone();
};

#endif // CONTROLS_H

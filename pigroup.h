#ifndef PIGROUP_H
#define PIGROUP_H

#include <QObject>
#include "axgroupbase.h"
#include "picontorl.h"

class PIGroup : public axGroupBase
{
    Q_OBJECT
public:
    explicit PIGroup(QWidget *parent = nullptr);
    PIContorl *pi;
    ~PIGroup();
signals:

public slots:
    void processRmL(int index);
    void processRmR(int index);
    void processAmS(int index);
    void processAmR(int index);
    void doUpdate();
    void updateUI();
};

#endif // PIGROUP_H

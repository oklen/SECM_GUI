#ifndef PICONTORL_H
#define PICONTORL_H

#include <stdio.h>


#ifdef WIN32a
    #include <conio.h>
    #include <windows.h>
#else
    #include <string.h>
#endif
#include "./PI/PI_GCS2_DLL.h"
#include "controls.h"
#include "threadpool.h"

#include <QDialog>
#include <QDebug>
class PIContorl:public Controls
{
public:
    PIContorl();
    void moveA(cmd* cd);
    void moveR(cmd* cd);
    void stop();
    void updatePos();
    void moveDone();
    void returnOrigin();
    bool testStatus();
    const double *getPos() const;
    ~PIContorl();
    bool autozerodone = false;
    static bool mDone;

    const char *MOV="MOV",*MVR="MVR",*qPOS="qPOS",*StopAll="StopAll",*qsPOS="qPOS",
    *IsMoving="IsMoving",*ATZ="ATZ";
    double vl[3]={3000,3000,3500};
    char DeviceName[35] = "No device Detected";
    friend class PIGroup;
private:
    void _move(double x,double y,double z);
    void interCmd(cmd* cd);
    void errorProcess(const char *cd);

    BOOL bRtoSuccess;
    int ID;
    char szErrorMessage[1024];
    char szUsbController[1024];
    int	iError;
    char szAxes[17];
    double dPos[3];
    BOOL bIsMoving[3];
    BOOL whoUse[3]={true};
    threadPool tp;
};

#endif // PICONTORL_H

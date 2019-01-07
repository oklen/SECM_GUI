#ifndef SIGMACONTROL_H
#define SIGMACONTROL_H
#include <iostream>
#include <fstream>
#include <QDebug>
#include <Windows.h>
#include <unordered_map>
#include "controls.h"
#include "threadpool.h"
#include "comoper.h"


using namespace std;
class sigmaControl:public Controls,public comOper
{
public:
    sigmaControl();
    void write(string command);
    void read();
    void moveA(cmd* cd);
    void moveR(cmd* cd);
    void updatePos();
    void stop();
    void moveDone();
    void returnOrigin();
    bool testStatus();
    int getDig(char*& d);
    void set(int index,int bandrate);
    const char* buffer();
    ~sigmaControl();

    threadPool tp;

private:
    void comMove(cmd* cd,string& commands);
    static bool mDone;
};

#endif // SIGMACONTROL_H

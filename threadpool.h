#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <queue>
#include <thread>
#include <mutex>
#include "controls.h"
#include <Windows.h>
#include <QDebug>

using namespace std;

class threadPool
{
public:
    threadPool(Controls *cts,int interval = 50):cts(cts),interval(interval){
        thread mt(&threadPool::run,this);
        mt.detach();
    }
    void addMission(cmd* command);
    void run();

    mutex  mtx;
private:
    Controls* cts;
    queue<cmd*> cq;
    int interval;
};

#endif // THREADPOOL_H

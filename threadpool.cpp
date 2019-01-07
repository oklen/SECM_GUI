#include "threadpool.h"

void threadPool::addMission(cmd *command)
{
    mtx.lock();
    cq.push(command);
    mtx.unlock();
}

void threadPool::run()
{
    while(true)
    {
        cmd*now =nullptr;
        mtx.lock();
        if(!cq.empty()){now=cq.front();cq.pop();}
        mtx.unlock();
        if(now){
            switch (now->ct) {
            case moveR:
                cts->moveR(now);break;
            case moveA:
                cts->moveA(now);break;
            case updatepos:
                cts->updatePos();
                break;
            case stopa:
                cts->stop();break;
            case returnOrigin:
                cts->returnOrigin();break;
            case exitEx:
                return;
            }
            delete now;
        }
        Sleep(interval);
    }
}

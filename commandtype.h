#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H
#ifndef CHI
#define CHI
#define chi(name) QString::fromLocal8Bit(name)
#endif
#include <iostream>

enum CommandType{
    moveR,
    moveA,
    updatepos,
    stopa,
    moveDone,
    returnOrigin,
    exitEx
};

class cmd{
public:
    CommandType ct;
    cmd(CommandType t):ct(t){}
    virtual ~cmd(){}
};

class sigCommand:public cmd{
public:
    sigCommand(CommandType t,int x=0,int y=0,int z=0):cmd(t),x{x},y{y},z{z}{}
    int x,y,z;
};

class piCommand:public cmd{
public:
    piCommand(CommandType t,double x=0,double y=0,double z=0):cmd(t),x{x},y{y},z{z}{}
    double x,y,z;
};

const char Waxis[3]={'X','Y','Z'};

#endif // COMMANDTYPE_H

#include "sigmacontrol.h"
#ifdef _WIN32

#include "rs232.h"

#include <stdio.h>
#include <string.h>

bool sigmaControl::mDone = false;

void sigmaControl::comMove(cmd *cd, string &commands)
{
    sigCommand* sigcd = dynamic_cast<sigCommand*>(cd);
    commands.append(to_string(sigcd->x));
    commands.push_back(',');
    commands.append(to_string(sigcd->y));
    commands.push_back(',');
    commands.append(to_string(sigcd->z));
    cout << commands << endl;
    write(move(commands));
}

#endif // _WIN32
#undef true
#undef false

sigmaControl::sigmaControl():tp(this)
{
        readParamter();
        comEnumerate();
        comOpen(index,bandrate);

        memset(buf,0,sizeof(buf));
        memset(wbuf,0,sizeof(wbuf));
}

void sigmaControl::write(string cmd)
{
    command.clear();
    command=cmd;
    command.push_back('\r');command.push_back('\n');
    memcpy(wbuf,command.data(),command.size());
    comWrite(index,wbuf,command.size());
}

void sigmaControl::read()
{
    comRead(index,buf,sizeof(buf));
}


void sigmaControl::moveA(cmd* cd)
{
    string commands = "A:";
    comMove(cd,commands);
}

void sigmaControl::moveR(cmd *cd)
{
    string commands = "M:";
    comMove(cd,commands);
}

void sigmaControl::updatePos()
{
    write("Q:");
    read();
    char* cache = buf;
    if(isalpha(cache[0])) return;
    sPos[0] = getDig(cache);
    sPos[1] = getDig(cache);
    sPos[2] = getDig(cache);
    emit posUpdate();
}

void sigmaControl::stop()
{
    write("L:E");
    read();
}

void sigmaControl::moveDone()
{
    write("Q:S");
    read();
    bool mb = true;
    char* cache = buf;
    if(isalpha(cache[0]))return;
    for(int i=0;i<3;++i){
        if(getDig(cache)!=0){mb =false;break;}
    }
    mDone = mb;
}

void sigmaControl::returnOrigin()
{
    write("H:1,1,1");
    read();
}

bool sigmaControl::testStatus()
{
    write("?:N");
    read();
    if(strncmp(buf,"HSC",2)==0)return true;
    return false;
}

int sigmaControl::getDig(char *&in)
{
    char* cache=in;
    while((*cache>='0'&&*cache<='9')||*cache=='-')++cache;
    *cache='\0';
    int result = atoi(in);in=++cache;
    return result;
}

void sigmaControl::set(int ind, int br)
{
    index=ind;br=bandrate;
    comOpen(index,bandrate);
}

const char *sigmaControl::buffer()
{
    return  buf;
}

sigmaControl::~sigmaControl()
{
    disconnect();
}




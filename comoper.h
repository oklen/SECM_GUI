#ifndef COMOPER_H
#define COMOPER_H
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <unordered_map>

using namespace std;
typedef struct {
    int port;
    void * handle=nullptr;
} COMDevice;

/*****************************************************************************/
#define COM_MAXDEVICES 64


#define COM_MINDEVNAME 16384
#pragma comment(lib, "user32.lib")

class comOper
{
public:
    comOper();
    int comEnumerate();
    void comTerminate();
    int comGetNoPorts();
    const char *comGetPortName(int index);
    int comFindPort(const char *name);
    const char *comGetInternalName(int index);
    int comOpen(int index, int baudrate);
    void comClose(int index);
    void comCloseAll();
    int comWrite(int index, const char *buffer, size_t len);
    int comRead(int index, char *buffer, size_t len);
    const char *findPattern(const char *string, const char *pattern, int *value);
    void clearReadBuf();
    void readParamter();
    ~comOper();
    unordered_map<string,int> nameToIndex;
    friend class sigmaControl;
    friend class ControlPad;
    int index,bandrate,stopbits,ByteSize,Parity;
private:
    COMDevice comDevices[COM_MAXDEVICES];

    int noDevices = 0;
    const char * comPtn = "COM???";
    string command;
    char wbuf[64];
    char buf[64];
};

#endif // COMOPER_H

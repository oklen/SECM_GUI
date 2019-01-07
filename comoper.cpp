#include "comoper.h"
#ifdef _WIN32

#include "sigma/rs232.h"

#include <stdio.h>
#include <string.h>

/*****************************************************************************/
#define true    -1
#define false   0

comOper::comOper()
{

}

int comOper::comEnumerate()
{
// Get devices information text
    size_t size = COM_MINDEVNAME;
    char * list = (char *) malloc(size);
    SetLastError(0);
    auto cnts = QueryDosDeviceA(NULL, list, size);
    while (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
        size *= 2;
        char * nlist = (char*)realloc(list, size);
        if (!nlist) {
            free(list);
            return 0;
        }
        list = nlist;
        SetLastError(0);
        QueryDosDeviceA(NULL, list, size);
    }
// Gather all COM ports
    int port;
    const char * nlist = findPattern(list, comPtn, &port);
    noDevices = 0;
    while(port > 0 && noDevices < COM_MAXDEVICES) {
        COMDevice * com = &comDevices[noDevices ++];
        com->port = port;
        if(comGetInternalName(noDevices-1))
        {
            string now = comGetInternalName(noDevices-1);
            while(now[0]!='C')now.erase(now.begin());
            nameToIndex[now]=noDevices-1;
        }
        com->handle  = 0;
        nlist = findPattern(nlist, comPtn, &port);
    }
    free(list);
    return noDevices;
}

void comOper::comTerminate()
{
    comCloseAll();
}

int comOper::comGetNoPorts()
{
    return noDevices;
}

/*****************************************************************************/
const char * comOper::comGetPortName(int index)
{
    #define COM_MAXNAME    32
    static char name[COM_MAXNAME];
    if (index < 0 || index >= noDevices)
        return 0;
    sprintf(name, "COM%i", comDevices[index].port);
    return name;
}

int comOper::comFindPort(const char * name)
{
    for (int i = 0; i < noDevices; i++)
        if (strcmp(name, comGetPortName(i)) == 0)
            return i;
    return -1;
}

const char * comOper::comGetInternalName(int index)
{
    #define COM_MAXNAME    32
    static char name[COM_MAXNAME];
    if (index < 0 || index >= noDevices)
        return 0;
    sprintf(name, "//./COM%i", comDevices[index].port);
    return name;
}

/*****************************************************************************/
int comOper::comOpen(int index, int baudrate)
{
    DCB config;
    COMMTIMEOUTS timeouts;
    if (index < 0 || index >= noDevices)
      return 0;
// Close if already open
    COMDevice * com = &comDevices[index];
    if (com->handle) comClose(index);

// Open COM port
    void * handle = CreateFileA(comGetInternalName(index), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (handle == INVALID_HANDLE_VALUE)
        return 0;
    com->handle = handle;
// Prepare read / write timeouts
    SetupComm(handle, 64, 64);
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutConstant = 1000;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutMultiplier = 0;
    SetCommTimeouts(handle, &timeouts);
// Prepare serial communication format
    GetCommState(handle, &config);
    config.BaudRate = baudrate;
    config.fBinary = 0;
    config.fParity = 0;
    config.fErrorChar = 0;
    config.fNull = 0;
    config.fAbortOnError = 0;
    config.ByteSize = ByteSize;
    config.Parity = Parity;
    config.StopBits = stopbits;
    config.EofChar = '\n';
    config.fNull = 1;
    config.DCBlength=sizeof(DCB);
// Set the port state
    if (SetCommState(handle, &config) == 0) {
        CloseHandle(handle);
        return 0;
    }
    return 1;
}

void comOper::comClose(int index)
{
    if (index < 0 || index >= noDevices)
        return;
    COMDevice * com = &comDevices[index];
    if (!com->handle)
        return;
    CloseHandle(com->handle);
    com->handle = 0;
}

void comOper::comCloseAll()
{
    for (int i = 0; i < noDevices; i++)
        comClose(i);
}

/*****************************************************************************/
int comOper::comWrite(int index, const char * buffer, size_t len)
{
    if (index < 0 || index >= noDevices)
        return 0;
    COMDevice * com = &comDevices[index];
    uint32_t bytes = 0;
    WriteFile(com->handle, buffer, len, (LPDWORD)&bytes, NULL);
    return bytes;
}

int comOper::comRead(int index, char * buffer, size_t len)
{
    if (index < 0 || index >= noDevices)
        return 0;
    COMDevice * com = &comDevices[index];
    uint32_t bytes = 0;
    ReadFile(com->handle, buffer, len, (LPDWORD)&bytes, NULL);
    return bytes;
}

/*****************************************************************************/
const char * comOper::findPattern(const char * string, const char * pattern, int * value)
{
    char c, n = 0;
    const char * sp = string;
    const char * pp = pattern;
// Check for the string pattern
    while (1) {
        c = *sp ++;
        if (c == '\0') {
            if (*pp == '?') break;
            if (*sp == '\0') break;
            n = 0;
            pp = pattern;
        }else{
            if (*pp == '?') {
            // Expect a digit
                if (c >= '0' && c <= '9') {
                    n = n * 10 + (c - '0');
                    if (*pp ++ == '\0') break;
                }else{
                    n = 0;
                    pp = comPtn;
                }
            }else{
            // Expect a character
                if (c == *pp) {
                    if (*pp ++ == '\0') break;
                }else{
                    n = 0;
                    pp = comPtn;
                }
            }
        }
    }
// Return the value
    * value = n;
    return sp;
}

void comOper::clearReadBuf()
{
    memset(buf,0,sizeof(buf));
}

void comOper::readParamter()
{
    ifstream configFile("E:/SECM-User-Interface/Config/SigmaConfig.txt",ios::in);
    configFile>>index>>bandrate>>stopbits>>ByteSize>>Parity;
    configFile.close();
}

comOper::~comOper()
{
    comClose(index);
}

#endif // _WIN32
#undef true
#undef false

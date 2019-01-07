#include "picontorl.h"

bool PIContorl::mDone = true;
PIContorl::PIContorl():tp(this)
{

    /// \brief PI_EnumerateUSB
    qDebug("Connecting Using USB...\n");
    PI_EnumerateUSB(szUsbController, 1024, "PI E-727");
    ID = PI_ConnectUSB(szUsbController);
    if (ID<0)
    {
        iError = PI_GetError(ID);
        PI_TranslateError(iError, szErrorMessage, 1024);
        qDebug("PI_ConnectUSB: ERROR %d: %s\n", iError, szErrorMessage);
        return;
    }
    strncpy(DeviceName,szUsbController,8);
    DeviceName[8]='\0';
    //////////////////////////////////////////
    // Get the names of the connected axes. //
    //////////////////////////////////////////
    if (!PI_qSAI(ID, szAxes, 16))
    {
        iError = PI_GetError(ID);
        PI_TranslateError(iError, szErrorMessage, 1024);
        qDebug("SAI?: ERROR %d: %s\n", iError, szErrorMessage);
        PI_CloseConnection(ID);
        return;
    }
    qDebug(">SAI?:\n%s\n", szAxes);

    // Use only the first 3 axes.
    strcpy(szAxes, "1 2 3");



    /////////////////////////////////////////
    // close the servo loop (closed-loop). //
    /////////////////////////////////////////
    BOOL bFlags[3];

    // Switch on the Servo for all axes
    bFlags[0] = TRUE; // servo on for the axis in the string 'axes'.
    bFlags[1] = TRUE; // servo on for the axis in the string 'axes'.
    bFlags[2] = TRUE; // servo on for the axis in the string 'axes'.

    // call the SerVO mode command.
    if(!PI_SVO(ID, szAxes, bFlags))
    {
        iError = PI_GetError(ID);
        PI_TranslateError(iError, szErrorMessage, 1024);
        qDebug("SVO: ERROR %d: %s\n", iError, szErrorMessage);
        PI_CloseConnection(ID);
        return;
    }
}

void PIContorl::_move(double x, double y, double z)
{
    ////////////////////////////////
    // Now you can move the axes. //
    ////////////////////////////////

    // move all axes the corresponding position in 'dPos'
    dPos[0] = x; // move first axis in the string 'axes' to position 2.0
    dPos[1] = y; // move first axis in the string 'axes' to position 2.0
    dPos[2] = z; // move first axis in the string 'axes' to position 2.0

    // call the MOV command (for closed servo loop).
    if(!PI_MOV(ID, szAxes, dPos))
    {
        iError = PI_GetError(ID);
        PI_TranslateError(iError, szErrorMessage, 1024);
        qDebug("MOV: ERROR %d: %s\n", iError, szErrorMessage);
        PI_CloseConnection(ID);
        return;
    }

    //////////////////////////////////////////////
    // Wait until the closed loop move is done. //
    //////////////////////////////////////////////
    bIsMoving[0] = TRUE;
    while(bIsMoving[0] == TRUE)
    {
        ////////////////////////////////////////////
        // get the current possition of all axes. //
        ////////////////////////////////////////////

        //dPos[0] receives the position of the first axis in the string 'axes'.


        ////////////////////////////////////////
        // Read the moving state of the axes. //
        ////////////////////////////////////////

        // if 'axes' = NULL or 'axis' is empty a general moving state of all axes ist returnd in 'bIsMoving[0]'
        // if 'bIsMoving[0]' = TRUE at least one axis of the controller ist still moving.
        // if 'bIsMoving[0]' = FALSE no axis of the controller is moving.

        // if 'axes != NULL and 'axis' is not empty the moving state of every axis in 'axes' is returned in
        // the array bIsMoving.
        if(!PI_IsMoving(ID, NULL /*axes = NULL*/, bIsMoving))
        {
            iError = PI_GetError(ID);
            PI_TranslateError(iError, szErrorMessage, 1024);
            qDebug("IsMoving: ERROR %d: %s\n", iError, szErrorMessage);
            PI_CloseConnection(ID);
            return;
        }

        qDebug(">POS?: \n1 = %g\n2 = %g\n3 = %g\n\n", dPos[0], dPos[1], dPos[2]);
    }
}

void PIContorl::moveA(cmd *cd)
{
    interCmd(cd);
    // call the MOV command (for closed servo loop).
    if(!PI_MOV(ID, szAxes, dPos))errorProcess(MOV);
}

void PIContorl::moveR(cmd *cd)
{
    interCmd(cd);
    if(!PI_MVR(ID, szAxes, dPos))errorProcess(MVR);
}

void PIContorl::stop()
{
    if(!PI_StopAll(ID))errorProcess(StopAll);
}

void PIContorl::updatePos()
{
    if(!PI_qPOS(ID, szAxes, sPos))errorProcess(qsPOS);
    emit posUpdate();
}

void PIContorl::moveDone()
{
    if(!PI_IsMoving(ID, NULL /*axes = NULL*/, bIsMoving))errorProcess(IsMoving);
    if(!bIsMoving[0]&&!bIsMoving[1]&&!bIsMoving[2])mDone=false;
}

void PIContorl::returnOrigin()
{
    if(!PI_ATZ(ID,szAxes,vl,whoUse)) errorProcess(ATZ);
}

bool PIContorl::testStatus()
{
    if(PI_IsConnected(ID))return true;
    else return false;
}


PIContorl::~PIContorl()
{
    disconnect();
    BOOL bFlags[3]={FALSE};
    if(!PI_SVO(ID,szAxes,bFlags))errorProcess("SVO");
    PI_CloseConnection(ID);
}

void PIContorl::interCmd(cmd *cd)
{
    piCommand* picd = dynamic_cast<piCommand*>(cd);
    dPos[0] = max(picd->x,0);
    dPos[1] = max(picd->y,0);
    dPos[2] = max(picd->z,0);
//    qDebug() << dPos[0] << " "<<dPos[1] << " "<<dPos[2];
}

void PIContorl::errorProcess(const char *cd)
{
    iError = PI_GetError(ID);
    PI_TranslateError(iError, szErrorMessage, 1024);
    qDebug("%s: ERROR %d: %s\n",cd,iError, szErrorMessage);
//    PI_CloseConnection(ID);
    return;
}

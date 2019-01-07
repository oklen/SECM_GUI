#include "jaicontrol.h"

void SetFramegrabberValue(CAM_HANDLE hCam, int8_t* szName, int64_t int64Val, int8_t* sCameraId)
{
    //Set frame grabber value, if applicable
    DEV_HANDLE hDev = NULL; //If a frame grabber exists, it is at the GenTL "local device layer".
    J_STATUS_TYPE retval = J_Camera_GetLocalDeviceHandle(hCam, &hDev);
    if(J_ST_SUCCESS != retval)
        return;

    if(NULL == hDev)
        return;

    NODE_HANDLE hNode;
    retval = J_Camera_GetNodeByName(hDev, szName, &hNode);
    if(J_ST_SUCCESS != retval)
        return;

    retval = J_Node_SetValueInt64(hNode, false, int64Val);
    if(J_ST_SUCCESS != retval)
        return;

    //Special handling for Active Silicon CXP boards, which also has nodes prefixed
    //with "Incoming":
    std::string strTransportName((char*)sCameraId);
    if(std::string::npos != strTransportName.find("TLActiveSilicon"))
    {
        std::string strName((char*)szName);
        if(std::string::npos != strName.find("Width")
            || std::string::npos != strName.find("Height"))
        {
            std::string strIncoming = "Incoming" + strName;
            NODE_HANDLE hNodeIncoming;
            J_STATUS_TYPE retval = J_Camera_GetNodeByName(hDev, (int8_t*)strIncoming.c_str(), &hNodeIncoming);
            if (retval == J_ST_SUCCESS)
            {
                retval = J_Node_SetValueInt64(hNodeIncoming, false, int64Val);
            }
        }

    }//if(std::string::npos != strTransportName.find("TLActiveSilicon"))
}

//Utility function to set the frame grabber's pixel format (if one is present in the system).
void SetFramegrabberPixelFormat(CAM_HANDLE hCam, int8_t* szName, int64_t jaiPixelFormat, int8_t* sCameraId)
{
    DEV_HANDLE hDev = NULL; //If a frame grabber exists, it is at the GenTL "local device layer".
    J_STATUS_TYPE retval = J_Camera_GetLocalDeviceHandle(hCam, &hDev);
    if(J_ST_SUCCESS != retval)
        return;

    if(NULL == hDev)
        return;

    int8_t szJaiPixelFormatName[512];
    uint32_t iSize = 512;
    retval = J_Image_Get_PixelFormatName(hCam, jaiPixelFormat, szJaiPixelFormatName, iSize);
    if(J_ST_SUCCESS != retval)
        return;

    NODE_HANDLE hLocalDeviceNode = 0;
    retval = J_Camera_GetNodeByName(hDev, (int8_t *)"PixelFormat", &hLocalDeviceNode);
    if(J_ST_SUCCESS != retval)
        return;

    if(0 == hLocalDeviceNode)
        return;

    //NOTE: this may fail if the camera and/or frame grabber does not use the SFNC naming convention for pixel formats!
    //Check the camera and frame grabber for details.
    retval = J_Node_SetValueString(hLocalDeviceNode, false, szJaiPixelFormatName);
    if(J_ST_SUCCESS != retval)
        return;

    //Special handling for Active Silicon CXP boards, which also has nodes prefixed
    //with "Incoming":
    std::string strTransportName((char*)sCameraId);
    if(std::string::npos != strTransportName.find("TLActiveSilicon"))
    {
        std::string strIncoming = std::string("Incoming") + std::string((char*)szName);
        NODE_HANDLE hNodeIncoming;
        J_STATUS_TYPE retval = J_Camera_GetNodeByName(hDev, (int8_t*)strIncoming.c_str(), &hNodeIncoming);
        if (retval == J_ST_SUCCESS)
        {
            //NOTE: this may fail if the camera and/or frame grabber does not use the SFNC naming convention for pixel formats!
            //Check the camera and frame grabber for details.
            retval = J_Node_SetValueString(hNodeIncoming, false, szJaiPixelFormatName);
        }
    }
}

void test(J_tIMAGE_INFO *pAqImageInfo)
{
    J_tIMAGE_INFO m_CnvImageInfo; // Image info struct
    if (m_CnvImageInfo.pImageBuffer == NULL)
    {
    if (J_Image_Malloc(pAqImageInfo, &m_CnvImageInfo) != J_ST_SUCCESS)
        return;
    }

    if (m_CnvImageInfo.pImageBuffer != NULL)
    {
        // Convert the raw image to "normalized" image format
        if (J_Image_FromRawToImage(pAqImageInfo, &m_CnvImageInfo) == J_ST_SUCCESS)
            qDebug() << "Image convert!:\nsize:" << m_CnvImageInfo.iImageSize;
       qDebug() << m_CnvImageInfo.pImageBuffer << "\nwidth:" << m_CnvImageInfo.iSizeX << "\nheight" << m_CnvImageInfo.iSizeY;
    }
}

///***************************************************************/
JaiControl::JaiControl()
{

    imgptr = new char[1624*1324*3];
    J_STATUS_TYPE   retval;
    uint32_t        iSize;
    uint32_t        iNumDev;
    bool8_t         bHasChange;

    m_hFactory = NULL;
    memset(rotateArs,0,sizeof(rotateArs));


        retval = J_Factory_Open((int8_t*)"", &m_hFactory);
        qDebug() << retval;

        if (retval == J_ST_SUCCESS)
            qDebug() << "Success!";
        //Update camera list
        retval = J_Factory_UpdateCameraList(m_hFactory, &bHasChange);
        if(retval == J_ST_SUCCESS)
            qDebug() <<  "find camera success";

        //Get the amount of camera
        retval = J_Factory_GetNumOfCameras(m_hFactory, &iNumDev);
        if(retval == J_ST_SUCCESS)
            qDebug() << "Get Camera amount:" << iNumDev;

        //Get camera ID
        retval = J_Factory_GetCameraIDByIndex(m_hFactory, 0, m_sCameraId, &iSize);
        if(retval == J_ST_SUCCESS)
            qDebug() << "Get Camera ID:" << m_sCameraId[0];
        else
            qDebug() << "Can't get camera id!!";
        qDebug() << "Done get Camera ID";
        //Open Camera
        retval = J_Camera_Open(m_hFactory, m_sCameraId, &m_hCam);
        if(retval == J_ST_SUCCESS)
        {
            qDebug() << "Open Camera success!";
            uint32_t numStreams = 0;
            retval = J_Camera_GetNumOfDataStreams(m_hCam, &numStreams);
            camerawstart();
            if(retval != J_ST_SUCCESS)
            {
                qDebug() << "Steam Data Support fail!";
            }
        }
        else
            qDebug() << "Camera open failed!!";


        //Make sure streaming is supported!
//        return;




}

void JaiControl::camerawstart()
{
//    uxCCD->show();
    pBuffer =  ( uchar*)malloc(4343040);
    J_STATUS_TYPE   retval;
    int64_t         int64Val;
    QSize           mywindowsize;

    SIZE	ViewSize;
    RECT	ViewWindowRect;
    POINT	ViewWindowPos;

    //Get Width from the camera
    J_Camera_SetValueInt64(m_hCam, NODE_NAME_WIDTH, 1624);
    J_Camera_GetValueInt64(m_hCam, NODE_NAME_WIDTH, &int64Val);
    mywindowsize.setWidth((LONG)int64Val);
    ViewSize.cx = (LONG)int64Val;
    //1624   1236

    //Get Height from camera
    J_Camera_SetValueInt64(m_hCam, NODE_NAME_HEIGHT, 1236);
    J_Camera_GetValueInt64(m_hCam, NODE_NAME_HEIGHT, &int64Val);
    mywindowsize.setHeight((LONG)int64Val);
    ViewSize.cy =(LONG)int64Val;

    //Set frame grabber dimension, if applicable
    SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);

    SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);

    //Set frame grabber dimension, if applicable
    SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);


    uint uCamNUM;
     retval = J_Camera_GetNumOfDataStreams(m_hCam,&uCamNUM);
     if(retval != J_ST_SUCCESS || uCamNUM == 0)
     {
         qDebug() << "Error to get datastreams!";
         exit(0);
     }
     qDebug() << "Data streams numbers:" << uCamNUM;

     // Get the pixelformat from the camera
     int64_t pixelFormat = 0;
     uint64_t jaiPixelFormat = 0;
     retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_PIXELFORMAT, &pixelFormat);
     J_Image_Get_PixelFormat(m_hCam, pixelFormat, &jaiPixelFormat);

     //Set frame grabber pixel format, if applicable
     SetFramegrabberPixelFormat(m_hCam, NODE_NAME_PIXELFORMAT, pixelFormat, &m_sCameraId[0]);

     // Calculate number of bits (not bytes) per pixel using macro
     int bpp = J_BitsPerPixel(jaiPixelFormat);

     int64_t payloadSize = 0;
     retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_PAYLOADSIZE, &payloadSize);
     if (retval != J_ST_SUCCESS)
     {
         qDebug() << "Unable to get PayloadSize value!";
         return;
     }


//     // Open stream

     retval = J_Image_OpenStream(m_hCam, 0, reinterpret_cast<J_IMG_CALLBACK_OBJECT>(this),reinterpret_cast<J_IMG_CALLBACK_FUNCTION>(&JaiControl::StreamCBFunc), &m_hThread, (uint32_t)(payloadSize)/*(ViewSize.cx*ViewSize.cy*bpp)/8*/);

     retval = J_Camera_ExecuteCommand(m_hCam, NODE_NAME_ACQSTART);

}


void JaiControl::CloseCCD()
{
    uxCCD->stoppaint();
    while(uxCCD->drawing)
        qDebug() << "Wait Draw Done!";

    retval = J_Camera_ExecuteCommand(m_hCam, NODE_NAME_ACQSTOP);
    if(retval != J_ST_SUCCESS)
        qDebug() << "Acquiration close fail";
    else
        qDebug() << "Acquiration Stop Success";
    if(m_hThread)
    {
        retval = J_Image_CloseStream(&m_hThread);
        if(retval != J_ST_SUCCESS)
            qDebug() << "Stream close fail";
        else
            qDebug() << "Stream Stop Success";
    }
    else
        {
        qDebug() << "Thread is NULL";
    }
//    J_Image_Free(&m_CnvImageInfo);
    J_Camera_Close(m_hCam);
    J_Factory_Close(m_hFactory);
}

void JaiControl::StreamCBFunc(J_tIMAGE_INFO *pAqImageInfo)
{
//    if(NeedRead)
//        return;
    if(uxCCD==NULL)return;

    mut.lock();
    uxCCD->count++;
    J_tIMAGE_INFO* &m_CnvImageInfo = rotateArs[abs(uxCCD->count)%60];
    mut.unlock();
    if(uxCCD->count%2)return;
//    if(uxCCD->count % 2 == 0 || uxCCD->count % 3 == 0) return;
    if (m_CnvImageInfo == nullptr /*|| uxCCD->count == 0*/)
    {
         m_CnvImageInfo = (new J_tIMAGE_INFO);
        if (J_Image_Malloc(pAqImageInfo, m_CnvImageInfo) != J_ST_SUCCESS)
            return;
    }

    if (m_CnvImageInfo->pImageBuffer != nullptr)
    {
        // Convert the raw image to "normalized" image format
        if (J_Image_FromRawToImageEx(pAqImageInfo, m_CnvImageInfo, BAYER_EXTEND_MULTI) != J_ST_SUCCESS)
            exit(0);
    }
    else qDebug() << "Error No Buffer!";

     MapView((int)m_CnvImageInfo->iSizeX,(int)m_CnvImageInfo->iSizeY,m_CnvImageInfo->pImageBuffer);

if(!beginSend)
    return;
}

void JaiControl::InitCCD()
{
    J_STATUS_TYPE   retval;
    uint32_t        iSize;
    uint32_t        iNumDev;
    bool8_t         bHasChange;

    m_hFactory = NULL;



        retval = J_Factory_Open((int8_t*)"", &m_hFactory);
        qDebug() << retval;

        if (retval == J_ST_SUCCESS)
            qDebug() << "Success!";
        //Update camera list
        retval = J_Factory_UpdateCameraList(m_hFactory, &bHasChange);
        if(retval == J_ST_SUCCESS)
            qDebug() <<  "find camera success";

        //Get the amount of camera
        retval = J_Factory_GetNumOfCameras(m_hFactory, &iNumDev);
        if(retval == J_ST_SUCCESS)
            qDebug() << "Get Camera amount:" << iNumDev;

        //Get camera ID
        retval = J_Factory_GetCameraIDByIndex(m_hFactory, 0, m_sCameraId, &iSize);
        if(retval == J_ST_SUCCESS)
            qDebug() << "Get Camera ID:" << m_sCameraId[0];

        //Open Camera
        retval = J_Camera_Open(m_hFactory, m_sCameraId, &m_hCam);
        if(retval == J_ST_SUCCESS)
            qDebug() << "Open Camera success!";

        //Make sure streaming is supported!
        uint32_t numStreams = 0;
        retval = J_Camera_GetNumOfDataStreams(m_hCam, &numStreams);
        if(retval != J_ST_SUCCESS)
        {
            qDebug() << "Steam Data Support fail!";
            return;
        }
}

void JaiControl::OpenCCD()
{
    J_STATUS_TYPE   retval;
    int64_t int64Val;
    QSize mywindowsize;

    SIZE	ViewSize;
    RECT	ViewWindowRect;
    POINT	ViewWindowPos;

    //Get Width from the camera
    J_Camera_GetValueInt64(m_hCam, NODE_NAME_WIDTH, &int64Val);
    mywindowsize.setWidth((LONG)int64Val);
    ViewSize.cx = (LONG)int64Val;

    //Get Height from camera
    J_Camera_GetValueInt64(m_hCam, NODE_NAME_HEIGHT, &int64Val);
    mywindowsize.setHeight((LONG)int64Val);
    ViewSize.cy =(LONG)int64Val;

    //Set frame grabber dimension, if applicable
    SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);


    uint uCamNUM;
     J_Camera_GetNumOfDataStreams(m_hCam,&uCamNUM);

     // Get the pixelformat from the camera
     int64_t pixelFormat = 0;
     uint64_t jaiPixelFormat = 0;
     retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_PIXELFORMAT, &pixelFormat);
     J_Image_Get_PixelFormat(m_hCam, pixelFormat, &jaiPixelFormat);

     //Set frame grabber pixel format, if applicable
     SetFramegrabberPixelFormat(m_hCam, NODE_NAME_PIXELFORMAT, pixelFormat, &m_sCameraId[0]);

     // Calculate number of bits (not bytes) per pixel using macro
     int bpp = J_BitsPerPixel(jaiPixelFormat);

     retval = J_Image_OpenStream(m_hCam, 0, reinterpret_cast<J_IMG_CALLBACK_OBJECT>(this),reinterpret_cast<J_IMG_CALLBACK_FUNCTION>(&JaiControl::StreamCBFunc), &m_hThread, (ViewSize.cx*ViewSize.cy*bpp)/8);

     retval = J_Camera_ExecuteCommand(m_hCam, NODE_NAME_ACQSTART);
}

void JaiControl::ReadCCD(int width, int height,  uchar **buffer)
{
    mwidth = width;
    mheight = height;
    NeedRead = true;
    uxCCD->mutex.lock();
//    mem(buffer,pBuffer,4343040*8);
    *buffer =  pBuffer;
    uxCCD->mutex.unlock();
//    QImage img = QImage(*buffer,1392,1040,QImage::Format_RGB888).scaled(width,height);
//    *buffer = img.bits();
    NeedRead = false;
}

inline void JaiControl::MapView(int sizex, int sizey, void *buffer)
{
    uxCCD->xcount = sizex;
    uxCCD->ycount = sizey;
    uxCCD->dataarray = buffer;
    uxCCD->toggle = true;
    uxCCD->update();
    uxCCD->doupdate();

    if(uxCCD->shouldclose)
        CloseCCD();
}

JaiControl::~JaiControl()
{
    J_DataStream_Close(m_hView);
    J_Camera_Close(m_hCam);
    J_Factory_Close(m_hFactory);
}


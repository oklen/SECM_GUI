
//#include "UXMSGR.h"

//template<class T>
//T Msg_Process(T* msgtype,LPVOID m)
//{
//    T data;
//    ::CopyMemory(&data, m, sizeof(T));
//    return data;
//}

//AfmMsgGUI::AfmMsgGUI(QWidget* parent)
//    :QWidget(parent)
//{
//    hWnd = (HWND)winId();
//    //To Debug Local with AfmMsgWndWrite Uset his!
////    setWindowTitle(QString("AfmMsgWndRead"));
//      setWindowTitle(QString("AfmMsgWndWrite")); //Deploy Name

//    LPCTSTR lpName;

//    lpName = TEXT("ParamTunnel1");

//    handle1 = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, lpName);
//    if (handle1 == NULL)
//    {
//        handle1 = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0, sizeof(AFM_MSG_PARAM), lpName);
//        if (handle1 == NULL)
//            return;
//    }
//    value1 = ::MapViewOfFile(handle1, FILE_MAP_ALL_ACCESS, 0, 0, 0);

//    lpName = TEXT("ParamTunnel2");
//    handle2 = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, lpName);
//    if (handle2 == NULL)
//    {
//        handle2 = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0, sizeof(AFM_MSG_PARAM), lpName);
//        if (handle2 == NULL)
//            return;
//    }
//    value2 = ::MapViewOfFile(handle2, FILE_MAP_ALL_ACCESS, 0, 0, 0);
////    hide();
//}

//bool AfmMsgGUI::nativeEvent(const QByteArray &eventType, void *message, long *result)
//{
//    MSG* pMsg = static_cast<MSG*>(message);
//    UINT MsgID = pMsg->message;
//    switch(MsgID)
//    {
//    case AFM_MSG_GP_SATRT_DEVICE:
//        AFM_MSG_PG_FOUR_QUAD_DATA_PARAM param;
//        qDebug() <<  "ID:" << (uint)hWnd << " receive:" << "AFM_MSG_GP_SATRT_DEVICE";
//        break;
//    case AFM_MSG_PG_FOUR_QUAD_DATA:
//        emit FOUR_QUAD_DATA(Msg_Process((AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA)*)(nullptr),value1));
//        break;
//    case AFM_MSG_PG_SCAN_DATA:
//        emit SCAN_DATA(Msg_Process((AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA)*)(nullptr),value1));
//        break;
//    case AFM_MSG_PG_OVER_LINE:
//        emit OVER_LINE();
//        break;
//    case AFM_MSG_PG_OVER_SCAN:
//        emit OVER_SCAN(Msg_Process((AFM_MSG_PARAM(AFM_MSG_PG_OVER_SCAN)*)(nullptr),value1));
//        break;
//    case AFM_MSG_PG_PROBE_COOR:
//        emit PROBE_COOR(Msg_Process((AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR)*)(nullptr),value1));
//        break;
//    case AFM_MSG_PG_SAMPLE_COOR:
//        emit SAMPLE_COOR(Msg_Process((AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR)*)(nullptr),value1));
//        break;
//    case AFM_MSG_GP_AUTO_END:
//        emit AUTO_PROBE_RESULT(Msg_Process((AFM_MSG_PARAM(AFM_MSG_GP_AUTO_END)*)(nullptr),value1));
//        break;
//    case AFM_MSG_GP_SENT_CCD_IMG:
//    {
//        qDebug() << "Receive Message!!";
//        AFM_MSG_PARAM(AFM_MSG_GP_SENT_CCD_IMG) mdata = Msg_Process((AFM_MSG_PARAM(AFM_MSG_GP_SENT_CCD_IMG)*)(nullptr),value2);
//        mydata =  mdata.CCDImg;
////        mimage = QImage(mydata,1392,1040,QImage::Format_RGB888);
//        repaint();
//    }
//        break;
//    default:
//        break;
//}
//    return QWidget::nativeEvent(eventType, message, result);

//}

//void AfmMsgGUI::mousePressEvent(QMouseEvent *event())
//{
//}

//void AfmMsgGUI::paintEvent(QPaintEvent *event)
//{
//if(mydata == nullptr)
//{
//    qDebug() << "mydata is nullptr";
//    return;
//}
//    QPainter mpainter;
//    mpainter.begin(this);
//    qDebug() << "should repinter";
////    QPixmap map(100,100);
////    map.fill(Qt::red);
//    mpainter.drawPixmap(0,0,1392/1.65,1040/1.65,
//            QPixmap::fromImage
//            (QImage(mydata,1392,1040,QImage::Format_RGB888)));
//    mpainter.end();
//}

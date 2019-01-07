//// AfmMsgGUI.h
//#ifndef AFM_MESSAGE_H
//#define AFM_MESSAGE_H
//#pragma comment(lib, "user32.lib")
//#include <qt_windows.h>
//#include "include/AfmMessage.h"
//#include <QWidget>
//#include <QDebug>
//#include <QLabel>
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QPainter>
//#include <QImage>


//class AfmMsgGUI: public QWidget
//{
//    Q_OBJECT
//public:
//     AfmMsgGUI(QWidget *parent = 0);

//    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
//    void mousePressEvent(QMouseEvent *event());
//    HWND hWnd;
//    QImage mimage;
//    void paintEvent(QPaintEvent *event);

//private:
//    int i;
//    HANDLE handle1;
//    LPVOID value1;
//    HANDLE handle2;
//    LPVOID value2;
//    uchar* mydata = nullptr;
//signals:
//    void FOUR_QUAD_DATA(AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA));
//    void SCAN_DATA( AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA));
//    void OVER_LINE();
//    void OVER_SCAN(AFM_MSG_PARAM(AFM_MSG_PG_OVER_SCAN));
//    void PROBE_COOR(AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR));
//    void SAMPLE_COOR(AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR));
//    void AUTO_PROBE_RESULT(AFM_MSG_PARAM(AFM_MSG_GP_AUTO_END));
//};
//#endif

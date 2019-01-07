//#ifndef UXPAINTHREAD_H
//#define UXPAINTHREAD_H

//#include <QObject>
//#include <QThread>
//#include <QPixmap>

//#include "jai_factory.h"
////#include <GDIPLUS.H>
//#include <STRSAFE.H>

//class UXPAINTHREAD : public QThread
//{
//    Q_OBJECT
//public:
//    explicit UXPAINTHREAD(QThread *parent = nullptr);
//    UXPAINTHREAD(J_tIMAGE_INFO *inimage)
//    {imageinfo = inimage;}
//    QPixmap map;
//    const uchar* data;
//    J_tIMAGE_INFO *imageinfo;
//    void run()
//    {
//        //1624   1236
//        //wait(100000);
//        sleep(2);
//        if (imageinfo->pImageBuffer != NULL &&   imageinfo->iImageSize == 6021792)
//           J_Image_Free(imageinfo);

////        map = QPixmap::fromImage
////                (QImage(data,1624,1236,QImage::Format_RGB888))
////                .scaled(1624/1.65,1236/1.65);
//    }

//signals:

//public slots:
//};

//#endif // UXPAINTHREAD_H

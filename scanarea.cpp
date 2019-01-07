#include "scanarea.h"

scanarea::scanarea(QWidget *parent) : QWidget(parent),
    sizel{new QLabel(this)},processel{new selecter(this)},mp{new QPixmap}
{
    //scana,sizel;
    QPalette pa;int submovex = 12;

    pa.setColor(QPalette::WindowText,QColor(165,165,165));
    sizel->setText(chi("Z轴高度  5.000 x 5.000 μm(256 x 256 pixels)"));
    sizel->setFont(QFont("SourceCode Pro",12));
    sizel->setPalette(pa);
    sizel->move(30,30);
    sizel->setWindowOpacity(0);

    processel->addSelect(chi("平滑"));
    processel->addSelect(chi("还原"));
    processel->resize(230,30);
    processel->move(480,21);

    mp->load("E:/SECM-User-Interface/scanarea.jpg");
    float times= 1.6f;
    *mp = mp->scaled(mp->width()*times,mp->height()*times);
    imgPos = QPoint(158,78);
    barPos = QPoint(30,338);
    btPos  = barPos + QPoint(50,50);
    btPos = QPoint(btPos.y(),btPos.x());
    btPos.setY(-btPos.y());

    barwidth = 40,barheight = 180;
    barcolor.setStart(barPos);
    barcolor.setColorAt(0,QColor(230,230,220));
    barcolor.setColorAt(0.5,QColor(190,140,10));
    barcolor.setColorAt(1,QColor(70,0,0));
    barcolor.setFinalStop(barPos+QPoint(barwidth,barheight));
}

void scanarea::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.setBrush(QColor(59,59,59));
    QRect rec = rect();rec.setHeight(height()-1);
    rec.setWidth(width()-1);
    mpainter.setPen(QColor(91,94,99));
    mpainter.drawRect(rec);
    mpainter.setBrush(QBrush(QColor(165,165,165)));

    mpainter.drawRect(QRect(imgPos-QPoint(2,2),QPoint(mp->width()+imgPos.x(),mp->height()+imgPos.y())));
    mpainter.drawPixmap(imgPos,*mp);
    mpainter.setBrush(QBrush(barcolor));
    mpainter.drawRect(barPos.x(),barPos.y(),barwidth,barheight);
    mpainter.setPen(Qt::white);
    mpainter.rotate(90);

    mpainter.setFont(QFont("Source Code Pro",12));
    mpainter.drawText(btPos,chi("100nm / div "));
    mpainter.end();
}


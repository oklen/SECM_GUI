#include "leftstatus.h"

LeftStatus::LeftStatus(QWidget *parent) : QWidget(parent)
{
    mp = QPixmap("E:/SECM-User-Interface/n1.jpg");
    for(int i = 0;i<4;++i)
    {
        pp[i].setParent(this);
        pp[i].move(30,80+110*i);
        pp[i].setFixedSize(QSize(100,100));
        pp[i].setFont(QFont("SourceCode Pro",15));

//        pp[i].setForegroundColor(QColor(255, 0, 0, 127));
//        pp[i].setUseThemeColors(true);

    }
     pp[0].setText(chi("进针"));
     pp[0].setBackgroundColor(QColor("#87CEEB"));
     pp[1].setText(chi("定位"));
     pp[1].setBackgroundColor(QColor(43,65,114));
     pp[2].setText(chi("扫描"));
     pp[2].setBackgroundColor(QColor(102,45,142));
     pp[3].setText(chi("退针"));
     pp[3].setBackgroundColor(QColor(0,103,56));
//    pp[0].setIcon(QIcon("E:/SECM-User-Interface/lambda.png"));
//    pp[0].setIconSize(pp[0].size()*1.2);

}

void LeftStatus::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.drawPixmap(QPoint(0,mp.size().height()-3),mp);
    mpainter.drawPixmap(QPoint(0,-1),mp);
    QPen mpen(QColor(91,94,99));mpen.setWidth(3);
    mpainter.setPen(mpen);
    mpainter.drawLine(QLine(width(),0,width(),height()));
    mpainter.end();
}

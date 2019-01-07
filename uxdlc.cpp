#include "uxdlc.h"

UXDLC::UXDLC(QWidget *parent) : QChartView(parent)
//    ,gpix{new QGraphicsPixmapItem(this)}
{
    UXDL *chart = new UXDL;
    setWindowOpacity(0);
//    chart->setTitle("Dynamic spline chart");
    chart->legend()->setColor(Qt::white);
    chart->legend()->setLabelColor(Qt::white);
    QTransform transform;
    transform.scale(1.3,1.3);
    transform.translate(100,5);
    chart->legend()->setTransform(transform);
    transform.reset();
    transform.scale(1.08,1.1);
    transform.translate(-30,-18);

    chart->axisX()->setLabelsFont(QFont("Source Code Pro",9));
    chart->axisY()->setLabelsFont(QFont("Source Code Pro",9));
    chart->axisX()->setLabelsBrush(QColor(169,169,169));
    chart->axisY()->setLabelsBrush(QColor(169,169,169));
    chart->axisX()->setTitleBrush(QColor(169,169,169));
    chart->axisY()->setTitleBrush(QColor(169,169,169));
    chart->axisX()->setTitleText(chi("μm"));
    chart->axisY()->setTitleText(chi("10nm/div"));
//    chart->setAnimationOptions(QChart::SeriesAnimations);
    setChart(chart);
//    chart->setTransform(transform); //Different happened
    setRenderHint(QPainter::Antialiasing);
    setAutoFillBackground(true);
}

//void UXDLC::mousePressEvent(QMouseEvent *event)
//{
//    emit bepressed();
//    raise();
//        mousedown = true;
//        hotpot = event->pos();
//}

//void UXDLC::mouseReleaseEvent(QMouseEvent *event)
//{

//    qDebug() << "Child Release";
//    mousedown = false;
//}

//void UXDLC::mouseMoveEvent(QMouseEvent *event)
//{
//    if (mousedown && QRect(0,0,1000,800).contains(this->pos()+event->pos()-hotpot)){
//        qDebug() << "Move!";
//        this->move(this->pos()+event->pos()-hotpot);
//    }
//    else
//    {
//        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
//                                                     +QPoint((event->pos()-hotpot).x(),0)))
//            this->move(this->pos()+QPoint((event->pos()-hotpot).x(),0));
//        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
//                                                     +QPoint(0,(event->pos()-hotpot).y())))
//            this->move(this->pos()+QPoint(0,(event->pos()-hotpot).y()));
//    }
//    qDebug() << "this pos:" << this->pos() << " "
//             << "event pos:" << event->pos() << " "
//             << "hotpot:" << hotpot;
//}

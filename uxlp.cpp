#include "uxlp.h"

UXLP::UXLP(QWidget *parent) : QWidget(parent)
{
    setFixedSize(length,length);
}

void UXLP::paintEvent(QPaintEvent *event)
{
    QPen mpen;
    QPainter mpainter(this);
    mpainter.setRenderHint(QPainter::Antialiasing);
    mpainter.setBrush(QBrush(QColor(0,0,0,40)));
    mpen.setColor(QColor(0,0,0,40));
    mpainter.setPen(mpen);
    mpainter.drawRect(rect());
    mpen.setColor(Qt::white);
    mpainter.setPen(mpen);
    mpainter.drawLine(QPoint(width()/2,0),QPoint(width()/2,height()));
    mpainter.drawLine(QPoint(0,height()/2),QPoint(width(),height()/2));
    mpainter.setBrush(QBrush(QColor(Qt::green)));
    mpen.setColor(Qt::green);
    mpainter.setPen(mpen);
    mpainter.drawEllipse(QPoint(length/2+calcenter(inputx),length/2+calcenter(inputy)),potr,potr);

    mpainter.end();
}

float UXLP::calcenter(float input)
{
    float v = input;
    int singal = 1;
    if (v < 0)
        singal = -1;
    if (std::abs(v) > 1)
        return singal*100;
    float x = (1 - std::sqrt(1-std::abs(v)))*100;
    return x*singal;
}

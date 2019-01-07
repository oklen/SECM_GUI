#include "tabb.h"

tabb::tabb(QWidget *parent) : QWidget(parent),content{"Scan"}
{
    //resize(150,50);
    mps = QPixmap("E:/SECM-User-Interface/bcc3.png");
    //setMask(mps.scaled(width(),height()));
//   setAutoFillBackground(true);
   //setMask(mps.mask());
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);

   shadow_effect->setOffset(0, -2);

    shadow_effect->setColor(Qt::black);

    shadow_effect->setBlurRadius(8);

    this->setGraphicsEffect(shadow_effect);
}

void tabb::paintEvent(QPaintEvent *event)
{
    QPainter mp(this);
    if(isable)
    {
        raise();
        mp.setBrush(QColor(144,148,160));
        if(childshow)childshow->show();
    }
    else
    {
        mp.setBrush(QColor(112,116,125));
        if(childshow)childshow->hide();
    }
    mp.drawRect(rect());
    mp.setRenderHint(QPainter::TextAntialiasing);
    mp.setFont(QFont("SourceCode Pro", 20, QFont::Bold));
    mp.setPen(Qt::white);
    mp.drawText(QPoint{60,35},content);
    mp.end();
}

void tabb::mousePressEvent(QMouseEvent *event)
{
    if(event->type()==QMouseEvent::MouseButtonPress)
    {
        isable = 2;update();
        emit doreset();
    }
}

void tabb::resizeEvent(QResizeEvent *event)
{
  setMask(mps.scaled(width(),height()));
}

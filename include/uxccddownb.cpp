#include "uxccddownb.h"

UXCCDDOWNB::UXCCDDOWNB(QWidget *parent) : QPushButton(parent)
{
    installEventFilter(this);
    setFixedSize(170,60);
}

void UXCCDDOWNB::paintEvent(QPaintEvent *event)
{
    QPainter mpainter;
    mpainter.begin(this);
    mpainter.setRenderHint(QPainter::Antialiasing);
    mpainter.setBrush(QBrush(QColor(255,255,255,100)));
    if(lighting)
    {QPen mpen1;
        mpen1.setColor(QColor(255,255,255,50));
        mpainter.setPen(mpen1);
        mpainter.drawRect(rect());
    }
    QPen mpen(Qt::white,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    mpainter.setPen(mpen);
    mpainter.drawLine(QPoint(10,50+downzoom),QPoint(85,10+downzoom));
    mpainter.drawLine(QPoint(85,10+downzoom),QPoint(85+75,50+downzoom));
    mpainter.end();

}

bool UXCCDDOWNB::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QMouseEvent::Enter && watched == this)
    {
        lighting = true;
        update();
    }
    if(event->type() == QMouseEvent::Leave && watched == this)
    {
        lighting = false;
        update();
    }
    if((event->type() == QMouseEvent::MouseButtonPress ||
        event->type() == QMouseEvent::MouseButtonDblClick )&& watched == this)
    {
        downzoom = -8;
        update();
    }
    if(event->type() == QMouseEvent::MouseButtonRelease && watched == this)
    {
        downzoom = 0;
        update();
    }
    return false;
}

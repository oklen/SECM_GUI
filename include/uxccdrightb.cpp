#include "uxccdrightb.h"

uxccdrightb::uxccdrightb(QWidget *parent) : QPushButton(parent)
{
    installEventFilter(this);
    setFixedSize(60,170);
}

void uxccdrightb::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
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
    mpainter.drawLine(QPoint(10+leftzoom,10),QPoint(50+leftzoom,85));
    mpainter.drawLine(QPoint(50+leftzoom,85),QPoint(10+leftzoom,85+75));
    mpainter.end();

}

bool uxccdrightb::eventFilter(QObject *watched, QEvent *event)
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
        leftzoom = 8;
        update();
    }
    if(event->type() == QMouseEvent::MouseButtonRelease && watched == this)
    {
        leftzoom = 0;
        update();
    }
    return false;
}

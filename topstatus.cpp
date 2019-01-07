#include "topstatus.h"

topstatus::topstatus(QWidget *parent) : QWidget(parent)
{
    installEventFilter(this);
    mp = QPixmap("E:/SECM-User-Interface/n2.jpg");
    for(int i = 0;i<4;++i)
    {
        tb[i].resize(180,50);
        tb[i].move(1140+170*i,0);
        tb[i].setParent(this);
        connect(tb+i,SIGNAL(doreset()),this,SLOT(pushreset()));
    }
    tb[0].content = chi("扫描");
    tb[1].content = chi("调试");
    tb[2].content = chi("设置");
    tb[3].content = chi("帮助");
    setMouseTracking(true);
}

void topstatus::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    //mpainter.setBrush(Qt::white);
    mpainter.setPen(Qt::white);
    mpainter.drawPixmap(rect(),mp);
    QRect rc = rect();rc.moveTop(-1);
    mpainter.drawRect(rc);
    QPen mpen(Qt::white);
    mpainter.setRenderHint(QPainter::TextAntialiasing);
    mpainter.setFont(QFont("SourceCode Pro", 30, QFont::Bold));
    mpainter.drawText(QPoint{200,37},QString ("ChangLi Nano"));
    mpainter.end();
}

void topstatus::pushreset()
{
    for(int i = 0;i<4;++i)
    {
        if(tb[i].isable>0)
        --tb[i].isable;
        tb[i].update();
    }
}

#include "selecter.h"

selecter::selecter(QWidget *parent) : QWidget(parent)
{
    setLayout(&hl);
}

void selecter::addSelect(int value)
{
    QtMaterialRaisedButton* rb = new QtMaterialRaisedButton;
    rb->setForegroundColor(QColor(168,168,168));
    rb->setBackgroundColor(QColor(0,0,0,0));
    rb->setBorderWidth(1);
    rb->setText(QString::number(value)+suffix);
    rb->setHaloVisible(false);
    int now = hlsize;ele[now] = rb;inved[now] = value;
    connect(rb,&QtMaterialRaisedButton::clicked,[this,now](){
        nv = inved[now];
        for(int i =  0;i<hlsize;i++)
        {ele[i]->setBackgroundColor(QColor(0,0,0,0));
        ele[i]->setForegroundColor(QColor(168,168,168));}
        ele[now]->setBackgroundColor(QColor("#EE5C42"));
        ele[now]->setForegroundColor(Qt::white);
    });
    ++hlsize;
    hl.addWidget(rb);
}

void selecter::addSelect(QString value)
{
    QtMaterialRaisedButton* rb = new QtMaterialRaisedButton;
    rb->setForegroundColor(QColor(168,168,168));
    rb->setBackgroundColor(QColor(0,0,0,0));
    rb->setBorderWidth(1);
    rb->setText(value);
    rb->setHaloVisible(false);
    int now = hlsize;ele[now] = rb;
    connect(rb,&QtMaterialRaisedButton::clicked,[this,now](){
        //nv = inved[now];
        for(int i =  0;i<hlsize;i++)
        {ele[i]->setBackgroundColor(QColor(0,0,0,0));
        ele[i]->setForegroundColor(QColor(168,168,168));}
        ele[now]->setBackgroundColor(QColor("#EE5C42"));
        ele[now]->setForegroundColor(Qt::white);
    });
    ++hlsize;
    hl.addWidget(rb);
}

void selecter::resizeEvent(QResizeEvent *event)
{
    for(int i = 0;i<hlsize;++i)
    {
        ele[i]->setFixedHeight(event->size().height()-9);
    }
}

int selecter::getvalue()
{
    return nv;
}

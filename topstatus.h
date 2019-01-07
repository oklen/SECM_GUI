#ifndef TOPSTATUS_H
#define TOPSTATUS_H

#include <QWidget>
#include <QPainter>
#include <tabb.h>
#include <QMouseEvent>
#include "commandtype.h"

class topstatus : public QWidget
{
    Q_OBJECT
public:
    explicit topstatus(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    tabb tb[4];
    QPixmap mp;
signals:

public slots:
    void pushreset();
};

#endif // TOPSTATUS_H

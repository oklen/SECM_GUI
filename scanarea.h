#ifndef SCANAREA_H
#define SCANAREA_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QLinearGradient>
#include "selecter.h"
#ifndef chi
#define chi(name) QString::fromLocal8Bit(name)
#endif
class scanarea : public QWidget
{
    Q_OBJECT
public:
    explicit scanarea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    QPixmap *mp;
    QLabel *sizel;
    QPoint imgPos;
    QPoint barPos,btPos;
    QLinearGradient barcolor;
    selecter *processel;
    int barheight,barwidth;
signals:

public slots:
};

#endif // SCANAREA_H

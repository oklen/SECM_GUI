//UX_dynamic Line Container
#ifndef UXDLC_H
#define UXDLC_H

#include <QWidget>
#include <QtCharts>
#include <QGraphicsPixmapItem>

#include "./Qt-project/uxdl.h"

QT_CHARTS_USE_NAMESPACE

class UXDLC : public QChartView
{
    Q_OBJECT
public:
    explicit UXDLC(QWidget *parent = nullptr);

//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);


signals:
    void bepressed();

public slots:

private:
    QPoint hotpot;
    bool mousedown = false;
    QGraphicsPixmapItem *gpix;
};

#endif // UXDLC_H

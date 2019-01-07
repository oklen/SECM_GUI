#ifndef TABB_H
#define TABB_H

#include <QWidget>
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
class tabb : public QWidget
{
    Q_OBJECT
public:
    explicit tabb(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent* event);
    int isable = 0;bool haveMasked = false;
    QWidget *childshow=NULL;
    QPixmap mps;
    QString content;
signals:
    void doreset();
public slots:
//    void getreset();
};

#endif // TABB_H

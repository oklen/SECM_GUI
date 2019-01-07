#ifndef UXCCDUPB_H
#define UXCCDUPB_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>

class UXCCDUPB : public QPushButton
{
    Q_OBJECT
public:
    explicit UXCCDUPB(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    bool lighting = false;

    int downzoom = 0;

signals:

public slots:
};

#endif // UXCCDUPB_H

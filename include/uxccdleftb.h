#ifndef UXCCDLEFTB_H
#define UXCCDLEFTB_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class UXCCDLEFTB : public QPushButton
{
    Q_OBJECT
public:
    explicit UXCCDLEFTB(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    bool lighting = false;

    int leftzoom = 0;
signals:

public slots:
};

#endif // UXCCDLEFTB_H

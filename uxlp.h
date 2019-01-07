#ifndef UXLP_H
#define UXLP_H

#include <QWidget>
#include <QPainter>
#include <cmath>

//Calculate the light point show in four axis and the show window
class UXLP : public QWidget
{
    Q_OBJECT
public:
    explicit UXLP(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    float calcenter(float input);

    float inputx = 0.0;
    float inputy = 0.0;
    int length = 100;
    int potr = 5;

signals:

public slots:
//    void doupdate();
};
#endif
 // UXLP_H

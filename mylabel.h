#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPainter>

class mylabel : public QLabel
{
public:
    explicit mylabel(QWidget *parnet = 0,int fontsize =15);
};

#endif // MYLABEL_H

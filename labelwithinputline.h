#ifndef LABELWITHINPUTLINE_H
#define LABELWITHINPUTLINE_H

#include <QWidget>
#include "mylabel.h"
#include "uxinputline.h"
#include <QHBoxLayout>

class labelWithInputline : public QWidget
{
    Q_OBJECT
public:
    explicit labelWithInputline(QWidget *parent = nullptr);
    mylabel *label,*label2;
    uxinputline *inputline;
signals:

public slots:
};

#endif // LABELWITHINPUTLINE_H

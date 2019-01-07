#ifndef LEFTSTATUS_H
#define LEFTSTATUS_H

#include <QWidget>
#include <QPushButton>
#include "qt-material-widgets/components/qtmaterialraisedbutton.h"
#include <QPushButton>
#include <QPainter>
#include "commandtype.h"

class LeftStatus : public QWidget
{
    Q_OBJECT
public:
    explicit LeftStatus(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    QPixmap mp;
    QtMaterialRaisedButton pp[4];
signals:

public slots:
};

#endif // LEFTSTATUS_H

#ifndef FILEOPR_H
#define FILEOPR_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include "selecter.h"
#include "qt-material-widgets/components/qtmaterialtextfield.h"
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>

#ifndef chi
#define chi(name) QString::fromLocal8Bit(name)
#endif


class fileopr : public QWidget
{
    Q_OBJECT
public:
    explicit fileopr(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);

    QLabel scanconfig,dataLocation,pixel,scansize,filename,directory;
    QtMaterialTextField name,dir;
    QtMaterialRaisedButton *select,*explore;
    selecter selpixel,selss;
signals:

public slots:
};

#endif // FILEOPR_H

#ifndef SELECTER_H
#define SELECTER_H

#include <QWidget>
#include <QLayout>
#include <QBoxLayout>
#include <QResizeEvent>
#include "qt-material-widgets/components/qtmaterialraisedbutton.h"
class selecter : public QWidget
{
    Q_OBJECT
public:
    explicit selecter(QWidget *parent = nullptr);
    void addSelect(int value);
    void resizeEvent(QResizeEvent *event);
    int inved[10],nv;
    QtMaterialRaisedButton* ele[10];
    QHBoxLayout hl;
    int getvalue();
    int hlsize = 0;
    QString suffix;
    void addSelect(QString value);
signals:

public slots:
};

#endif // SELECTER_H

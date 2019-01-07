#ifndef UXCCDDOWNB_H
#define UXCCDDOWNB_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QPushButton>



class /*QDESIGNER_WIDGET_EXPORT*/ UXCCDDOWNB : public QPushButton
{
    Q_OBJECT
public:
    explicit UXCCDDOWNB(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    bool lighting = false;

    int downzoom = 0;
signals:

public slots:
};

#endif // UXCCDDOWNB_H

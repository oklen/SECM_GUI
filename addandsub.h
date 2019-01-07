#ifndef ADDANDSUB_H
#define ADDANDSUB_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class ADDandSub : public QWidget
{
    Q_OBJECT
public:
    explicit ADDandSub(QWidget *parent = nullptr);
    QPushButton *add,*sub;
signals:

public slots:
};

#endif // ADDANDSUB_H

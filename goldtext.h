#ifndef GOLDTEXT_H
#define GOLDTEXT_H

#include<QFont>
#include <QLabel>
#include <QWidget>

class goldtext : public QLabel
{
    Q_OBJECT
public:
    explicit goldtext(QWidget* parent = 0);
};

#endif // GOLDTEXT_H

#include "mylabel.h"

mylabel::mylabel(QWidget* parent,int fontsize):QLabel (parent)
{
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(174,179,139));
//    this->setText("扫描范围 - 50.0 x 50.0 μm²");
    this->setFont(QFont("SourceCode Pro",fontsize));
    this->setPalette(pa);
}

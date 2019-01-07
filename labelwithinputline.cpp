#include "labelwithinputline.h"

labelWithInputline::labelWithInputline(QWidget *parent) : QWidget(parent),label(new mylabel),
    inputline(new uxinputline),label2(new mylabel)
{
    QHBoxLayout* hlayout = new QHBoxLayout;
    label2->setText("mv");
    hlayout->addWidget(label);
    hlayout->addWidget(inputline);
    hlayout->addWidget(label2);
    setLayout(hlayout);
}

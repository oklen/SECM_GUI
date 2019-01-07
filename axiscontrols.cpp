#include "axiscontrols.h"
QString path =
        "E:/SECM-User-Interface/qt-material-widgets/components/icons/hardware/svg/production/";

AxisControls::AxisControls(QWidget *parent) : QWidget(parent),
    DigLabel(new mylabel(nullptr,45)),targetlabel(new mylabel),steplabel(new mylabel),
    hudlabel(new mylabel),hudshow(new mylabel(nullptr,20)),
    left(new QPushButton),
    right(new QPushButton),
    targetcon(new QPushButton),
    stepcon(new QPushButton),
    hudcon(new QPushButton),
    targetinput(new uxinputline),stepinput(new uxinputline),
    hudinput(new uxinputline),
    slider(new QSlider(Qt::Horizontal)),axis(new mylabel(nullptr,20)),unit(new mylabel),
    unit2(new mylabel),unit3(new mylabel),unit4(new mylabel(nullptr,35))
{
    axis->setAlignment(Qt::AlignLeft|Qt::AlignBottom);
    left->setIcon(QIcon(path+"ic_keyboard_arrow_left_24px.svg"));
    right->setIcon(QIcon(path+"ic_keyboard_arrow_right_24px.svg"));
    targetcon->setIcon(QIcon(path+"ic_keyboard_return_24px.svg"));
    stepcon->setIcon(QIcon(path+"ic_keyboard_return_24px.svg"));
    hudcon->setIcon(QIcon(path+"ic_keyboard_return_24px.svg"));
    DigLabel->setFixedSize(300,120);
    DigLabel->setText(QString::number(192.45));
    unit->setText("um");unit2->setText("um");unit3->setText("%");unit4->setText("um");

    setFixedWidth(320);
    slider->setMaximum(1000);
    targetlabel->setText(chi("目标位置:"));
    targetinput->setText("0");
    steplabel->setText(chi("步长大小:"));
    hudlabel->setText(chi("百分位置:"));
    hudshow->setAlignment(Qt::AlignRight|Qt::AlignBottom);
    QVBoxLayout* vlayout = new QVBoxLayout;
    QHBoxLayout* hlayout1= new QHBoxLayout;
    QHBoxLayout* hlayout2 = new QHBoxLayout;
    QHBoxLayout* hlayout3= new QHBoxLayout;
    QHBoxLayout* hlayout4 = new QHBoxLayout;
    QHBoxLayout* hlayout5 = new QHBoxLayout;
    QHBoxLayout* hlayout6 = new QHBoxLayout;

    hlayout1->addWidget(left);
    hlayout1->addWidget(slider);
    hlayout1->addWidget(right);
    hlayout2->addWidget(targetlabel);
    hlayout2->addWidget(targetinput);
    hlayout2->addWidget(unit);
    hlayout2->addWidget(targetcon);
    hlayout3->addWidget(steplabel);
    hlayout3->addWidget(stepinput);
    hlayout3->addWidget(unit2);
    hlayout3->addWidget(stepcon);
//    DigLabel->setAlignment(Qt::AlignRight);
//    axis->setAlignment(Qt::AlignCenter);
//    unit4->setAlignment(Qt::AlignRight);

//    hlayout4->addWidget(axis);
    hlayout4->addWidget(DigLabel);
    hlayout4->addWidget(unit4);
    hlayout5->addWidget(hudlabel);
    hlayout5->addWidget(hudinput);
    hlayout5->addWidget(unit3);
    hlayout5->addWidget(hudcon);
    hlayout6->addWidget(axis);
//    hlayout6->addWidget(hudshow);

    vlayout->addLayout(hlayout6);
    vlayout->addLayout(hlayout4);
    vlayout->addWidget(hudshow);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    vlayout->addLayout(hlayout3);
    vlayout->addLayout(hlayout5);
    setLayout(vlayout);
}

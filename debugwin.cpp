#include "debugwin.h"
#include "ui_debugwin.h"

DebugWin::DebugWin(QWidget *parent) :
    QWidget(parent),aands(new ADDandSub),
    ui(new Ui::DebugWin),mb(QColor(50,50,50))
{
    ui->setupUi(this);
    ui->widget_3->label->setText(chi("基准电压"));
    ui->widget_4->label->setText(chi("偏压设置"));
    ui->widget_5->label->setText(chi("增益步长"));
    ui->widget_5->layout()->removeWidget(ui->widget_5->label2);
    ui->widget_5->layout()->addWidget(aands);
    ui->widget_5->layout()->addWidget(ui->widget_5->label2);
    ui->widget_6->label->setText(chi("运放输出"));
    ui->label->setFont(QFont("Source Code Pro",20));
    ui->label_2->setFont(QFont("Source Code Pro",20));
    ui->label_3->setFont(QFont("Source Code Pro",20));
    sigmaGp = ui->widget_2;
    pi = ui->widget;
}

DebugWin::~DebugWin()
{
    delete ui;
}

void DebugWin::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.setBrush(mb);
    mpainter.drawRect(rect());
    mpainter.end();
}

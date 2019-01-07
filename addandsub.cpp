#include "addandsub.h"

ADDandSub::ADDandSub(QWidget *parent) : QWidget(parent),
    add(new QPushButton),sub(new QPushButton)
{
    QHBoxLayout* hlayout= new QHBoxLayout;
    add->setIcon(QIcon("E:/SECM-User-Interface/Qt-project/components/icons/content/svg/production/ic_add_24px.svg"));
    sub->setIcon(QIcon("E:/SECM-User-Interface/Qt-project/components/icons/content/svg/production/ic_remove_24px.svg"));
    hlayout->addWidget(add);
    hlayout->addWidget(sub);
    setLayout(hlayout);
}

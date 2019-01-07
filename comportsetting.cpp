#include "comportsetting.h"

comPortSetting::comPortSetting(sigmaControl* sigma,QWidget *parent) : QWidget(parent),
    sigma(sigma),ls{new mylabel[15]},PortNames(new QComboBox),PortNames2(new QComboBox),testButton(new QtMaterialRaisedButton),
    testButton2(new QtMaterialRaisedButton),testButton3(new QtMaterialRaisedButton)
{
    for(auto bb = sigma->nameToIndex.begin();bb!=sigma->nameToIndex.end();++bb){
        QString *now = new QString(QString::fromStdString(bb->first));
        PortNames->addItem(*now);
        PortNames2->addItem(*now);
    }
    QVBoxLayout* vlayout = new QVBoxLayout;
    ls[1].setText(chi("SECM设置"));
    ls[1].setFont(QFont("Source Code Pro",20));
    ls[0].setFont(QFont("Source Code Pro",20));
    ls[7].setFont(QFont("Source Code Pro",20));
    ls[2].setText(chi("    波特率:"));
    ls[3].setText(chi("    停止位:"));
    ls[4].setText(chi("    数据位:"));
    ls[5].setText(chi("    奇偶校验:"));
    ls[2].setText(ls[2].text()+QString::number(sigma->bandrate));
    ls[3].setText(ls[3].text()+QString::number(sigma->stopbits));
    ls[4].setText(ls[4].text()+QString::number(sigma->ByteSize));
    ls[5].setText(ls[5].text()+(sigma->Parity?chi("有"):chi("无")));
    ls[11].setText(chi("    端口"));
    ls[12].setText(chi("    端口"));
    ls[13].setText(chi("    端口"));
    ls[14].setText(chi("    端口"));

    for(int i=1;i<6;++i)
        vlayout->addWidget(&ls[i]);

    ls[0].setText(chi("微米台设置"));

    ls[6].setText(chi("待测"));
    ls[7].setText(chi("纳米台设置"));
    ls[8].setText(chi("待测"));
    ls[12].setText(chi("待测"));
    QHBoxLayout *hlayout1 = new QHBoxLayout;
    QHBoxLayout *hlayout2 = new QHBoxLayout;
    QHBoxLayout *hlayout3 = new QHBoxLayout;
    QHBoxLayout *hlayout4 = new QHBoxLayout;
    QHBoxLayout *hlayout5 = new QHBoxLayout;
    QHBoxLayout *hlayout6 = new QHBoxLayout;
    QHBoxLayout *hlayout7 = new QHBoxLayout;

    hlayout3->addWidget(&ls[11]);
    hlayout3->addWidget(PortNames2);
    hlayout4->addSpacing(40);
    hlayout4->addWidget(testButton3);
    hlayout4->addWidget(&ls[12]);

    hlayout1->addWidget(&ls[13]);
    hlayout1->addWidget(PortNames);
    hlayout6->addSpacing(40);
    hlayout6->addWidget(testButton);
    hlayout6->addWidget(&ls[6]);
    hlayout2->addWidget(&ls[14]);
    hlayout2->addWidget(&ls[10]);
    ls[10].setText("PI COM");
    hlayout7->addSpacing(40);
    hlayout7->addWidget(testButton2);
    hlayout7->addWidget(&ls[8]);

    hlayout5->addWidget(&ls[13]);
    vlayout->addLayout(hlayout3);
    vlayout->addLayout(hlayout4);
//    vlayout->addSpacing(30);
    vlayout ->addWidget(&ls[0]);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout6);
//    vlayout->addSpacing(30);
    vlayout->addWidget(&ls[7]);
    vlayout->addLayout(hlayout2);
    vlayout->addLayout(hlayout7);

    setLayout(vlayout);
    testButton->setText(chi("测试"));
    testButton->setFixedSize(80,40);
    testButton2->setText(chi("测试"));
    testButton2->setFixedSize(80,40);
    testButton3->setText(chi("测试"));
    testButton3->setFixedSize(80,40);
    ls[6].setStyleSheet("color:rgb(255,153,18)");
    ls[8].setStyleSheet("color:rgb(255,153,18)");
    ls[12].setStyleSheet("color:rgb(255,153,18)");
    connect(testButton,&QtMaterialFlatButton::pressed,[this](){
        if(test(this->sigma->nameToIndex[PortNames->currentText().toStdString()])&&this->sigma->testStatus()){
            ls[6].setText("COM for SECM is OK");
            ls[6].setStyleSheet("color:rgb(61,145,64)");
        }else {ls[6].setText("COM for SECM Test Failed");ls[6].setStyleSheet("color:rgb(255,97,18)");}
    });
    connect(testButton2,&QtMaterialFlatButton::pressed,[this](){
        if(pi->testStatus()){
            ls[8].setText("COM for SECM is OK");
            ls[8].setStyleSheet("color:rgb(61,145,64)");
        }else {ls[8].setText("COM for SECM Test Failed");ls[8].setStyleSheet("color:rgb(255,97,18)");}
    });
    setFixedSize(350,520);
}

bool comPortSetting::test(int index)
{
    if(sigma->comOpen(index,sigma->bandrate)){
        sigma->index = index;
        return true;
    }return false;
}

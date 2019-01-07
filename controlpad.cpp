#include "controlpad.h"
bool ControlPad::working = false;

ControlPad::ControlPad(QWidget* parent):QWidget(parent),
    sigma(new sigmaControl),history(new QTextBrowser),
    sigmaPos(new QLabel)
{
    PortNames.show();
    QVBoxLayout *vlayout1 = new QVBoxLayout;
    QHBoxLayout *hlayout1 = new QHBoxLayout;
    QLabel* PortLabel = new QLabel,*bandLabel = new QLabel;
    PortLabel->setText(chi("设置串口"));
    bandLabel->setText(chi("设置波特率"));
    bandRate.setText("38400");
    hlayout1->addWidget(PortLabel);
    hlayout1->addWidget(&PortNames);
    hlayout1->addWidget(bandLabel);
    hlayout1->addWidget(&bandRate);
    hlayout1->addWidget(&comPb);
    comPb.setText(chi("设置"));
    QHBoxLayout* hlayout2= new QHBoxLayout;
    QLabel *command = new QLabel;
    sigmaPos->setText("Pos: X:0 Y:0 Z:0");
    Send.setText(chi("发送"));
    command->setText(chi("命令"));
    hlayout2->addWidget(command);
    hlayout2->addWidget(&sendContent);
    hlayout2->addWidget(&Send);
    vlayout1->addWidget(history);
    vlayout1->addLayout(hlayout1);
    vlayout1->addLayout(hlayout2);
    vlayout1->addWidget(sigmaPos);

    setLayout(vlayout1);
    connect(&comPb,SIGNAL(clicked()),this,SLOT(SetConfig()));
    working = false;
    connect(&Send,&QPushButton::clicked,[this](){
        if(working)return;
        working = true;
        std::thread mt(&ControlPad::sendcommand,this);
        mt.detach();
    });
}

void ControlPad::closeEvent(QCloseEvent *event)
{
    hide();
}

void ControlPad::SetConfig()
{
    sigma->set(sigma->nameToIndex[PortNames.currentText().toStdString()],bandRate.text().toInt());
}

void ControlPad::sendcommand()
{
    sigma->clearReadBuf();
    sigma->write(sendContent.text().toStdString());
        there:
        sigma->read();
        if(sigma->buffer()[0]==0) goto there;
    history->append(sigma->buffer());
    int cnts=0;
    do{
        sigma->write("!:");
        sigma->read();
    }while(memcmp(sigma->buffer(),"0,0,0\r\t",5)!=0&&++cnts<1000);
    sigma->read();
    sigma->write("Q:");
    sigma->read();
    sigmaPos->clear();
    nowPos = sigmaLabel;
    for(int i=0;sigma->buffer()[i]!=0;++i)
        nowPos.push_back(sigma->buffer()[i]);
    nowPos.remove(nowPos.size()-1,1);
    nowPos.remove(nowPos.size()-1,1);
    int cnt=0;
    for(int i=0;i<nowPos.size()&&cnt<2;++i){
        if(nowPos[i]==','){
            nowPos.remove(i,1);nowPos.insert(i,df[cnt++]);
        }
    }
    sigmaPos->setText(nowPos);
    //history->append(sigma->buffer());
    working = false;
}

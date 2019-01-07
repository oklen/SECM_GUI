#include "sigmagroup.h"

sigmaGroup::sigmaGroup(QWidget *parent) : axGroupBase(parent),
    sigma(new sigmaControl),cPs(new comPortSetting(sigma))
{
    controls = sigma;
    ax[0]->slider->setMaximum(xmaxvalue);
    ax[1]->slider->setMaximum(ymaxvalue);
    ax[2]->slider->setMaximum(zmaxvalue);
    ax[0]->maxvalue = xmaxvalue;
    ax[1]->maxvalue = ymaxvalue;
    ax[2]->maxvalue = zmaxvalue;
    for(int i=0;i<3;++i)
    {
        ax[i]->stepinput->setText("10000");
        ax[i]->step = 10000;
    }
    sigma->tp.addMission(new sigCommand(returnOrigin));
    cPs->show();
}

void sigmaGroup::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier&&event->key()==Qt::Key_S)
        stop();
}

void sigmaGroup::processRmL(int index)
{
    sigma->tp.addMission(new sigCommand(
                     moveR,-movet[index][0]*ax[index]->step,
                 -movet[index][1]*ax[index]->step,
            -movet[index][2]*ax[index]->step));
}

void sigmaGroup::processRmR(int index)
{
    sigma->tp.addMission(new sigCommand(
                     moveR,movet[index][0]*ax[index]->step,
                 movet[index][1]*ax[index]->step,
            movet[index][2]*ax[index]->step));
}

void sigmaGroup::processAmS(int index)
{
    int value = ax[index]->slider->value();
    sigma->tp.addMission(new sigCommand(
                     moveA,index==0?value:ax[0]->nowvalue,
                     index==1?value:ax[1]->nowvalue,
                     index==2?value:ax[2]->nowvalue));
}

void sigmaGroup::processAmR(int index)
{
    long long value;
    if(index<0){
        index = abs(index);--index;
//        qDebug() << index <<" " <<ax[index]->hudinput->text()<<" "<<ax[index]->maxvalue;
        value=ax[index]->hudinput->text().toLongLong()*ax[index]->maxvalue/100;
    }else value = ax[index]->targetinput->text().toInt();
    value = min(value,ax[index]->maxvalue);
    sigma->tp.addMission(new sigCommand(
                     moveA,index==0?value:ax[0]->nowvalue,
                     index==1?value:ax[1]->nowvalue,
                     index==2?value:ax[2]->nowvalue));
}

void sigmaGroup::doUpdate()
{
    sigma->tp.addMission(new sigCommand(updatepos));
}

void sigmaGroup::updateUI()
{
    for(int i=0;i<3;++i){
        if(!sliderDown)
        {
            ax[i]->slider->setValue((int)sigma->sPos[i]);
            QString number {QString::number(100L*ax[i]->slider->value()/ax[i]->slider->maximum())};
            number.push_back('%');
            ax[i]->hudshow->setText(number);
        }
        ax[i]->DigLabel->setText((QString::asprintf("%8d",(int)sigma->sPos[i])));
        ax[i]->nowvalue = sigma->sPos[i];
    }
}

void sigmaGroup::stop()
{
    sigma->tp.addMission(new sigCommand(stopa));
}

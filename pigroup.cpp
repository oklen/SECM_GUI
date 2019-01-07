#include "pigroup.h"

PIGroup::PIGroup(QWidget *parent) : axGroupBase(parent),
    pi(new PIContorl)
{
    controls = pi;
    for(int i=0;i<3;++i){
        ax[i]->slider->setMaximum(1000000);
        ax[i]->maxvalue = 100;
        ax[i]->step = 0.1;
        ax[i]->targetinput->setText(QString("0.0"));
        ax[i]->stepinput->setText("0.1");
        ax[i]->nowvalue = 0;
    }
    //    pi->tp.addMission(new piCommand(returnOrigin));
}

PIGroup::~PIGroup()
{
    delete pi;
}

void PIGroup::processRmL(int index)
{
    pi->tp.addMission(new piCommand(
                     moveR,-movet[index][0]*ax[index]->step,
                 -movet[index][1]*ax[index]->step,
            -movet[index][2]*ax[index]->step));
}

void PIGroup::processRmR(int index)
{
    pi->tp.addMission(new piCommand(
                     moveR,movet[index][0]*ax[index]->step,
                 movet[index][1]*ax[index]->step,
            movet[index][2]*ax[index]->step));
}

void PIGroup::processAmS(int index)
{
    double value = ax[index]->maxvalue*ax[index]->slider->value()/ax[index]->slider->maximum();
    pi->tp.addMission(new piCommand(
                     moveA,index==0?value:ax[0]->nowvalue,
                     index==1?value:ax[1]->nowvalue,
                  index==2?value:ax[2]->nowvalue));
}

void PIGroup::processAmR(int index)
{
    double value;
    if(index<0){
        index = abs(index);--index;
        value=ax[index]->hudinput->text().toDouble()*ax[index]->maxvalue/100;
    }
    else value = ax[index]->targetinput->text().toDouble();
    value = min(value,ax[index]->maxvalue);
    pi->tp.addMission(new piCommand(
                     moveA,index==0?value:ax[0]->nowvalue,
                     index==1?value:ax[1]->nowvalue,
                  index==2?value:ax[2]->nowvalue));
}

void PIGroup::doUpdate()
{
    pi->tp.addMission(new piCommand(updatepos));
}

void PIGroup::updateUI()
{
    for(int i=0;i<3;++i){
//        qDebug()<<pi->sPos[i]<<" "<< ax[i]->slider->value();
        if(!sliderDown)
        {	
            ax[i]->slider->setValue(pi->sPos[i]/ax[i]->maxvalue*ax[i]->slider->maximum());
            QString number {QString::number((int)(100*pi->sPos[i]/ax[i]->maxvalue))};
            number.push_back('%');
            ax[i]->hudshow->setText(number);
        }
        pi->tp.mtx.lock();
        ax[i]->DigLabel->setText(QString::asprintf("%8.3f",pi->sPos[i]));
        pi->tp.mtx.unlock();
        ax[i]->nowvalue = pi->sPos[i];
    }
}

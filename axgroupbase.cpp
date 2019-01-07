#include "axgroupbase.h"

axGroupBase::axGroupBase(QWidget *parent,int interval) : QWidget(parent)
{
    sliderDown=false;
    for(int i=0;i<3;++i){
        ax[i] = new AxisControls;
        connect(ax[i]->slider,&QSlider::sliderReleased,[this,i](){
            processAmS(i);
            sliderDown=false;
        });
        connect(ax[i]->slider,&QSlider::sliderPressed,[this,i](){
            sliderDown=true;
        });
        connect(ax[i]->targetcon,&QtMaterialIconButton::pressed,[this,i](){
            processAmR(i);
        });
        connect(ax[i]->left,&QtMaterialIconButton::pressed,[this,i](){
            processRmL(i);
        });
        connect(ax[i]->right,&QtMaterialIconButton::pressed,[this,i](){
            processRmR(i);
        });
        connect(ax[i]->hudcon,&QtMaterialIconButton::pressed,[this,i](){
            processAmR(-(i+1));
        });
        hlayout->addWidget(ax[i]);
        connect(ax[i]->stepcon,&QtMaterialIconButton::pressed,[this,i](){
           ax[i]->step = ax[i]->stepinput->text().toDouble();
        });
        ax[i]->axis->setText(QString(Waxis[i]));
    }
    setLayout(hlayout);
    timer.setInterval(interval);
    connect(&timer,&QTimer::timeout,[this](){
//        for(int i=0;i<3;++i)if(ax[i]->slider->isSliderDown())return;
        doUpdate();
        if(!connected&&controls){
            connected = true;
            connect(controls,&Controls::posUpdate,[this](){
                this->updateUI();
            });
        }
    });

    timer.start();
}

axGroupBase::~axGroupBase()
{
    timer.stop();
}

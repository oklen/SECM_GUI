#include "uxccdw.h"

UXCCDW::UXCCDW(QWidget *parent) : QOpenGLWidget(parent)
{
    setFixedSize(1392/1.65,1040/1.65);
//    connect(this,SIGNAL(objectNameChanged(QString)),this,SLOT(repaint()));
//  connect(this,SIGNAL(shoudld()),this,SLOT(repaint()));
    connect(this,SIGNAL(shoudld()),this,SLOT(update()));

    mmap = QPixmap("E:/SECM-User-Interface/emptyb.jpg");
    mpen.setWidth(1);
    mpen.setColor(Qt::white);

    progress.setParent(this);
    progress.setInvertedAppearance(true);
    progress.setProgressType(Material::DeterminateProgress);
    progress.setMinimum(0);
    progress.setMaximum(100);
    progress.setValue(100);
    progress.setFixedSize(310,20);
    progress.move(10,480+130);
    progress.setBackgroundColor(QColor(0,0,0,20));
    progress.setProgressColor(QColor(240,240,240,250));

    cp.setText(QString::fromLocal8Bit("0% (0 of 256)"));
    cp.setFont(QFont("SourceCode Pro", 25));
    rt.setFont(QFont("SourceCode Pro", 25));
    rt.setText("00:00:00");

//    intensity.setFont(QFont("SourceCode Pro"));
//    intensity.setText("Intensity 1.0");

//    intensity.move(width()-110,120);
    cp.move(20,460+130);
    cp.resize(250,25);
    rt.move(progress.x()+progress.width()-93,460+130);

    rt.setParent(this);
    cp.setParent(this);
//    intensity.setParent(this);

    cp.setObjectName("currentprocesslabel");
    rt.setObjectName("remaintime");
//    intensity.setObjectName("intensity");

    cp.raise();
    rt.raise();
    setStyleSheet("QLabel{background:(0,0,0,0)}"
                  "QLabel#currentprocesslabel{color:white;font-size:18px;}"
                  "QLabel#remaintime{color:white;font-size:19px;}"
                  /*"QLabel#intensity{color:white;font-size:14px;}"*/);

    cp.setAttribute(Qt::WA_TranslucentBackground);
    rt.setAttribute(Qt::WA_TranslucentBackground);
//    intensity.setAttribute(Qt::WA_TranslucentBackground);


    ub.setParent(this);
    ub.move((1392/1.65-ub.width())/2,1040/1.65-ub.height());
    ud.setParent(this);
    ud.move((1392/1.65-ud.width())/2,0);
    ul.setParent(this);
    ul.move(0,(1040/1.65-ul.height())/2);
    ur.setParent(this);
    ur.move(1392/1.65-ur.width(),(1040/1.65-ul.height())/2);

//    lp.move(this->width()-lp.width()-10,10);
//    lp.setParent(this);
    update();
}

void UXCCDW::paintEvent(QPaintEvent *event)
{
//    if(!dataarray)
//    qDebug() << "the should close is " << shouldclose;
    QPainter mp(this);
    mp.end();
    if(!toggle)
        return;

    QPainter mpainter;
    mpainter.begin(this);
    const uchar *cache = (uchar*)dataarray;

    if(!zoom)
    {
//        qDebug() << "Do Painting!";

//        mutex.lock();
        mpainter.drawImage(rect(),QImage((uchar*)dataarray,1624,1236,QImage::Format_RGB888),QRect(0,0,1624,1236));
//        mutex.unlock();
    }
    else
        mpainter.drawPixmap(0,0,1392/1.65,1040/1.65,
                            QPixmap::fromImage
                            (QImage(cache,1624,1236,QImage::Format_RGB888))
                            ,initpoint.x()*1.65*1624.0/1392,
                            initpoint.y()*1.65*1236.0/1040,
                            (endpoint-initpoint).x()*1.65*1624.0/1392,(endpoint-initpoint).y()*1.65*1236.0/1040);

    if(mousedown)
    {
        mpainter.setPen(mpen);
        mpainter.drawRect(QRect(initpoint,curpoint));
    }
//        qDebug() << "Draw done!";
    mpainter.end();

   // J_Image_Free(cacheimg2);
}

void UXCCDW::doupdate()
{
    if(!shouldclose)
        emit shoudld();
}

void UXCCDW::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        zoom = false;
        return;
    }
    initpoint = event->pos();
    curpoint =event->pos();
    mousedown = true;
}

void UXCCDW::mouseMoveEvent(QMouseEvent *event)
{

    curpoint = event->pos();
    if(curpoint.x() > this->width())
        curpoint.setX(this->width());
    if(curpoint.y() > this->height())
        curpoint.setY(this->height());
    update();
}

void UXCCDW::mouseReleaseEvent(QMouseEvent *event)
{
    //  1392/1.65,1040/1.65
    endpoint = event->pos();
    if(endpoint.x() > this->width())
        endpoint.setX(this->width());
    if(endpoint.y() > this->height())
        endpoint.setY(this->height());
    if(endpoint.x() < initpoint.x())
    {
        auto mider = endpoint.x();
        endpoint.setX(initpoint.x());
        initpoint.setX(mider);
    }
    if(endpoint.y() < initpoint.y())
    {
        auto mider = endpoint.y();
        endpoint.setY(initpoint.y());
        initpoint.setY(mider);
    }

    mousedown =false;
    if(event->button() == Qt::RightButton || (initpoint-endpoint).manhattanLength()<10)
    {
        return;
    }
    zoom = true;
}
void UXCCDW::stoppaint()
{
    bstoppaint = true;
}

void UXCCDW::updatetime()
{
    int havetime = mtime.restart()*(256 - processValue*256/100);

    QString hour = QString::number(havetime/1000/60/60);
    hour.resize(2,QChar('0'));
    QString minute = QString::number(havetime/1000/60);
    minute.resize(2,QChar('0'));
    QString second = QString::number((havetime/1000)%60);
    second.resize(2,QChar('0'));

    rt.setText(hour+":"+minute+":"+second);
}

//void UXCCDW::set4window(float up, float left, float sum)
//{
//    lp.inputx = left;
//    lp.inputy = up;
//    lp.update();
//    intensity.setText(QString("Intensity ") + QString::number(sum) + QString(" V"));
//}

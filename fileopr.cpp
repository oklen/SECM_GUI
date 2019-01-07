#include "fileopr.h"


fileopr::fileopr(QWidget *parent) : QWidget(parent)
{
    QPalette pa;int submovex = 12;
    pa.setColor(QPalette::WindowText,QColor(174,179,139));
    scanconfig.setText(chi("扫描设置"));
    scanconfig.setFont(QFont("SourceCode Pro",15));
    scanconfig.setPalette(pa);
    scanconfig.move(10,10);
    scanconfig.setWindowOpacity(0);

    dataLocation.setText(chi("存储设置"));
    dataLocation.setFont(QFont("SourceCode Pro",15));
    dataLocation.setPalette(pa);
    dataLocation.move(10,145);
    dataLocation.setWindowOpacity(0);


    pixel.setText(chi("单位像素"));
    pixel.setFont(QFont("SourceCode Pro",12));
    pa.setColor(QPalette::WindowText,QColor(156,156,156));
    pixel.setPalette(pa);
    pixel.move(submovex,59);
    pixel.setWindowOpacity(0);

    selpixel.addSelect(128);
    selpixel.addSelect(256);
    selpixel.addSelect(512);
    selpixel.addSelect(1024);
    selpixel.addSelect(1024<<1);
    selpixel.addSelect(1024<<2);
    selpixel.resize(600,40);
    selpixel.move(submovex+80,45);

    scansize.setText(chi("扫描范围"));
    scansize.setFont(QFont("SourceCode Pro",12));
    scansize.setPalette(pa);
    scansize.move(submovex,100);
    scansize.setWindowOpacity(0);

    selss.suffix =" um";
    selss.addSelect(5);
    selss.addSelect(10);
    selss.addSelect(25);
    selss.addSelect(50);
    selss.addSelect(50<<1);
    selss.addSelect(250);
    selss.resize(600,40);
    selss.move(submovex+80,95-9);

    filename.setText(chi("文件名"));
    filename.setFont(QFont("SourceCode Pro",12));
    filename.setPalette(pa);
    filename.move(submovex,195);
    filename.setWindowOpacity(0);


    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);

   shadow_effect->setOffset(0, 0);

    shadow_effect->setColor(Qt::black);

    shadow_effect->setBlurRadius(4);


    int leftspace = 80;
    name.move(submovex+leftspace,195);

    name.setGraphicsEffect(shadow_effect);
    name.setShowInputLine(false);
    name.setInkColor(QColor(Qt::white));
    name.setFixedWidth(name.width()-120);
    //name.setTextColor(QColor(156,156,156));
    name.setStyleSheet("color:rgb(156,156,156);background:rgb(59,59,59)");

    directory.setText(chi("目录"));
    directory.setFont(QFont("SourceCode Pro",12));
    directory.setPalette(pa);
    directory.move(submovex,245);
    directory.setWindowOpacity(0);

    QGraphicsDropShadowEffect *shadow_effect2 = new QGraphicsDropShadowEffect;

    shadow_effect2->setOffset(0, 0);

    shadow_effect2->setColor(Qt::black);

    shadow_effect2->setBlurRadius(4);

    dir.move(submovex+leftspace,245);
    dir.setStyleSheet("background:rgb(99,99,99)");
    dir.setShowInputLine(false);
    dir.setInkColor(QColor(Qt::white));
    dir.setFixedWidth(name.width()-200);
    dir.setGraphicsEffect(shadow_effect2);
    dir.setStyleSheet("color:rgb(156,156,156);background:rgb(59,59,59)");
    //dir.setTextColor(QColor(156,156,156));

    select = new QtMaterialRaisedButton;
    select->setForegroundColor(QColor(168,168,168));
    select->setBackgroundColor(QColor(0,0,0,0));
    select->setBorderWidth(2);
    select->setText(chi("选择"));
    select->resize(90,30);
    select->setFixedHeight(28);
    select->setBorderWidth(1);
    select->setHaloVisible(false);
    select->move(dir.x()+dir.width()+10,245);

    explore = new QtMaterialRaisedButton;
    explore->setForegroundColor(QColor(168,168,168));
    explore->setBackgroundColor(QColor(0,0,0,0));
    explore->setBorderWidth(2);
    explore->setText(chi("浏览"));
    explore->resize(90,30);
    explore->setFixedHeight(28);
    explore->setBorderWidth(1);
    explore->setHaloVisible(false);
    explore->move(dir.x()+dir.width()+110,245);


    pixel.setParent(this);
    scanconfig.setParent(this);
    scansize.setParent(this);
    dataLocation.setParent(this);
    selpixel.setParent(this);
    selss.setParent(this);
    filename.setParent(this);
    directory.setParent(this);
    name.setParent(this);dir.setParent(this);select->setParent(this);
    explore->setParent(this);
    connect(explore,&QtMaterialRaisedButton::clicked,[&](){
       QFileDialog df(this);
       df.setFileMode(QFileDialog::AnyFile);
       df.exec();
       if(df.selectedFiles().length())
       {
           QDir wdir(df.selectedFiles().first());
           name.setText(wdir.dirName());
           dir.setText(wdir.absolutePath().chopped(dir.text().length()));
       }
    });
}

void fileopr::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    mpainter.setBrush(QColor(59,59,59));
//    QPen mpen(Qt::black);mpen.setWidth(25);
    QRect rec = rect();rec.setHeight(height()-1);
    rec.setWidth(width()-1);
    mpainter.setPen(QColor(91,94,99));
    mpainter.drawRect(rec);
    mpainter.end();
}

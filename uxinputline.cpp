#include "uxinputline.h"

uxinputline::uxinputline(QWidget* parent):QtMaterialTextField(parent)
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    shadow_effect->setColor(Qt::black);
    shadow_effect->setBlurRadius(4);
    setGraphicsEffect(shadow_effect);
    setShowInputLine(false);
    setInkColor(QColor(Qt::white));
    setStyleSheet("color:rgb(156,156,156);background:rgb(59,59,59)");
}

#include "temperaturegauge.h"

TemperatureGauge::TemperatureGauge(QWidget *parent)
    : QWidget(parent), m_angle(-15)
{
    resize(100, 100);
}

void TemperatureGauge::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(4);
    painter.setPen(pen);


    painter.drawEllipse(QRect(0, 0, 100, 100));
    pen.setColor(QColor(150, 150, 150));
    painter.setPen(pen);
    painter.drawEllipse(QRect(2, 2, 96, 96));
    painter.save();

    pen.setColor(QColor(235, 90, 45));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.translate(50, 50);

    painter.rotate(-30);
    for (int i = 0; i < 3; ++i) {
        painter.drawLine(QLine(QPoint(34, 0), QPoint(40, 0)));
        painter.rotate(-60);
    }
    painter.restore();
    painter.save();

    QPainterPath scales;
    QFont scaleFont = font();
    scaleFont.setPixelSize(10);
    scaleFont.setStyle(QFont::StyleOblique);
    scales.addText(QPoint(65, 45), scaleFont, tr("150"));
    scales.addText(QPoint(40, 30), scaleFont, tr("100"));
    scales.addText(QPoint(15, 45), scaleFont, tr("50"));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawPath(scales);

    painter.restore();
    painter.save();

    QPainterPath pivot;
    pivot.addEllipse(40, 40, 20, 20);
    painter.fillPath(pivot, QBrush(QColor(60, 60, 60)));
    painter.restore();

    painter.save();
    painter.translate(50, 50);
    /*
     * -15 deg equals 50 on scale
     * 105 deg equals 150 on scale
    */
    painter.rotate(m_angle);
    QPainterPath arrow;
    arrow.moveTo(10, 14);
    arrow.lineTo(-4, 0);
    arrow.lineTo(-24, -24);
    arrow.lineTo(0, -4);
    arrow.lineTo(14, 10);
    arrow.lineTo(10, 14);
    arrow.closeSubpath();

    QPainterPath arrowbottom;
    arrowbottom.moveTo(14, 10);
    arrowbottom.lineTo(18, 16);
    arrowbottom.lineTo(16, 18);
    arrowbottom.lineTo(10, 14);
    arrowbottom.lineTo(14, 10);
    arrowbottom.closeSubpath();

    painter.fillPath(arrow, QBrush(QColor(184, 7, 16)));
    painter.fillPath(arrowbottom, QBrush(QColor(50, 50, 50)));
    painter.restore();
}

void TemperatureGauge::moveGauge(int angle)
{
    m_angle = angle;
    update();
}

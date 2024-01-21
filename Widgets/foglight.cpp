#include "foglight.h"

FogLight::FogLight(QWidget *parent)
    : QWidget(parent), m_fogLight_status(false)
{
    resize(50, 50);
}

void FogLight::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPainterPath lamp;
    lamp.moveTo(5, 20);
    lamp.lineTo(7, 15);
    lamp.lineTo(10, 10);
    lamp.lineTo(15, 7);
    lamp.lineTo(20, 5);
    lamp.lineTo(23, 5);
    lamp.lineTo(24, 10);
    lamp.lineTo(25, 15);
    lamp.lineTo(25, 25);
    lamp.lineTo(24, 30);
    lamp.lineTo(23, 35);
    lamp.lineTo(20, 35);
    lamp.lineTo(15, 33);
    lamp.lineTo(10, 30);
    lamp.lineTo(7, 25);
    lamp.lineTo(5, 20);
    lamp.closeSubpath();

    QPen pen;
    pen.setWidth(2);
    if (m_fogLight_status)
        pen.setColor(QColor(200, 60, 20));
    else
        pen.setColor(QColor(50, 20, 10));

    painter.setPen(pen);
    painter.drawPath(lamp);
    if (m_fogLight_status)
        painter.fillPath(lamp, QBrush(QColor(200, 60, 20)));
    else
        painter.fillPath(lamp, QBrush(QColor(50, 20, 10)));
    painter.save();

    QList<QLine> lines;
    lines.push_back(QLine(QPoint(30, 10), QPoint(45, 25)));
    lines.push_back(QLine(QPoint(30, 20), QPoint(45, 35)));
    lines.push_back(QLine(QPoint(30, 30), QPoint(45, 45)));

    pen.setWidth(4);
    painter.drawLines(lines);
    painter.restore();

    QPainterPath zigzagbeam;
    zigzagbeam.moveTo(38, 13);
    zigzagbeam.lineTo(40, 19);
    zigzagbeam.lineTo(40, 21);
    zigzagbeam.lineTo(36, 25);
    zigzagbeam.lineTo(36, 27);
    zigzagbeam.lineTo(39, 35);
    zigzagbeam.lineTo(39, 37);
    zigzagbeam.lineTo(34, 40);
    zigzagbeam.closeSubpath();

    painter.save();
    painter.drawPath(zigzagbeam);
    painter.restore();

}

void FogLight::changeFogLight()
{
    m_fogLight_status = m_fogLight_status ? false : true;
    update();

}

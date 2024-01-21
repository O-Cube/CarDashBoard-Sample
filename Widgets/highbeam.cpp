#include "highbeam.h"

HighBeamHeadlights::HighBeamHeadlights(QWidget *parent)
    : QWidget(parent), m_beamLight_status(false)
{
    resize(50, 50);
}

void HighBeamHeadlights::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPainterPath lamp;
    lamp.moveTo(22, 25);
    lamp.lineTo(23, 20);
    lamp.lineTo(24, 15);
    lamp.lineTo(23, 20);
    lamp.lineTo(25, 13);
    lamp.lineTo(26, 11);
    lamp.lineTo(27, 10);
    lamp.lineTo(30, 9);
    lamp.lineTo(32, 9);
    lamp.lineTo(37, 10);
    lamp.lineTo(42, 14);
    lamp.lineTo(47, 20);
    lamp.lineTo(48, 25);
    lamp.lineTo(47, 30);
    lamp.lineTo(42, 36);
    lamp.lineTo(37, 40);
    lamp.lineTo(32, 41);
    lamp.lineTo(30, 41);
    lamp.lineTo(27, 40);
    lamp.lineTo(26, 39);
    lamp.lineTo(25, 37);
    lamp.lineTo(24, 34);
    lamp.lineTo(23, 30);
    lamp.lineTo(22, 25);
    lamp.closeSubpath();

    QPen pen;
    pen.setWidth(2);
    if (m_beamLight_status)
        pen.setColor(QColor(30, 240, 30));
    else
        pen.setColor(QColor(30, 30, 30));

    painter.setPen(pen);
    painter.drawPath(lamp);
    if (m_beamLight_status)
        painter.fillPath(lamp, QBrush(QColor(30, 240, 30)));
    else
        painter.fillPath(lamp, QBrush(QColor(30, 30, 30)));
    painter.save();

    QList<QLine> lines;
    lines.push_back(QLine(QPoint(2, 37), QPoint(21, 37)));
    lines.push_back(QLine(QPoint(2, 31), QPoint(19, 31)));
    lines.push_back(QLine(QPoint(2, 25), QPoint(18, 25)));
    lines.push_back(QLine(QPoint(2, 19), QPoint(19, 19)));
    lines.push_back(QLine(QPoint(2, 13), QPoint(21, 13)));

    pen.setWidth(4);
    painter.drawLines(lines);
    painter.restore();

}

void HighBeamHeadlights::changeHighBeamHeadlights()
{
    m_beamLight_status = m_beamLight_status ? false : true;
    update();
}

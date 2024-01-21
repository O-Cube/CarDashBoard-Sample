#include "dippedbeam.h"

DippedBeamHeadlights::DippedBeamHeadlights(QWidget *parent)
    : QWidget(parent), m_dippedBeam_status(false)
{
    resize(50, 50);
}

void DippedBeamHeadlights::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPainterPath lamp;
    lamp.moveTo(25, 8);
    lamp.lineTo(26, 6);
    lamp.lineTo(27, 5);
    lamp.lineTo(30, 4);
    lamp.lineTo(32, 4);
    lamp.lineTo(37, 5);
    lamp.lineTo(42, 9);
    lamp.lineTo(47, 15);
    lamp.lineTo(48, 20);
    lamp.lineTo(47, 25);
    lamp.lineTo(42, 31);
    lamp.lineTo(37, 35);
    lamp.lineTo(32, 36);
    lamp.lineTo(30, 36);
    lamp.lineTo(27, 35);
    lamp.lineTo(26, 34);
    lamp.lineTo(25, 32);
    lamp.lineTo(25, 8);
    lamp.closeSubpath();

    QPen pen;
    pen.setWidth(2);
    if (m_dippedBeam_status)
        pen.setColor(QColor(30, 240, 30));
    else
        pen.setColor(QColor(30, 90, 30));

    painter.setPen(pen);
    painter.drawPath(lamp);


    if (m_dippedBeam_status)
        painter.fillPath(lamp, QBrush(QColor(30, 240, 30)));
    else
        painter.fillPath(lamp, QBrush(QColor(30, 30, 30)));
    painter.save();

    pen.setWidth(4);
    QList<QLine> lines;
    lines.push_back(QLine(QPoint(3, 17), QPoint(22, 10)));
    lines.push_back(QLine(QPoint(3, 24), QPoint(22, 17)));
    lines.push_back(QLine(QPoint(3, 31), QPoint(22, 24)));
    lines.push_back(QLine(QPoint(3, 38), QPoint(22, 31)));
    painter.drawLines(lines);

    painter.restore();

}

void DippedBeamHeadlights::changeDippedBeam()
{
    m_dippedBeam_status = m_dippedBeam_status ? false : true;
    update();
}

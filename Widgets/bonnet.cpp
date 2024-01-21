#include "bonnet.h"

Bonnet::Bonnet(QWidget *parent) :
    QWidget(parent), m_bonnetStatus(false)
{
    resize(60, 40);
}

void Bonnet::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::black);

    QPainterPath chasis;
    chasis.moveTo(3, 30);
    chasis.lineTo(4, 24);
    chasis.lineTo(8, 20);
    chasis.lineTo(21, 19);
    chasis.lineTo(30, 12);
    chasis.lineTo(49, 12);
    chasis.lineTo(52, 19);
    chasis.lineTo(57, 19);
    chasis.lineTo(58, 21);
    chasis.lineTo(58, 30);
    chasis.lineTo(54, 30);
    chasis.arcTo(QRectF(46, 26, 8, 8), 0, -180);
    chasis.lineTo(20, 30);
    chasis.arcTo(QRectF(12, 26, 8, 8), 0, -180);
    chasis.lineTo(3, 30);
    chasis.closeSubpath();

    QPen pen;
    if (m_bonnetStatus)
        pen.setColor(QColor(200, 60, 20));
    else
        pen.setColor(QColor(50, 20, 10));
    pen.setWidthF(1.5);
    pen.setJoinStyle(Qt::RoundJoin);

    painter.setPen(pen);
    painter.drawPath(chasis);
    painter.save();

    QPainterPath bonnet;
    bonnet.moveTo(QPoint(21, 19));
    bonnet.lineTo(QPoint(10, 11));
    bonnet.lineTo(QPoint(7, 12));

    painter.drawPath(bonnet);
    painter.restore();
}

void Bonnet::changeBonnet()
{
    m_bonnetStatus = m_bonnetStatus ? false : true;
    update();
}

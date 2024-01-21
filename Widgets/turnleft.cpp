#include "turnleft.h"

TurnLeft::TurnLeft(QWidget *parent)
    : QWidget(parent), m_leftLight_status(false)
{
    resize(50, 50);
}

void TurnLeft::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::black);
    int side = qMin(width(), height());
    painter.scale(side / 50, side / 50);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    if (m_leftLight_status)
        pen.setColor(QColor(30, 240, 30));
    else
        pen.setColor(QColor(30, 90, 30));
    pen.setWidth(4);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    QPolygon polygon;
    polygon << QPoint(5, 25) << QPoint(25, 5) << QPoint(25, 18) << QPoint(45, 18) << QPoint(45, 32) \
            << QPoint(25, 32) << QPoint(25, 45) << QPoint(5, 25);
    painter.drawPolygon(polygon);
}

void TurnLeft::changeStatus()
{
    m_leftLight_status = m_leftLight_status ? false : true;
    update();
}

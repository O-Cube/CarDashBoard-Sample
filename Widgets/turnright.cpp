#include "turnright.h"

TurnRight::TurnRight(QWidget *parent)
    : QWidget(parent), m_rightLight_status(false)
{
    resize(50, 50);
}

void TurnRight::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::black);
    int side = qMin(width(), height());
    painter.scale(side / 50, side / 50);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    if (m_rightLight_status)
        pen.setColor(QColor(30, 240, 30));
    else
        pen.setColor(QColor(30, 90, 30));
    pen.setWidth(4);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    QPolygon polygon;
    polygon << QPoint(5, 18) << QPoint(25, 18) << QPoint(25, 5) << QPoint(45, 25) << QPoint(25, 45) \
            << QPoint(25, 32) << QPoint(5, 32) << QPoint(5, 18);
    painter.drawPolygon(polygon);
}

void TurnRight::changeStatus()
{
    m_rightLight_status = m_rightLight_status ? false : true;
    update();
}

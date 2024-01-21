#include "door.h"

Door::Door(QWidget *parent)
    : QWidget(parent), m_doorStatus(false)
{
    resize(40, 50);
}

void Door::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);
    QBrush brush(QColor(250, 20, 45));
    QPen pen(QColor(250, 20, 45));
    pen.setWidth(2);

    if (!m_doorStatus) {
        pen.setColor(QColor(60, 20, 20));
        brush.setColor(QColor(60, 20, 20));
    }
    painter.setPen(pen);

    QPainterPath chasis;
    chasis.moveTo(13, 13);
    chasis.lineTo(15, 11);
    chasis.lineTo(17, 10);
    chasis.lineTo(23, 10);
    chasis.lineTo(25, 11);
    chasis.lineTo(27, 13);
    chasis.lineTo(27, 20);
    chasis.lineTo(25, 27);
    chasis.lineTo(25, 33);
    chasis.lineTo(27, 39);
    chasis.lineTo(27, 43);
    chasis.lineTo(26, 45);
    chasis.lineTo(24, 46);
    chasis.lineTo(16, 46);
    chasis.lineTo(14, 45);
    chasis.lineTo(13, 43);
    chasis.lineTo(13, 39);
    chasis.lineTo(15, 33);
    chasis.lineTo(15, 27);
    chasis.lineTo(13, 20);
    chasis.lineTo(13, 20);
    chasis.closeSubpath();

    painter.drawPath(chasis);
    painter.save();

    QPainterPath frontScreen;
    frontScreen.moveTo(15, 20);
    frontScreen.lineTo(25, 20);
    frontScreen.lineTo(24, 25);
    frontScreen.lineTo(16, 25);
    frontScreen.lineTo(15, 20);
    frontScreen.closeSubpath();

    painter.fillPath(frontScreen, brush);
    painter.restore();

    QPainterPath backScreen;
    backScreen.moveTo(16, 33);
    backScreen.lineTo(24, 33);
    backScreen.lineTo(25, 39);
    backScreen.lineTo(15, 39);
    backScreen.lineTo(16, 33);
    backScreen.closeSubpath();

    painter.save();
    painter.fillPath(backScreen, brush);
    painter.restore();

    painter.save();
    painter.drawLine(QPoint(13, 21), QPoint(9, 28));
    painter.drawLine(QPoint(27, 21), QPoint(31, 28));
    painter.restore();
}

void Door::changeDoorStatus()
{
    m_doorStatus = m_doorStatus ? false : true;
    update();
}

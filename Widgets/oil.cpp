#include "oil.h"

Jar::Jar(QWidget *parent)
    : QWidget(parent), m_changeOil_status(false)
{
    resize(50, 50);
}

void Jar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPen pen(QColor(200, 60, 20));
    pen.setWidth(2);
    QBrush brush(QColor(200, 60, 20));

    if (!m_changeOil_status) {
        pen.setColor(QColor(50, 20, 10));
        brush.setColor(QColor(50, 20, 10));
    }
    painter.setPen(pen);

    QPainterPath jar;
    jar.moveTo(5, 12);
    jar.lineTo(11, 12);
    jar.lineTo(11, 10);
    jar.lineTo(9, 10);
    jar.lineTo(9, 9);
    jar.lineTo(15, 9);
    jar.lineTo(15, 10);
    jar.lineTo(13, 10);
    jar.lineTo(13, 12);
    jar.lineTo(19, 12);
    jar.lineTo(20, 13);
    jar.lineTo(20, 14);
    jar.lineTo(40, 7);
    jar.lineTo(41, 7);
    jar.lineTo(44, 9);
    jar.lineTo(45, 12);
    jar.lineTo(43, 13);
    jar.lineTo(42, 10);
    jar.lineTo(41, 10);
    jar.lineTo(25, 30);
    jar.lineTo(5, 30);
    jar.lineTo(5, 12);
    jar.closeSubpath();

    QPainterPath drop;
    drop.moveTo(46, 14);
    drop.lineTo(46, 16);
    drop.lineTo(46, 16);
    drop.lineTo(48, 18);
    drop.lineTo(48, 20);
    drop.lineTo(47, 21);
    drop.lineTo(46, 21);
    drop.lineTo(45, 20);
    drop.lineTo(44, 18);
    drop.lineTo(44, 17);
    drop.lineTo(45, 16);
    drop.lineTo(46, 14);
    drop.closeSubpath();

    painter.fillPath(jar, brush);
    painter.fillPath(drop, brush);
    painter.save();

    painter.drawLine(QLine(QPoint(0, 7), QPoint(0, 8)));
    painter.drawLine(QLine(QPoint(0, 7), QPoint(6, 10)));
    painter.drawLine(QLine(QPoint(6, 10), QPoint(6, 12)));
    painter.drawLine(QLine(QPoint(0, 13), QPoint(5, 15)));
    painter.restore();
}

void Jar::changeOil()
{
    m_changeOil_status = m_changeOil_status ? false : true;
    update();
}

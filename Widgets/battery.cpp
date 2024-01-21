#include "battery.h"

Battery::Battery(QWidget *parent)
    : QWidget(parent), m_batteryStatus(false)
{
    resize(50, 50);
}

void Battery::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);
    QBrush brush(QColor(200, 60, 20));
    QPen pen(QColor(200, 60, 20));
    pen.setWidth(2);

    if (!m_batteryStatus) {
        brush.setColor(QColor(50, 20, 10));
        pen.setColor(QColor(50, 20, 10));
    }

    QPainterPath spike;
    spike.moveTo(24, 22);
    spike.lineTo(30, 28);
    spike.lineTo(30, 29);
    spike.lineTo(29, 30);
    spike.lineTo(26, 30);
    spike.lineTo(27, 37);
    spike.lineTo(23, 30);
    spike.lineTo(23, 29);
    spike.lineTo(24, 28);
    spike.lineTo(27, 28);
    spike.lineTo(24, 22);
    spike.closeSubpath();

    painter.setPen(pen);
    painter.fillPath(spike, brush);
    painter.save();

    QPainterPath batteryTop;
    batteryTop.moveTo(5, 15);
    batteryTop.lineTo(45, 15);
    batteryTop.lineTo(45, 18);
    batteryTop.lineTo(5, 18);
    batteryTop.lineTo(5, 15);
    batteryTop.closeSubpath();
    painter.fillPath(batteryTop, brush);
    painter.restore();

    painter.save();
    QPainterPath batteryBottom;
    batteryBottom.moveTo(5, 37);
    batteryBottom.lineTo(3, 40);
    batteryBottom.lineTo(48, 40);
    batteryBottom.lineTo(45, 37);
    batteryBottom.lineTo(5, 37);
    batteryBottom.closeSubpath();

    painter.fillPath(batteryBottom, brush);
    painter.restore();

    QList<QLine> lines;
    lines.push_back(QLine(QPoint(5, 18), QPoint(5, 37)));
    lines.push_back(QLine(QPoint(45, 18), QPoint(45, 37)));
    lines.push_back(QLine(QPoint(10, 20), QPoint(10, 26)));
    lines.push_back(QLine(QPoint(7, 23), QPoint(13, 23)));
    lines.push_back(QLine(QPoint(37, 23), QPoint(43, 23)));
    lines.push_back(QLine(QPoint(10, 12), QPoint(10, 15)));
    lines.push_back(QLine(QPoint(40, 12), QPoint(40, 15)));
    lines.push_back(QLine(QPoint(15, 15), QPoint(15, 10)));
    lines.push_back(QLine(QPoint(15, 10), QPoint(35, 10)));
    lines.push_back(QLine(QPoint(35, 10), QPoint(35, 15)));

    painter.save();
    painter.drawLines(lines);
    painter.restore();

}

void Battery::changeBatteryStatus()
{
    m_batteryStatus = m_batteryStatus ? false : true;
    update();
}

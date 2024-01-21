#include "speedometer.h"

Speedometer::Speedometer(QWidget *parent)
    : QWidget(parent), m_speed(0.0)
{
    resize(300, 300);
}

void Speedometer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);
    QPen pen(QColor(200, 200, 200));
    pen.setWidth(4);

    painter.setPen(pen);
    painter.drawEllipse(0, 0, 300, 300);
    pen.setColor(QColor(120, 120, 120));
    painter.setPen(pen);
    painter.drawEllipse(2, 2, 296, 296);
    painter.save();

    painter.translate(150, 150);
    painter.rotate(45);
    QLine line(QPoint(130, 0), QPoint(140, 0));
    pen.setColor(QColor(235, 90, 45));
    pen.setWidth(5);
    painter.setPen(pen);
    for (int i = 0; i < 14; ++i) {
        painter.drawLine(line);
        painter.rotate(-20.78);
    }
    painter.restore();

    painter.save();
    pen.setColor(QColor(235, 90, 45));
    pen.setWidth(3);
    painter.setPen(pen);
    painter.translate(150, 150);
    painter.rotate(34.61);
    for (int i = 0; i < 13; ++i) {
        painter.drawLine(line);
        painter.rotate(-20.78);
    }
    painter.restore();

    painter.save();
    QFont text_font = font();
    text_font.setPixelSize(20);
    text_font.setWeight(QFont::Normal);
    painter.setFont(text_font);
    painter.setPen(pen);
    painter.drawText(65, 235, tr("0"));
    painter.drawText(42, 205, tr("20"));
    painter.drawText(28, 165, tr("40"));
    painter.drawText(32, 122, tr("60"));
    painter.drawText(55, 83, tr("80"));
    painter.drawText(80, 58, tr("100"));
    painter.drawText(110, 40, tr("120"));
    painter.drawText(150, 40, tr("140"));
    painter.drawText(180, 58, tr("160"));
    painter.drawText(210, 83, tr("180"));
    painter.drawText(230, 122, tr("200"));
    painter.drawText(235, 165, tr("220"));
    painter.drawText(225, 205, tr("240"));
    painter.drawText(200, 235, tr("260"));
    text_font.setPixelSize(15);
    painter.setFont(text_font);
    painter.drawText(125, 120, tr("Km/h"));

    QPainterPath pivot;
    pivot.addEllipse(130, 130, 40, 40);
    painter.fillPath(pivot, QBrush(QColor(120, 120, 120)));
    painter.restore();

    painter.save();
    QPainterPath pointer;

    painter.translate(150, 150);
    /* -90 = 0, 180 = 260 */
    painter.rotate(m_speed);

    pointer.moveTo(32, 28);
    pointer.lineTo(-36, -40);
    pointer.lineTo(-100, -100);
    pointer.lineTo(-40, -36);
    pointer.lineTo(28, 32);
    pointer.lineTo(32, 28);
    pointer.closeSubpath();

    QPainterPath pointerBottom;
    pointerBottom.moveTo(32, 28);
    pointerBottom.lineTo(40, 38);
    pointerBottom.lineTo(38, 40);
    pointerBottom.lineTo(28, 32);
    pointerBottom.lineTo(32, 28);
    pointerBottom.closeSubpath();

    painter.fillPath(pointer, QBrush(QColor(200, 50, 45)));
    painter.fillPath(pointerBottom, QBrush(QColor(60, 60, 60)));
    painter.restore();
}

void Speedometer::changeSpeed(float speed)
{
    m_speed = speed;
    update();
}

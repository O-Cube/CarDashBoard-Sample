#include "revolutiongauge.h"

RevolutionGauge::RevolutionGauge(QWidget *parent)
    : QWidget(parent), m_revolution(0.0)
{
    resize(300, 300);
}

void RevolutionGauge::paintEvent(QPaintEvent *event)
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

    QLine line(QPoint(130, 0), QPoint(140, 0));

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
    painter.drawText(55, 220, tr("0"));
    painter.drawText(30, 140, tr("1"));
    painter.drawText(70, 65, tr("2"));
    painter.drawText(143, 40, tr("3"));
    painter.drawText(220, 65, tr("4"));
    painter.drawText(262, 142, tr("5"));
    painter.drawText(240, 225, tr("6"));
    text_font.setPixelSize(15);
    painter.setFont(text_font);
    painter.drawText(125, 100, tr("1/min*1000"));

    QPainterPath pivot;
    pivot.addEllipse(130, 130, 40, 40);
    painter.fillPath(pivot, QBrush(QColor(120, 120, 120)));
    painter.restore();

    painter.save();
    QPainterPath pointer;

    painter.translate(150, 150);
    /* 0 = -80 deg, 6 = 170 deg */
    painter.rotate(m_revolution);

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

void RevolutionGauge::changeRev(float rev)
{
    m_revolution = rev;
    update();
}

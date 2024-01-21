#include "traction.h"

SlipperyRoad::SlipperyRoad(QWidget *parent)
    : QWidget(parent), m_slipperyRoad_status(false)
{
    resize(50, 50);
}

void SlipperyRoad::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPen pen(QColor(250, 20, 45));
    pen.setWidth(2);
    QBrush brush(QColor(250, 20, 45));

    if (!m_slipperyRoad_status) {
        pen.setColor(QColor(60, 20, 20));
        brush.setColor(QColor(60, 20, 20));
    }

    painter.setPen(pen);

    QPainterPath carBody;
    carBody.moveTo(13, 18);
    carBody.lineTo(10, 20);
    carBody.lineTo(10, 30);
    carBody.lineTo(12, 30);
    carBody.lineTo(13, 32);
    carBody.lineTo(18, 32);
    carBody.lineTo(19, 30);
    carBody.lineTo(31, 30);
    carBody.lineTo(32, 32);
    carBody.lineTo(37, 32);
    carBody.lineTo(38, 30);
    carBody.lineTo(40, 30);
    carBody.lineTo(40, 20);
    carBody.lineTo(37, 18);
    carBody.lineTo(13, 18);
    carBody.closeSubpath();

    QPainterPath leftMirror;
    leftMirror.moveTo(13, 18);
    leftMirror.lineTo(12, 15);
    leftMirror.lineTo(10, 15);
    leftMirror.lineTo(10, 18);
    leftMirror.lineTo(13, 18);
    leftMirror.closeSubpath();

    QPainterPath rightMirror;
    rightMirror.moveTo(37, 18);
    rightMirror.lineTo(38, 15);
    rightMirror.lineTo(40, 15);
    rightMirror.lineTo(40, 18);
    rightMirror.lineTo(37, 18);
    rightMirror.closeSubpath();

    QPainterPath leftTract;
    leftTract.moveTo(10, 48);
    leftTract.lineTo(13, 46);
    leftTract.lineTo(14, 44);
    leftTract.lineTo(14, 42);
    leftTract.lineTo(11, 39);
    leftTract.lineTo(10, 37);
    leftTract.lineTo(10, 36);
    leftTract.lineTo(11, 34);
    leftTract.lineTo(13, 32);
    leftTract.lineTo(18, 32);
    leftTract.lineTo(14, 36);
    leftTract.lineTo(14, 37);
    leftTract.lineTo(17, 40);
    leftTract.lineTo(18, 42);
    leftTract.lineTo(18, 43);
    leftTract.lineTo(17, 45);
    leftTract.lineTo(10, 48);
    leftTract.closeSubpath();

    QPainterPath rightTract;
    rightTract.moveTo(30, 48);
    rightTract.lineTo(33, 46);
    rightTract.lineTo(34, 44);
    rightTract.lineTo(34, 43);
    rightTract.lineTo(33, 41);
    rightTract.lineTo(31, 39);
    rightTract.lineTo(30, 37);
    rightTract.lineTo(30, 36);
    rightTract.lineTo(32, 32);
    rightTract.lineTo(37, 32);
    rightTract.lineTo(35, 35);
    rightTract.lineTo(35, 37);
    rightTract.lineTo(38, 41);
    rightTract.lineTo(38, 43);
    rightTract.lineTo(38, 45);
    rightTract.lineTo(30, 48);
    rightTract.closeSubpath();

    painter.fillPath(carBody, brush);
    painter.fillPath(leftMirror, brush);
    painter.fillPath(rightMirror, brush);
    painter.fillPath(leftTract, brush);
    painter.fillPath(rightTract, brush);

    painter.save();

    painter.drawLine(QLine(QPoint(15, 10), QPoint(13, 18)));
    painter.drawLine(QLine(QPoint(35, 10), QPoint(37, 18)));
    painter.drawLine(QLine(QPoint(15, 10), QPoint(35, 10)));

    painter.restore();

}

void SlipperyRoad::slipperyRoad()
{
    m_slipperyRoad_status = m_slipperyRoad_status ? false : true;
    update();
}

#include "engine.h"

Engine::Engine(QWidget *parent)
    : QWidget(parent), m_changeEngine_status(false)
{
    resize(50, 50);
}

void Engine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);

    QPen pen(QColor(200, 60, 20));
    pen.setWidth(1);
    if (!m_changeEngine_status)
        pen.setColor(QColor(50, 20, 10));

    painter.setPen(pen);

    QPainterPath engine;
    engine.moveTo(4, 15);
    engine.lineTo(5, 15);
    engine.lineTo(5, 24);
    engine.lineTo(7, 24);
    engine.lineTo(7, 15);
    engine.lineTo(10, 15);
    engine.lineTo(15, 10);
    engine.lineTo(23, 10);
    engine.lineTo(23, 8);
    engine.lineTo(17, 8);
    engine.lineTo(17, 6);
    engine.lineTo(32, 6);
    engine.lineTo(32, 8);
    engine.lineTo(26, 8);
    engine.lineTo(26, 10);
    engine.lineTo(35, 10);
    engine.lineTo(40, 15);
    engine.lineTo(43, 15);
    engine.lineTo(43, 23);
    engine.lineTo(45, 23);
    engine.lineTo(45, 15);
    engine.lineTo(49, 15);
    engine.lineTo(49, 40);
    engine.lineTo(45, 40);
    engine.lineTo(45, 32);
    engine.lineTo(43, 32);
    engine.lineTo(43, 42);
    engine.lineTo(20, 42);
    engine.lineTo(15, 35);
    engine.lineTo(7, 35);
    engine.lineTo(7, 26);
    engine.lineTo(5, 26);
    engine.lineTo(5, 35);
    engine.lineTo(4, 35);
    engine.lineTo(4, 15);
    engine.closeSubpath();

    painter.drawPath(engine);
}

void Engine::changeEngineStatus()
{
    m_changeEngine_status = m_changeEngine_status ? false : true;
    update();
}

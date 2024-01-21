#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

class Speedometer : public QWidget
{
    Q_OBJECT
public:
    explicit Speedometer(QWidget *parent = nullptr);
    void changeSpeed(float speed);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    float m_speed;
};

#endif // SPEEDOMETER_H

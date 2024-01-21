#ifndef TEMPERATUREGAUGE_H
#define TEMPERATUREGAUGE_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class TemperatureGauge : public QWidget
{
    Q_OBJECT
public:
    explicit TemperatureGauge(QWidget *parent = nullptr);
    void moveGauge(int angle);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int m_angle;
};

#endif // TEMPERATUREGAUGE_H

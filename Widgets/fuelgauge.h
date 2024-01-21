#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class FuelGauge : public QWidget
{
    Q_OBJECT
public:
    explicit FuelGauge(QWidget *parent = nullptr);
    void moveGauge(int angle);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int m_angle;
};

#endif // FUELGAUGE_H

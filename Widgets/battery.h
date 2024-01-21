#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Battery : public QWidget
{
    Q_OBJECT
public:
    explicit Battery(QWidget *parent = nullptr);
    void changeBatteryStatus();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_batteryStatus;
};

#endif // BATTERY_H

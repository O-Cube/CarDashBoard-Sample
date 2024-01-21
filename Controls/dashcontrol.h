#ifndef DASHCONTROL_H
#define DASHCONTROL_H

#include <QWidget>
#include <QGridLayout>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include "carsliders.h"

class DashControl : public QWidget
{
    Q_OBJECT
public:
    explicit DashControl(QWidget *parent = nullptr);
    ~DashControl();
signals:
    /* signals from sliders components */
    void temperatureChanged(int value);
    void speedChanged(int value);
    void fuelChanged(int value);
    void revolutionChanged(int value);
    /* signals from button components */
    void leftClicked();
    void rightClicked();
    void engineClicked();
    void oilClicked();
    void doorsClicked();
    void mainbeamClicked();
    void dippedbeamClicked();
    void batteryClicked();
    void foglampClicked();
    void tractionClicked();
    void bonnetClicked();
    void bootClicked();

private:
    QGridLayout *m_layout;
    /* sliders */
    CarSliders *m_temperature;
    CarSliders *m_speedometer;
    CarSliders *m_revolutions;
    CarSliders *m_fuel;
    /* push buttons */
    QPushButton *left;
    QPushButton *right;
    QPushButton *engine;
    QPushButton *oil;
    QPushButton *doors;
    QPushButton *mainbeam;
    QPushButton *dippedbeam;
    QPushButton *battery;
    QPushButton *foglamp;
    QPushButton *traction;
    QPushButton *bonnet;
    QPushButton *boot;
};

#endif // DASHCONTROL_H

#ifndef DASHBOARDINTERFACE_H
#define DASHBOARDINTERFACE_H

#include "../Widgets/battery.h"
#include "../Widgets/bonnet.h"
#include "../Widgets/battery.h"
#include "../Widgets/boot.h"
#include "../Widgets/battery.h"
#include "../Widgets/dippedbeam.h"
#include "../Widgets/door.h"
#include "../Widgets/engine.h"
#include "../Widgets/foglight.h"
#include "../Widgets/fuelgauge.h"
#include "../Widgets/highbeam.h"
#include "../Widgets/oil.h"
#include "../Widgets/revolutiongauge.h"
#include "../Widgets/traction.h"
#include "../Widgets/speedometer.h"
#include "../Widgets/temperaturegauge.h"
#include "../Widgets/turnleft.h"
#include "../Widgets/turnright.h"

#include <QWidget>
#include <QPainter>
#include <QGridLayout>

class DashBoardInterface : public QWidget
{
    Q_OBJECT
public:
    explicit DashBoardInterface(QWidget *parent = nullptr);
    ~DashBoardInterface();
protected:
    void paintEvent(QPaintEvent *event) override;
public slots:
    void temperatureChanged(int value);
    void fuelChanged(int value);
    void revChanged(int value);
    void speedChanged(int value);

    void leftChanged();
    void rightChanged();
    void engineChanged();
    void oilChanged();
    void doorChanged();
    void mainbeamChanged();
    void dippedbeamChanged();
    void batteryChanged();
    void foglampChanged();
    void tractionChanged();
    void bonnetChanged();
    void bootChanged();
private:
    /* determination of corresponding speedometer angle from slider deflection */
    float speedometerDeflection_angle(const int value);
    float revDeflection_angle(const int value);
    float tempDeflection_angle(const int value);
    float fuelDeflection_angle(const int value);

    QGridLayout *layout;
    /* slider widget components */
    FuelGauge *fuelDisplay;
    Speedometer *speedDisplay;
    TemperatureGauge *temperatureDisplay;
    RevolutionGauge *revolutionsDisplay;
    /* button components */
    TurnLeft *left;
    TurnRight *right;
    Engine *engine;
    Jar *oil;
    Door *door;
    HighBeamHeadlights *mainbeam;
    DippedBeamHeadlights *dippedbeam;
    FogLight *foglamp;
    Battery *battery;
    SlipperyRoad *traction;
    Bonnet *bonnet;
    Boot *boot;
};

#endif // DASHBOARDINTERFACE_H

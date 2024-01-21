#include "dashboardinterface.h"

DashBoardInterface::DashBoardInterface(QWidget *parent)
    : QWidget(parent)
{
    resize(1200, 500);
    layout = new QGridLayout(this);
    layout->setColumnMinimumWidth(7, 60);
    layout->setColumnMinimumWidth(8, 60);
    layout->setColumnMinimumWidth(9, 60);
    layout->setColumnMinimumWidth(10, 60);
    layout->setColumnMinimumWidth(11, 60);
    layout->setColumnMinimumWidth(12, 60);
    layout->setRowMinimumHeight(0, 60);

    /* speedometer widget */
    speedDisplay = new Speedometer(this);
    layout->addWidget(speedDisplay, 1, 4, 6, 6);

    /* fuel gauge widget */
    fuelDisplay = new FuelGauge(this);
    layout->addWidget(fuelDisplay, 5, 2, 2, 2);

    /* rev gauge widget */
    revolutionsDisplay = new RevolutionGauge(this);
    layout->addWidget(revolutionsDisplay, 1, 12, 6, 6);

    /* temperature gauge widget */
    temperatureDisplay = new TemperatureGauge(this);
    layout->addWidget(temperatureDisplay, 5, 17, 2, 2);

    left = new TurnLeft(this);
    layout->addWidget(left, 0, 7, 1, 1);

    right = new TurnRight(this);
    layout->addWidget(right, 0, 13, 1, 1);

    engine = new Engine(this);
    layout->addWidget(engine, 0, 8, 1, 1);

    oil = new Jar(this);
    layout->addWidget(oil, 1, 9, 1, 1);

    door = new Door(this);
    layout->addWidget(door, 2, 9, 1, 1);

    mainbeam = new HighBeamHeadlights(this);
    layout->addWidget(mainbeam, 2, 11, 1, 1);

    foglamp = new FogLight(this);
    layout->addWidget(foglamp, 1, 11, 1, 1);

    traction = new SlipperyRoad(this);
    layout->addWidget(traction, 2, 10, 1, 1);

    dippedbeam = new DippedBeamHeadlights(this);
    layout->addWidget(dippedbeam, 0, 9, 1, 1);

    battery = new Battery(this);
    layout->addWidget(battery, 1, 10, 1, 1);

    bonnet = new Bonnet(this);
    layout->addWidget(bonnet, 3, 9, 1, 1);

    boot = new Boot(this);
    layout->addWidget(boot, 3, 10, 1, 1);
}

DashBoardInterface::~DashBoardInterface()
{
    delete layout;

    delete fuelDisplay;
    delete speedDisplay;
    delete temperatureDisplay;
    delete revolutionsDisplay;

    delete left;
    delete right;
    delete engine;
    delete oil;
    delete door;
    delete mainbeam;
    delete dippedbeam;
    delete foglamp;
    delete battery;
    delete traction;
    delete bonnet;
    delete boot;
}

void DashBoardInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);
}

void DashBoardInterface::temperatureChanged(int value)
{
    temperatureDisplay->moveGauge(tempDeflection_angle(value));
}

void DashBoardInterface::fuelChanged(int value)
{
    fuelDisplay->moveGauge(fuelDeflection_angle(value));
}

void DashBoardInterface::revChanged(int value)
{
    revolutionsDisplay->changeRev(revDeflection_angle(value));
}

void DashBoardInterface::speedChanged(int value)
{
    speedDisplay->changeSpeed(speedometerDeflection_angle(value));
}

void DashBoardInterface::leftChanged()
{
    left->changeStatus();
}

void DashBoardInterface::rightChanged()
{
    right->changeStatus();
}

void DashBoardInterface::engineChanged()
{
    engine->changeEngineStatus();
}

void DashBoardInterface::oilChanged()
{
    oil->changeOil();
}

void DashBoardInterface::doorChanged()
{
    door->changeDoorStatus();
}

void DashBoardInterface::mainbeamChanged()
{
    mainbeam->changeHighBeamHeadlights();
}

void DashBoardInterface::dippedbeamChanged()
{
    dippedbeam->changeDippedBeam();
}

void DashBoardInterface::batteryChanged()
{
    battery->changeBatteryStatus();
}

void DashBoardInterface::foglampChanged()
{
    foglamp->changeFogLight();
}

void DashBoardInterface::tractionChanged()
{
    traction->slipperyRoad();
}

void DashBoardInterface::bonnetChanged()
{
    bonnet->changeBonnet();
}

void DashBoardInterface::bootChanged()
{
    boot->changeBoot();
}

/* determines corresponding deflection angle of the speedometer from slider movement */
float DashBoardInterface::speedometerDeflection_angle(const int value)
{
    return (value * (270 / 20)) - 90;
}

/* determines the deflection angle on the revolution display */
float DashBoardInterface::revDeflection_angle(const int value)
{
    return (value * (250 / 20)) - 80;
}

float DashBoardInterface::tempDeflection_angle(const int value)
{
    return (value * (120 / 20) - 15);
}

float DashBoardInterface::fuelDeflection_angle(const int value)
{
    return (value * (120 / 20) - 15);
}

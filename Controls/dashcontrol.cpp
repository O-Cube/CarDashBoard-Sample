#include "dashcontrol.h"

DashControl::DashControl(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 100);

    /* layout vertical boundaries */
    m_layout = new QGridLayout(this);
    m_layout->setColumnMinimumWidth(0, 20);
    m_layout->setColumnMinimumWidth(1, 5);
    m_layout->setColumnMinimumWidth(2, 20);
    m_layout->setColumnMinimumWidth(3, 5);
    m_layout->setColumnMinimumWidth(4, 20);
    m_layout->setColumnMinimumWidth(5, 5);
    m_layout->setColumnMinimumWidth(6, 20);
    m_layout->setColumnMinimumWidth(7, 5);
    m_layout->setColumnMinimumWidth(8, 20);
    m_layout->setColumnMinimumWidth(9, 5);
    m_layout->setColumnMinimumWidth(10, 20);
    m_layout->setColumnMinimumWidth(11, 5);
    m_layout->setColumnMinimumWidth(12, 20);

    /* temperature slider */
    m_temperature = new CarSliders(Qt::Vertical, this);
    connect(m_temperature, &CarSliders::valueChanged, this, [=] () {
        emit temperatureChanged(m_temperature->value());
    });
    m_layout->addWidget(m_temperature, 0, 0, 6, 1);
    m_layout->addWidget(new QLabel(tr("Temp"), this), 6, 0);

    /* speedometer slider */
    m_speedometer = new CarSliders(Qt::Vertical, this);
    connect(m_speedometer, &CarSliders::valueChanged, this, [=] () {
        emit speedChanged(m_speedometer->value());
    });
    m_layout->addWidget(m_speedometer, 0, 2, 6, 1);
    m_layout->addWidget(new QLabel(tr("Speed"), this), 6, 2);

    /* revolution slider */
    m_revolutions = new CarSliders(Qt::Vertical, this);
    connect(m_revolutions, &CarSliders::valueChanged, this, [=] () {
        emit revolutionChanged(m_revolutions->value());
    });
    m_layout->addWidget(m_revolutions, 0, 10, 6, 1);
    m_layout->addWidget(new QLabel(tr("Revs"), this), 6, 10);

    /* fuel slider */
    m_fuel = new CarSliders(Qt::Vertical, this);
    connect(m_fuel, &CarSliders::valueChanged, this, [=] () {
        emit fuelChanged(m_fuel->value());
    });
    m_layout->addWidget(m_fuel, 0, 12, 6, 1);
    m_layout->addWidget(new QLabel(tr("Fuel"), this), 6, 12);

    /* left direction light */
    left = new QPushButton(tr("Left"), this);
    m_layout->addWidget(left, 0, 4);
    connect(left, &QPushButton::clicked, this, &DashControl::leftClicked);

    /* engine */
    engine = new QPushButton(tr("Engine"), this);
    m_layout->addWidget(engine, 0, 6);
    connect(engine, &QPushButton::clicked, this, &DashControl::engineClicked);

    /* oil */
    oil = new QPushButton(tr("Oil"), this);
    m_layout->addWidget(oil, 0, 8);
    connect(oil, &QPushButton::clicked, this, &DashControl::oilClicked);

    /* right */
    right = new QPushButton(tr("Right"), this);
    m_layout->addWidget(right, 1, 4);
    connect(right, &QPushButton::clicked, this, &DashControl::rightClicked);

    /* doors */
    doors = new QPushButton(tr("Doors"), this);
    m_layout->addWidget(doors, 1, 6);
    connect(doors, &QPushButton::clicked, this, &DashControl::doorsClicked);

    /* main beam */
    mainbeam = new QPushButton(tr("MBeam"), this);
    m_layout->addWidget(mainbeam, 1, 8);
    connect(mainbeam, &QPushButton::clicked, this, &DashControl::mainbeamClicked);

    /* dipped beam */
    dippedbeam = new QPushButton(tr("DBeam"), this);
    m_layout->addWidget(dippedbeam, 2, 4);
    connect(dippedbeam, &QPushButton::clicked, this, &DashControl::dippedbeamClicked);

    /* battery */
    battery = new QPushButton(tr("Battery"), this);
    m_layout->addWidget(battery, 2, 6);
    connect(battery, &QPushButton::clicked, this, &DashControl::batteryClicked);

    /* fog lamp */
    foglamp = new QPushButton(tr("FogLamp"), this);
    m_layout->addWidget(foglamp, 2, 8);
    connect(foglamp, &QPushButton::clicked, this, &DashControl::foglampClicked);

    /* traction */
    traction = new QPushButton(tr("Traction"), this);
    m_layout->addWidget(traction, 3, 4);
    connect(traction, &QPushButton::clicked, this, &DashControl::tractionClicked);

    /* bonnet */
    bonnet = new QPushButton(tr("Bonnet"), this);
    m_layout->addWidget(bonnet, 3, 6);
    connect(bonnet, &QPushButton::clicked, this, &DashControl::bonnetClicked);

    /* boot */
    boot = new QPushButton(tr("Boot"), this);
    m_layout->addWidget(boot, 3, 8);
    connect(boot, &QPushButton::clicked, this, &DashControl::bootClicked);
}

DashControl::~DashControl()
{
    delete m_layout;
    delete m_temperature;
    delete m_speedometer;
    delete m_revolutions;
    delete m_fuel;

    delete left;
    delete right;
    delete engine;
    delete oil;
    delete doors;
    delete mainbeam;
    delete dippedbeam;
    delete battery;
    delete foglamp;
    delete traction;
    delete bonnet;
    delete boot;
}

/* sample car dashboard - obed o. */
#include "Widgets/turnleft.h"
#include "Widgets/turnright.h"
#include "Widgets/bonnet.h"
#include "Widgets/boot.h"
#include "Widgets/dippedbeam.h"
#include "Widgets/highbeam.h"
#include "Widgets/foglight.h"
#include "Widgets/battery.h"
#include "Widgets/door.h"
#include "Widgets/engine.h"
#include "Widgets/oil.h"
#include "Widgets/traction.h"
#include "Widgets/temperaturegauge.h"
#include "Widgets/fuelgauge.h"
#include "Widgets/speedometer.h"
#include "Widgets/revolutiongauge.h"
#include "Controls/dashcontrol.h"
#include "DashboardInterface/dashboardinterface.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DashControl control;
    DashBoardInterface interface;
    /* connections involving buttons */
    QObject::connect(&control, &DashControl::leftClicked, &interface, &DashBoardInterface::leftChanged);
    QObject::connect(&control, &DashControl::rightClicked, &interface, &DashBoardInterface::rightChanged);
    QObject::connect(&control, &DashControl::engineClicked, &interface, &DashBoardInterface::engineChanged);
    QObject::connect(&control, &DashControl::oilClicked, &interface, &DashBoardInterface::oilChanged);
    QObject::connect(&control, &DashControl::doorsClicked, &interface, &DashBoardInterface::doorChanged);
    QObject::connect(&control, &DashControl::mainbeamClicked, &interface, &DashBoardInterface::mainbeamChanged);
    QObject::connect(&control, &DashControl::batteryClicked, &interface, &DashBoardInterface::batteryChanged);
    QObject::connect(&control, &DashControl::dippedbeamClicked, &interface, &DashBoardInterface::dippedbeamChanged);
    QObject::connect(&control, &DashControl::foglampClicked, &interface, &DashBoardInterface::foglampChanged);
    QObject::connect(&control, &DashControl::tractionClicked, &interface, &DashBoardInterface::tractionChanged);
    QObject::connect(&control, &DashControl::bonnetClicked, &interface, &DashBoardInterface::bonnetChanged);
    QObject::connect(&control, &DashControl::bootClicked, &interface, &DashBoardInterface::bootChanged);
    /* connections involving sliders */
    QObject::connect(&control, &DashControl::speedChanged, &interface, &DashBoardInterface::speedChanged);
    QObject::connect(&control, &DashControl::revolutionChanged, &interface, &DashBoardInterface::revChanged);
    QObject::connect(&control, &DashControl::temperatureChanged, &interface, &DashBoardInterface::temperatureChanged);
    QObject::connect(&control, &DashControl::fuelChanged, &interface, &DashBoardInterface::fuelChanged);

    control.show();
    interface.show();
    return a.exec();
}

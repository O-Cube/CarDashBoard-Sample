#include "carsliders.h"

CarSliders::CarSliders(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent)
{
    setMaximum(20);
    setMinimum(0);
    setSingleStep(1);
}

#ifndef CARSLIDERS_H
#define CARSLIDERS_H

#include <QWidget>
#include <QSlider>

class CarSliders : public QSlider
{
public:
    CarSliders(Qt::Orientation orientation, QWidget *parent = nullptr);
};

#endif // CARSLIDERS_H

#ifndef FOGLIGHT_H
#define FOGLIGHT_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class FogLight : public QWidget
{
    Q_OBJECT
public:
    explicit FogLight(QWidget *parent = nullptr);
    void changeFogLight();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_fogLight_status;
};

#endif // FOGLIGHT_H

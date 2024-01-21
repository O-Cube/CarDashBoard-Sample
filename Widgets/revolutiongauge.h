#ifndef REVOLUTIONGAUGE_H
#define REVOLUTIONGAUGE_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

class RevolutionGauge : public QWidget
{
    Q_OBJECT
public:
    explicit RevolutionGauge(QWidget *parent = nullptr);
    void changeRev(float rev);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    float m_revolution;
};

#endif // REVOLUTIONGAUGE_H

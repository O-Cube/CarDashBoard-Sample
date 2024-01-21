#ifndef TRACTION_H
#define TRACTION_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class SlipperyRoad : public QWidget
{
    Q_OBJECT
public:
    explicit SlipperyRoad(QWidget *parent = nullptr);
    void slipperyRoad();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_slipperyRoad_status;
};

#endif // TRACTION_H

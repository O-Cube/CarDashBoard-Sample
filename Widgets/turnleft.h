#ifndef TURNLEFT_H
#define TURNLEFT_H

#include <QWidget>
#include <QPainter>

class TurnLeft : public QWidget
{
    Q_OBJECT
public:
    explicit TurnLeft(QWidget *parent = nullptr);
    void changeStatus();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_leftLight_status;
};

#endif // TURNLEFT_H

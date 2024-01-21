#ifndef TURNRIGHT_H
#define TURNRIGHT_H

#include <QWidget>
#include <QPainter>

class TurnRight : public QWidget
{
    Q_OBJECT
public:
    explicit TurnRight(QWidget *parent = nullptr);
    void changeStatus();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_rightLight_status;

signals:
};

#endif // TURNRIGHT_H

#ifndef DOOR_H
#define DOOR_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Door : public QWidget
{
    Q_OBJECT
public:
    explicit Door(QWidget *parent = nullptr);
    void changeDoorStatus();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_doorStatus;
};

#endif // DOOR_H

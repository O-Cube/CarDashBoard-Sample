#ifndef BONNET_H
#define BONNET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Bonnet : public QWidget
{
    Q_OBJECT
public:
    Bonnet(QWidget *parent = nullptr);
    void changeBonnet();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_bonnetStatus;
};

#endif // BONNET_H

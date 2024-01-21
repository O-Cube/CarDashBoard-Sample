#ifndef BOOT_H
#define BOOT_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Boot : public QWidget
{
    Q_OBJECT
public:
    explicit Boot(QWidget *parent = nullptr);
    void changeBoot();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_bootStatus;
};

#endif // BOOT_H

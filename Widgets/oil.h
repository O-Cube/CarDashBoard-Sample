#ifndef OIL_H
#define OIL_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Jar : public QWidget
{
    Q_OBJECT
public:
    explicit Jar(QWidget *parent = nullptr);
    void changeOil();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_changeOil_status;
};

#endif // OIL_H

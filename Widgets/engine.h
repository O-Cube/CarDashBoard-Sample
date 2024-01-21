#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Engine : public QWidget
{
    Q_OBJECT
public:
    explicit Engine(QWidget *parent = nullptr);
    void changeEngineStatus();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_changeEngine_status;
};

#endif // ENGINE_H

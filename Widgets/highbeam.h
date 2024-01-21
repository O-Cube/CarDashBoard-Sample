#ifndef HIGHBEAM_H
#define HIGHBEAM_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class HighBeamHeadlights : public QWidget
{
    Q_OBJECT
public:
    explicit HighBeamHeadlights(QWidget *parent = nullptr);
    void changeHighBeamHeadlights();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_beamLight_status;
};

#endif // HIGHBEAM_H

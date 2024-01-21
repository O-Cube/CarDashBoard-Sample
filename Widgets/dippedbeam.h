#ifndef DIPPEDBEAM_H
#define DIPPEDBEAM_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class DippedBeamHeadlights : public QWidget
{
    Q_OBJECT
public:
    explicit DippedBeamHeadlights(QWidget *parent = nullptr);
    void changeDippedBeam();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool m_dippedBeam_status;
};

#endif // DIPPEDBEAM_H

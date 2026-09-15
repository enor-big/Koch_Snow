#ifndef KOCHWIDGET_H
#define KOCHWIDGET_H

#include <QWidget>

class KochWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KochWidget(QWidget *parent = nullptr);
    void setDepth(int newDepth);
protected:
    void paintEvent(QPaintEvent *event) override;
    void drawKochSegment(QPainter &painter, QPointF A, QPointF B, int depth);
    void wheelEvent(QWheelEvent *event) override;
private:
    int depth=0;
    double scale = 1.0;
signals:
};

#endif // KOCHWIDGET_H

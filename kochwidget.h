#ifndef KOCHWIDGET_H
#define KOCHWIDGET_H

#include <QWidget>

class KochWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KochWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void drawKochSegment(QPainter &painter, QPointF A, QPointF B);
signals:
};

#endif // KOCHWIDGET_H

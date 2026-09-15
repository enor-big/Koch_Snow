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
private:
    int depth=0;
signals:
};

#endif // KOCHWIDGET_H

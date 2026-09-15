#include "kochwidget.h"
#include "QPainter"
#include <cmath>
#include <QWheelEvent>

KochWidget::KochWidget(QWidget *parent)
    : QWidget{parent}
{}

void KochWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.scale(scale, scale);
    QPointF A(200, 350);
    QPointF B(600, 350);
    QPointF C(400, 350 - 200 * sqrt(3));
    drawKochSegment(painter, A, B, depth);
    drawKochSegment(painter, B, C, depth);
    drawKochSegment(painter, C, A, depth);
}

void KochWidget::drawKochSegment(QPainter &painter, QPointF A, QPointF B, int depth){
    if (depth==0){
        painter.drawLine(A, B);
        return;
    }
    else{
        QPointF D(
            A.x() + (B.x() - A.x()) / 3,
            A.y() + (B.y() - A.y()) / 3
            );
        QPointF E(
            A.x() + 2 * (B.x() - A.x()) / 3,
            A.y() + 2 * (B.y() - A.y()) / 3
            );

        double dx=E.x() - D.x();
        double dy=E.y() - D.y();
        double rotatedX=dx/2-dy*sqrt(3)/2;
        double rotatedY=dx*sqrt(3)/2+dy/2;

        QPointF F(
            D.x()+rotatedX,
            D.y()+rotatedY
            );
        drawKochSegment(painter, A, D, depth - 1);
        drawKochSegment(painter, D, F, depth - 1);
        drawKochSegment(painter, F, E, depth - 1);
        drawKochSegment(painter, E, B, depth - 1);
    }

}
void KochWidget::setDepth(int newDepth){
    depth=newDepth;
    update();
}

void KochWidget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
        scale *= 1.1;
    else
        scale /= 1.1;

    update();
}

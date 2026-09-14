#include "kochwidget.h"
#include "QPainter"
#include <cmath>

KochWidget::KochWidget(QWidget *parent)
    : QWidget{parent}
{}

void KochWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPointF A(200, 400);
    QPointF B(600, 400);
    QPointF C(400, 400 - 200 * sqrt(3));
    drawKochSegment(painter, A, B);
    drawKochSegment(painter, B, C);
    drawKochSegment(painter, C, A);
}

void KochWidget::drawKochSegment(QPainter &painter, QPointF A, QPointF B){
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
    painter.drawLine(A, D);
    painter.drawLine(D, F);
    painter.drawLine(F, E);
    painter.drawLine(E, B);
}

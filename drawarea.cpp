#include "drawarea.h"
#include <QPainter>
#include <QPainterPath>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent)
{

}

void DrawArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
    painter.setPen(Qt::red);
    for (size_t i = 0; i < points.size(); ++i) {
        painter.drawLine(
                    QPointF(points[i].x() - 8, points[i].y()),
                    QPointF(points[i].x() + 8, points[i].y())
        );
        painter.drawLine(
                    QPointF(points[i].x(), points[i].y() - 8),
                    QPointF(points[i].x(), points[i].y() + 8)
        );
    }
    QPainterPath path;
    painter.setPen(Qt::white);
    if (points.size() >= 3) {
        path.moveTo(points[0]);
        path.lineTo(points[1]);
        path.lineTo(points[2]);
        path.closeSubpath();
        painter.drawPath(path);
    }
}

void DrawArea::mousePressEvent(QMouseEvent *e)
{
    points.push_back(e->localPos());
    update();
}

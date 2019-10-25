#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPointF>
#include <vector>

class DrawArea : public QWidget
{
    Q_OBJECT
    std::vector<QPointF> points;
public:
    explicit DrawArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

signals:

public slots:
};

#endif // DRAWAREA_H

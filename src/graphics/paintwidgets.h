#ifndef PAINTWIDGETS_H
#define PAINTWIDGETS_H

#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QtMath>
#include <QtWidgets>

struct coords{
    QPoint qp;
    int    k;
};

class QPaintWidget : public QFrame{
public:
    explicit    QPaintWidget();
    void        paintEvent(QPaintEvent *event);
    QPoint      pos;
    void        mouseMoveEvent(QMouseEvent *event);
    QVector<coords> vector;
    void        mousePressEvent(QMouseEvent *);
    void        mouseReleaseEvent(QMouseEvent *);
    int         f;
};

#endif // PAINTWIDGETS_H

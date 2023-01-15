#include <QPainter>
#include "paintwidgets.h"

QPaintWidget::QPaintWidget(){
    this->resize(1000, 600);
    this->move(100, 100);
    this->setWindowTitle("Рисовашка");

    QPalette pal; //этот объект для того чтобы задать фон/определить цвета
    pal.setColor(QPalette::Window, QColor(100, 200, 150));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setMouseTracking(true);
    f = 0;
}

void    QPaintWidget::paintEvent(QPaintEvent *event){
    QPainter    p(this);

    p.setPen(QPen(Qt::green, Qt::SolidLine));
    for (int i = 1; i < vector.size(); ++i){
        if (vector[i - 1].k == 1){
            continue;
        }
        p.drawLine(vector[i - 1].qp.x(), vector[i - 1].qp.y(), vector[i].qp.x(), vector[i].qp.y());
    }
}

void    QPaintWidget::mouseMoveEvent(QMouseEvent *event){
    if (!f)
        return ;
    this->pos = event->pos();
    coords qp1;
    qp1.qp = this->pos;
    qp1.k = 0;
    vector.append(qp1);
    this->update();
}

void    QPaintWidget::mousePressEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton)
        f = 1;
}

void    QPaintWidget::mouseReleaseEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton)
    {
        f = 0;
        if (vector.size() > 0)
            vector[vector.size() - 1].k = 1;
    }
    if (e->button() == Qt::RightButton)
    {
        if (vector.size() > 0)
            vector.remove(vector.size() - 1);
        if (vector.size() > 0)
            vector[vector.size() - 1].k = 1;
        this->update();
    }
}

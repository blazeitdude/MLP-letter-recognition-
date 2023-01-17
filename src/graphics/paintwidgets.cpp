#include <QPainter>
#include "paintwidgets.h"


QPaintWidget::QPaintWidget(QWidget *parent) : QWidget{parent}, _stop(false), _draw(true){
    _pen = QPen(Qt::black, _penWidth, Qt::SolidLine, Qt::RoundCap);
}

void    QPaintWidget::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0, 0, _pixmap);
    this->update();
}

void    QPaintWidget::resizeEvent(QResizeEvent *event){
    auto newRectangle = _pixmap.rect().united(rect());
    if (!(newRectangle == _pixmap.rect())){
        QPixmap newPixmap{newRectangle.size()};
        QPainter newPainter{&newPixmap};
        newPainter.fillRect(newPixmap.rect(), Qt::white);
        newPainter.drawPixmap(0, 0, _pixmap);
        _pixmap = newPixmap;
    }
}

void    QPaintWidget::clear() {
    _pixmap.fill(Qt::white);
    this->clearMask();
}

void    QPaintWidget::draw(const QPoint &position, Qt::MouseButton click){
    if (_stop == false && _draw){
        QPainter painter{&_pixmap};
        painter.setPen(_pen);
        painter.drawLine(_lastposition, position);
        _lastposition = position;
        update();
    }
}

void    QPaintWidget::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton && _stop == false){
        clear();
        _draw = false;
        _lastposition = event->pos();
    }
    else if (event->button() == Qt::LeftButton){
        _draw = true;
        _lastposition = event->pos();
        draw(event->pos(), event->button());
    }
}

void    QPaintWidget::mouseMoveEvent(QMouseEvent *event){
    draw(event->pos(), event->button());
}

QImage QPaintWidget::drawingImage(){
    int width = 1;
    const int   drawingAreaHeight = 512;
    const int   drawingAreaWidth = 512;
    const int   pixelSize = 28;

    QImage      image(drawingAreaWidth, drawingAreaHeight, QImage::Format_Grayscale8);
    QImage      padImage(512 * width, drawingAreaHeight * width, QImage::Format_Grayscale8);
    QPainter    painter{&padImage};

    this->render(&painter);
    image = padImage.copy(width, width, drawingAreaWidth, drawingAreaHeight);
    image = image.scaled(QSize(pixelSize, pixelSize), Qt::IgnoreAspectRatio);
    return image;
}
















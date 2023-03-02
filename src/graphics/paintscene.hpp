#ifndef PAINTWIDGETS_H
#define PAINTWIDGETS_H

#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QtMath>
#include <QtWidgets>
#include <memory>
#include <QPixmap>
#include <vector>

class PaintScene : public QWidget{

public:
	explicit PaintScene(QWidget *parent = nullptr);
	void    paintEvent(QPaintEvent *event);
	void    resizeEvent(QResizeEvent *event);
	void    mousePressEvent(QMouseEvent *event);
	void    mouseMoveEvent(QMouseEvent *event);
	void    clear();
	void    draw(const QPoint &position, Qt::MouseButton click);
	void    setImage(QImage mg);
	void    setLock(bool lock);
	QImage  getImage();

private:
	static const int _penWidth = 20;
	QPen    _pen;
	bool    _draw;
	bool    _stop;
	QPixmap _pixmap;
	QPoint  _lastposition;
};


#endif // PAINTWIDGETS_H

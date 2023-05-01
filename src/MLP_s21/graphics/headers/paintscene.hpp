#ifndef PAINTWIDGETS_H
#define PAINTWIDGETS_H

#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QtMath>
#include <QtWidgets>
#include <memory>
#include <QPixmap>
#include <QColor>
#include <vector>
#include "secondwindow.hpp"

namespace s21 {

class PaintScene : public QWidget{

public:
    explicit PaintScene(QWidget *parent = nullptr);
    ~PaintScene() override = default;

    const QImage& getImage();
    void  setImage(const QString& path);
    bool isClear();
    void setWindow(secondWindow* win);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void clearImage();
    void draw(const QPoint& point);
    const std::vector<double>& vectorsInImage();

private:
    secondWindow* secondWin;
    QPoint _lastPoint;
    QImage _image;
    QImage _resize;
    std::vector<double> _pixelVec;
    bool _drag;
    static constexpr double lineWidth = 40;
    static constexpr int pixelSize = 28;
};
}


#endif // PAINTWIDGETS_H

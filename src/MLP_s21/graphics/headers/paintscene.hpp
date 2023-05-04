#ifndef PAINTWIDGETS_H
#define PAINTWIDGETS_H

#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QtMath>
#include <QtWidgets>
#include <memory>
#include <vector>

#include "secondwindow.hpp"

namespace s21 {

class PaintScene : public QWidget {
 public:
  explicit PaintScene(QWidget* parent = nullptr);
  ~PaintScene() override = default;

  const QImage& GetImage();
  void SetImage(const QString& path);
  bool IsClear();
  void SetWindow(secondWindow* win);
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void paintEvent(QPaintEvent* event) override;
  void ClearImage();
  void Draw(const QPoint& point);
  const std::vector<double>& VectorsInImage();

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
}  // namespace s21

#endif  // PAINTWIDGETS_H

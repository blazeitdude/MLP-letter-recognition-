#include "headers/paintscene.hpp"

#include <QPainter>

namespace s21 {

PaintScene::PaintScene(QWidget *parent)
    : QWidget(parent),
      _image(QSize(512, 512), QImage::Format_RGB16),
      _drag(false) {
  ClearImage();
}

void PaintScene::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    _lastPoint = event->pos();
    _drag = true;
  } else {
    ClearImage();
  }
}

void PaintScene::mouseMoveEvent(QMouseEvent *event) {
  if ((event->buttons() & Qt::LeftButton) && _drag) {
    Draw(event->pos());
  }
}

void PaintScene::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && _drag) {
    Draw(event->pos());
    _drag = false;
  }
  secondWin->Predict();
}

void PaintScene::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect rect(event->rect());
  painter.drawImage(rect, _image, rect);
}

void PaintScene::Draw(const QPoint &point) {
  QPainter painter(&_image);
  painter.setPen(
      QPen(Qt::black, lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  painter.setRenderHint(QPainter::SmoothPixmapTransform);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.drawLine(_lastPoint, point);

  int rad = (lineWidth / 2) + 2;
  update(
      QRect(_lastPoint, point).normalized().adjusted(-rad, -rad, +rad, +rad));
  _lastPoint = point;
}

void PaintScene::ClearImage() {
  _image.fill(qRgb(0xFF, 0xFF, 0xFF));
  update();
}

const QImage &PaintScene::GetImage() { return _image; }

void PaintScene::SetImage(const QString &filePath) {
  ClearImage();
  _image.load(filePath);
  update();
}

bool PaintScene::IsClear() {
  for (int i = 0; i < _image.width(); ++i) {
    for (int j = 0; j < _image.height(); ++j) {
      if (_image.pixelColor(i, j).blackF() != 0.f) {
        return false;
      }
    }
  }
  return true;
}

void PaintScene::SetWindow(secondWindow *win) { secondWin = win; }

const std::vector<double> &PaintScene::VectorsInImage() {
  if (!_pixelVec.empty()) {
    _pixelVec.clear();
  }
  _resize = _image.scaled(pixelSize, pixelSize);
  for (int i = 0; i < pixelSize; ++i) {
    for (int j = 0; j < pixelSize; ++j) {
      _pixelVec.emplace_back(
          static_cast<double>(_resize.pixelColor(i, j).blackF()));
    }
  }
  return _pixelVec;
}
}  // namespace s21

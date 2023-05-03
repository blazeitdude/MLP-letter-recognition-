#include "headers/secondwindow.hpp"

#include <QDebug>

#include "ui_secondwindow.h"

namespace s21 {

secondWindow::secondWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::secondWindow),
      start_window(new LearningStartWindow),
      trainWindow(new LearningMainWindow),
      _controller(new s21::Controller),
      _settingsWindow(new settingsWindow) {
  ui->setupUi(this);
  ui->draw_widget->setWindow(this);
  int idFont =
      QFontDatabase::addApplicationFont(":/MountainsofChristmas-Regular.ttf");
  QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
  QFont IC(itimCyrillic);
  IC.setPixelSize(16);
  this->setFont(IC);
  this->setFont(IC);

  _controller->setNeural(s21::NeuralType::MATRIX, defaultLayer);
  _settingsWindow->setController(_controller);
  connect(this, &secondWindow::testDone, this, &secondWindow::showTestWin);
  connect(this, &secondWindow::trainDone, this, &secondWindow::showTrainWin);
}

secondWindow::~secondWindow() {
  delete start_window;
  delete trainWindow;
  delete _settingsWindow;
  delete ui;
}

void secondWindow::save_image() {
  QString path = QFileDialog::getSaveFileName(
      ui->draw_widget, tr("Save as BMP image"), "", tr("BMP file (*.bmp)"));
  QImage image;

  if (path.isEmpty()) return;
  image = ui->draw_widget->getImage();
  image.save(path);
}

void secondWindow::changeAccept(bool accept) {
  if (accept)
    this->setEnabled(true);
  else
    this->setDisabled(true);
}

auto secondWindow::readPixels(const QImage &image) -> std::vector<double> {
  const double kmaxColor = 255.0;
  const int pixelSize = 28;
  std::vector<double> image_pixels;

  for (int i = 0; i < pixelSize; ++i) {
    for (int j = 0; j < pixelSize; ++j) {
      QRgb pixel = image.pixel(i, j);
      double normalize = (pixel & 0xFF) / kmaxColor;
      image_pixels.push_back(normalize);
    }
  }
  return image_pixels;
}

void secondWindow::predict() {
  if (!ui->draw_widget->isClear()) {
    _controller->initValues(ui->draw_widget->vectorsInImage());
    _controller->feedForward();
    ui->predictLabel->setText(
        QString(QChar(static_cast<int>(_controller->getResult()) + asciiBias)));
  } else {
    ui->predictLabel->setText("");
  }
}

void secondWindow::on_pushButton_learn_clicked() {
  _filePath =
      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                   _emnistPath, QFileDialog::tr("(*.csv)"));
  if (!_filePath.isEmpty()) {
    changeAccept(false);
    _thread = std::thread([&]() {
      if (_settingsWindow->isCrossValid()) {
        if (_settingsWindow->getKGroups() != 1) {
          emit trainDone(_controller->validation(
              _filePath.toStdString(), _settingsWindow->getKGroups()));
        }
      } else {
        emit trainDone(_controller->trainModel(_filePath.toStdString(),
                                               _settingsWindow->getEpochNum()));
      }
      changeAccept(true);
    });
    _thread.detach();
  }
}

void secondWindow::on_pushButton_test_clicked() {
  if (_settingsWindow->getSelection() != 0) {
    _filePath =
        QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                     _emnistPath, QFileDialog::tr("(*.csv)"));
    changeAccept(false);
    if (!_filePath.isEmpty()) {
      _thread = std::thread([&]() {
        _info = _controller->getInfo(_filePath.toStdString(),
                                     _settingsWindow->getSelection());
        start_window->setAccuracy(_info.accuracy);
        start_window->setPrecision(_info.precision);
        start_window->setRecall(_info.recall);
        start_window->setMeasure(_info.f_measure);
        start_window->setTime(_info.ed_time);
        changeAccept(true);
        emit testDone();
      });
      _thread.detach();
    }
  }
}

void secondWindow::showTestWin() { start_window->show(); }

void secondWindow::showTrainWin(const std::vector<double> &values) {
  QString labelName = _settingsWindow->isCrossValid() ? "K-GROUPS" : "EPOCH";
  trainWindow->addData(labelName, values);
  trainWindow->show();
}

void secondWindow::on_saveImageButton_clicked() { save_image(); }

void secondWindow::on_uploadImageButton_clicked() {
  QString path = QFileDialog::getOpenFileName(this, "File Selection", "",
                                              tr("BMP file (*.bmp)"));

  if (path.isEmpty()) return;
  ui->draw_widget->setImage(path);
  predict();
}

void secondWindow::on_saveWeightsButton_clicked() {
  _filePath =
      QFileDialog::getExistingDirectory(
          this, "Open directory to save file", _weightsPath,
          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
      "/";
  if (!_filePath.isEmpty()) {
    _fileName = _filePath + "weights_" +
                QString::number((_settingsWindow->getLayersNum()));
    _controller->saveWeights(_fileName.toStdString() + ".txt");
  }
}

void secondWindow::on_uploadWeightsButton_clicked() {
  _filePath =
      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                   _weightsPath, QFileDialog::tr("(*.txt)"));
  if (!_filePath.isEmpty()) {
    _controller->loadWeights(_filePath.toStdString());
  }
}

void secondWindow::on_settingsPushButton_clicked() { _settingsWindow->show(); }

}  // namespace s21
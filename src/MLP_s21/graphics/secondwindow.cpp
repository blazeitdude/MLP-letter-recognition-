#include "headers/secondwindow.hpp"

#include <QDebug>

#include "ui_secondwindow.h"

namespace s21 {

secondWindow::secondWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::secondWindow),
      _startWindow(new LearningStartWindow),
      _trainWindow(new LearningMainWindow),
      _controller(new s21::Controller),
      _settingsWindow(new settingsWindow) {
  ui->setupUi(this);
  ui->draw_widget->SetWindow(this);
  int idFont =
      QFontDatabase::addApplicationFont(":/MountainsofChristmas-Regular.ttf");
  QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
  QFont IC(itimCyrillic);
  IC.setPixelSize(16);
  this->setFont(IC);
  this->setFont(IC);

  _controller->SetNeural(s21::NeuralType::MATRIX, defaultLayer);
  _settingsWindow->SetController(_controller);
  connect(this, &secondWindow::TestDone, this, &secondWindow::ShowTestWin);
  connect(this, &secondWindow::TrainDone, this, &secondWindow::ShowTrainWin);
}

secondWindow::~secondWindow() {
  delete _startWindow;
  delete _trainWindow;
  delete _settingsWindow;
  delete ui;
}

void secondWindow::SaveImage() {
  QString path = QFileDialog::getSaveFileName(
      ui->draw_widget, tr("Save as BMP image"), "", tr("BMP file (*.bmp)"));
  QImage image;

  if (path.isEmpty()) return;
  image = ui->draw_widget->GetImage();
  image.save(path);
}

void secondWindow::ChangeAccept(bool accept) {
  if (accept)
    this->setEnabled(true);
  else
    this->setDisabled(true);
}

auto secondWindow::ReadPixels(const QImage &image) -> std::vector<double> {
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

void secondWindow::Predict() {
  if (!ui->draw_widget->IsClear()) {
    _controller->InitValues(ui->draw_widget->VectorsInImage());
    _controller->FeedForward();
    ui->predictLabel->setText(
        QString(QChar(static_cast<int>(_controller->GetResult()) + asciiBias)));
  } else {
    ui->predictLabel->setText("");
  }
}

void secondWindow::on_pushButton_learn_clicked() {
  _filePath =
      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                   _emnistPath, QFileDialog::tr("(*.csv)"));
  if (!_filePath.isEmpty()) {
    ChangeAccept(false);
    _thread = std::thread([&]() {
      if (_settingsWindow->IsCrossValid()) {
        if (_settingsWindow->GetKGroups() != 1) {
          emit TrainDone(_controller->Validation(
              _filePath.toStdString(), _settingsWindow->GetKGroups()));
        }
      } else {
        emit TrainDone(_controller->TrainModel(_filePath.toStdString(),
                                               _settingsWindow->GetEpochNum()));
      }
      ChangeAccept(true);
    });
    _thread.detach();
  }
}

void secondWindow::on_pushButton_test_clicked() {
  if (_settingsWindow->GetSelection() != 0) {
    _filePath =
        QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                     _emnistPath, QFileDialog::tr("(*.csv)"));
    ChangeAccept(false);
    if (!_filePath.isEmpty()) {
      _thread = std::thread([&]() {
        _info = _controller->GetInfo(_filePath.toStdString(),
                                     _settingsWindow->GetSelection());
        _startWindow->SetAccuracy(_info.accuracy);
        _startWindow->SetPrecision(_info.precision);
        _startWindow->SetRecall(_info.recall);
        _startWindow->SetMeasure(_info.f_measure);
        _startWindow->SetTime(_info.ed_time);
        ChangeAccept(true);
        emit TestDone();
      });
      _thread.detach();
    }
  }
}

void secondWindow::ShowTestWin() { _startWindow->show(); }

void secondWindow::ShowTrainWin(const std::vector<double> &values) {
  QString labelName = _settingsWindow->IsCrossValid() ? "K-GROUPS" : "EPOCH";
  _trainWindow->AddData(labelName, values);
  _trainWindow->show();
}

void secondWindow::on_saveImageButton_clicked() { SaveImage(); }

void secondWindow::on_uploadImageButton_clicked() {
  QString path = QFileDialog::getOpenFileName(this, "File Selection", "",
                                              tr("BMP file (*.bmp)"));

  if (path.isEmpty()) return;
  ui->draw_widget->SetImage(path);
  Predict();
}

void secondWindow::on_saveWeightsButton_clicked() {
  _filePath =
      QFileDialog::getExistingDirectory(
          this, "Open directory to save file", _weightsPath,
          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
      "/";
  if (!_filePath.isEmpty()) {
    _fileName = _filePath + "weights_" +
                QString::number((_settingsWindow->GetLayersNum()));
    _controller->SaveWeights(_fileName.toStdString() + ".txt");
  }
}

void secondWindow::on_uploadWeightsButton_clicked() {
  _filePath =
      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                   _weightsPath, QFileDialog::tr("(*.txt)"));
  if (!_filePath.isEmpty()) {
    _controller->LoadWeights(_filePath.toStdString());
  }
}

void secondWindow::on_settingsPushButton_clicked() { _settingsWindow->show(); }

}  // namespace s21
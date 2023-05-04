#ifndef SECONDWINDOW_HPP
#define SECONDWINDOW_HPP

#include <QDialog>
#include <QDir>
#include <QFontDatabase>
#include <QImage>
#include <QWidget>
#include <chrono>
#include <thread>

#include "../../controller/controller.hpp"
#include "learningmainwindow.hpp"
#include "learningstartwindow.hpp"
#include "settingswindow.h"

namespace Ui {
class secondWindow;
}

namespace s21 {
class secondWindow : public QDialog {
  Q_OBJECT

 public:
  explicit secondWindow(QWidget* parent = nullptr);
  ~secondWindow();
  void ChangeAccept(bool accept);
  void Predict();

  auto ReadPixels(const QImage& image) -> std::vector<double>;
  void SaveImage();

 private slots:

  void on_pushButton_learn_clicked();

  void on_pushButton_test_clicked();
  void ShowTestWin();
  void ShowTrainWin(const std::vector<double>& values);

  void on_saveImageButton_clicked();

  void on_uploadImageButton_clicked();

  void on_saveWeightsButton_clicked();

  void on_uploadWeightsButton_clicked();

  void on_settingsPushButton_clicked();

 signals:
  void TestDone();
  void TrainDone(const std::vector<double>& values);

 private:
  Ui::secondWindow* ui;
  LearningStartWindow* _startWindow;
  LearningMainWindow* _trainWindow;
  settingsWindow* _settingsWindow;
  s21::Controller* _controller;
  QString _filePath;
  QString _fileName;
  s21::Info _info;
  const QString _emnistPath = "../../datasets/";
  const QString _weightsPath = "../../weights/";
  std::thread _thread;
  static constexpr int defaultLayer = 2;
  static constexpr int asciiBias = 65;
};
}  // namespace s21

#endif  // SECONDWINDOW_HPP

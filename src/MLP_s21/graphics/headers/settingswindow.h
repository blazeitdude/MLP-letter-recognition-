#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QCloseEvent>
#include <QDialog>
#include <QFontDatabase>

#include "../../controller/controller.hpp"

namespace Ui {
class settingsWindow;
}

namespace s21 {

class settingsWindow : public QDialog {
  Q_OBJECT

 public:
  explicit settingsWindow(QWidget* parent = nullptr);
  ~settingsWindow();

  int GetLayersNum();
  void SetController(s21::Controller* controller);
  double GetSelection();
  size_t GetEpochNum();
  bool IsCrossValid();
  size_t GetKGroups();

 private slots:
  void on_crossValidationCheck_stateChanged(int arg1);

 private:
  auto closeEvent(QCloseEvent* event) -> void override;

 private:
  Ui::settingsWindow* ui;
  s21::Controller* _controller;
};

}  // namespace s21
#endif  // SETTINGSWINDOW_H

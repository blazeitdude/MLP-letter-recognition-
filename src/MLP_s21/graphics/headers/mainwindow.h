#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QFontDatabase>
#include <QMainWindow>
#include <QMessageBox>

#include "secondwindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void on_pushButton_clicked();

 private:
  Ui::MainWindow *ui;
  secondWindow *win;
};
}  // namespace s21
#endif  // MAINWINDOW_H

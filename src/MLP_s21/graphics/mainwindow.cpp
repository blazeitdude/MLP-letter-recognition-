#include "headers/mainwindow.h"

#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), win(new secondWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete win;
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  win->setFixedSize(1440, 1024);
  win->show();
  this->hide();
}
}  // namespace s21
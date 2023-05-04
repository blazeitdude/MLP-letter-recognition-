#include "headers/learningstartwindow.hpp"

#include <QDebug>

#include "ui_learningstartwindow.h"

namespace s21 {

LearningStartWindow::LearningStartWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LearningStartWindow) {
  ui->setupUi(this);
}

LearningStartWindow::~LearningStartWindow() { delete ui; }

void LearningStartWindow::SetAccuracy(const double accuracy) {
  ui->accuracyLabel->setText(QString::number(accuracy * 100, 'g', 2) + " %");
}

void LearningStartWindow::SetPrecision(const double presicion) {
  ui->precisionLabel->setText(QString::number(presicion * 100, 'g', 2) + " %");
}

void LearningStartWindow::SetRecall(const double recall) {
  ui->recallLabel->setText(QString::number(recall * 100, 'g', 2) + " %");
}

void LearningStartWindow::SetMeasure(const double measure) {
  ui->measureLabel->setText(QString::number(measure * 100, 'g', 2) + " %");
}

void LearningStartWindow::SetTime(const double time) {
  ui->timeLabel->setText(QString::number(time, 'g', 2) + " s");
}

}  // namespace s21

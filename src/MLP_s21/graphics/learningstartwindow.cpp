#include "headers/learningstartwindow.hpp"

#include <QDebug>

#include "ui_learningstartwindow.h"

namespace s21 {

LearningStartWindow::LearningStartWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LearningStartWindow) {
  ui->setupUi(this);
}

LearningStartWindow::~LearningStartWindow() { delete ui; }

void LearningStartWindow::setAccuracy(const double accuracy) {
  ui->accuracyLabel->setText(QString::number(accuracy * 100, 'g', 2) + " %");
}

void LearningStartWindow::setPrecision(const double presicion) {
  ui->precisionLabel->setText(QString::number(presicion * 100, 'g', 2) + " %");
}

void LearningStartWindow::setRecall(const double recall) {
  ui->recallLabel->setText(QString::number(recall * 100, 'g', 2) + " %");
}

void LearningStartWindow::setMeasure(const double measure) {
  ui->measureLabel->setText(QString::number(measure * 100, 'g', 2) + " %");
}

void LearningStartWindow::setTime(const double time) {
  ui->timeLabel->setText(QString::number(time * 100, 'g', 2) + " s");
}

}  // namespace s21

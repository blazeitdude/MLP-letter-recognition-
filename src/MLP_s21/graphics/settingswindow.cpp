#include "headers/settingswindow.h"

#include <QString>

#include "ui_settingswindow.h"

namespace s21 {

settingsWindow::settingsWindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::settingsWindow) {
  ui->setupUi(this);
  ui->kgroupSpin->setDisabled(true);

  int idFont =
      QFontDatabase::addApplicationFont(":/MountainsofChristmas-Regular.ttf");
  QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
  QFont IC(itimCyrillic);
  IC.setPixelSize(16);
  this->setFont(IC);
  this->setFont(IC);

  for (int i = 2; i <= 5; ++i) {
    ui->layers_comboBox->addItem(QString::number(i));
  }
  for (int i = 1; i <= 10; ++i) {
    ui->epochs_comboBox->addItem(QString::number(i));
  }
}

settingsWindow::~settingsWindow() { delete ui; }

int settingsWindow::getLayersNum() {
  return ui->layers_comboBox->currentText().toInt();
}

size_t settingsWindow::getEpochNum() {
  return ui->epochs_comboBox->currentText().toUInt();
}

double settingsWindow::getSelection() { return ui->doubleSpinBox->value(); }

bool settingsWindow::isCrossValid() {
  return ui->crossValidationCheck->isChecked();
}

size_t settingsWindow::getKGroups() {
  return static_cast<size_t>(ui->kgroupSpin->value());
}

void settingsWindow::setController(s21::Controller* controller) {
  _controller = controller;
}

void settingsWindow::on_crossValidationCheck_stateChanged(int arg1) {
  if (arg1) {
    ui->kgroupSpin->setEnabled(true);
  } else {
    ui->kgroupSpin->setValue(1);
    ui->kgroupSpin->setDisabled(true);
  }
}

auto settingsWindow::closeEvent(QCloseEvent* event) -> void {
  s21::NeuralType netType;
  if (ui->radioButton_matrix->isChecked()) {
    netType = s21::NeuralType::MATRIX;
  } else {
    netType = s21::NeuralType::GRAPH;
  }
  _controller->setNeural(netType, ui->layers_comboBox->currentText().toInt());
  event->accept();
}

}  // namespace s21

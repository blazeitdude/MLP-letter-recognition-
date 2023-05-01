#include "headers/settingswindow.h"

#include <QString>

#include "ui_settingswindow.h"

namespace s21 {

settingsWindow::settingsWindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::settingsWindow) {
  ui->setupUi(this);
  ui->kgroupSpin->setDisabled(true);

  for (int i = 2; i <= 5; ++i) {
    ui->layers_comboBox->addItem(QString::number(i));
  }
  for (int i = 1; i <= 30; ++i) {
    ui->epochs_comboBox->addItem(QString::number(i));
  }

  //    ui->horizontalSlider_layer->setTickInterval(1);
  //    ui->horizontalSlider_layer->setMinimum(1);
  //    ui->horizontalSlider_layer->setMaximum(5);
  //    ui->horizontalSlider_layer->setTickPosition(QSlider::TickPosition(1));

  //    ui->horizontalSlider_epochs->setTickInterval(1);
  //    ui->horizontalSlider_epochs->setMinimum(5);
  //    ui->horizontalSlider_epochs->setMaximum(30);
  //    ui->horizontalSlider_epochs->setTickPosition(QSlider::TickPosition(5));
}

settingsWindow::~settingsWindow() { delete ui; }

int settingsWindow::getLayersNum() {
  //    return ui->label_numLay->text().toInt();
  return ui->layers_comboBox->currentText().toInt();
}

size_t settingsWindow::getEpochNum() {
  //    return ui->label_numEpoc->text().toUInt();
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
  _controller->setNeural(netType, ui->label_numLay->text().toInt());
  event->accept();
}

void settingsWindow::on_horizontalSlider_layer_valueChanged(int value) {
  qDebug() << value << Qt::endl;
  switch (value) {
    case 1:
      ui->label_numLay->setText(QString("1"));
      break;
    case 2:
      ui->label_numLay->setText(QString("2"));
      break;
    case 3:
      ui->label_numLay->setText(QString("3"));
      break;
    case 4:
      ui->label_numLay->setText(QString("4"));
      break;
    case 5:
      ui->label_numLay->setText(QString("5"));
      break;
  }
}

void settingsWindow::on_horizontalSlider_epochs_valueChanged(int value) {
  qDebug() << value << Qt::endl;
  switch (value) {
    case 5:
      ui->label_numEpoc->setText(QString("5"));
      break;
    case 6:
      ui->label_numEpoc->setText(QString("6"));
      break;
    case 7:
      ui->label_numEpoc->setText(QString("7"));
      break;
    case 8:
      ui->label_numEpoc->setText(QString("8"));
      break;
    case 9:
      ui->label_numEpoc->setText(QString("9"));
      break;
    case 10:
      ui->label_numEpoc->setText(QString("10"));
      break;
    case 11:
      ui->label_numEpoc->setText(QString("11"));
      break;
    case 12:
      ui->label_numEpoc->setText(QString("12"));
      break;
    case 13:
      ui->label_numEpoc->setText(QString("13"));
      break;
    case 14:
      ui->label_numEpoc->setText(QString("14"));
      break;
    case 15:
      ui->label_numEpoc->setText(QString("15"));
      break;
    case 16:
      ui->label_numEpoc->setText(QString("16"));
      break;
    case 17:
      ui->label_numEpoc->setText(QString("17"));
      break;
    case 18:
      ui->label_numEpoc->setText(QString("18"));
      break;
    case 19:
      ui->label_numEpoc->setText(QString("19"));
      break;
    case 20:
      ui->label_numEpoc->setText(QString("20"));
      break;
    case 21:
      ui->label_numEpoc->setText(QString("21"));
      break;
    case 22:
      ui->label_numEpoc->setText(QString("22"));
      break;
    case 23:
      ui->label_numEpoc->setText(QString("23"));
      break;
    case 24:
      ui->label_numEpoc->setText(QString("24"));
      break;
    case 25:
      ui->label_numEpoc->setText(QString("25"));
      break;
    case 26:
      ui->label_numEpoc->setText(QString("26"));
      break;
    case 27:
      ui->label_numEpoc->setText(QString("27"));
      break;
    case 28:
      ui->label_numEpoc->setText(QString("28"));
      break;
    case 29:
      ui->label_numEpoc->setText(QString("29"));
      break;
    case 30:
      ui->label_numEpoc->setText(QString("30"));
      break;
  }
}

}  // namespace s21
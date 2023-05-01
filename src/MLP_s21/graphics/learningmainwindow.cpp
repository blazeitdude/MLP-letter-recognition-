#include "headers/learningmainwindow.hpp"

#include <QApplication>
#include <QtCharts>

#include "ui_learningmainwindow.h"

namespace s21 {

LearningMainWindow::LearningMainWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LearningMainWindow) {
  ui->setupUi(this);
}

LearningMainWindow::~LearningMainWindow() { delete ui; }

void LearningMainWindow::addData(const QString mode,
                                 const std::vector<double> values) {
  QChart *chart = new QChart();
  QValueAxis *xAxis = new QValueAxis();
  QValueAxis *yAxis = new QValueAxis();

  xAxis->setTitleText(mode);
  yAxis->setTitleText("Error");

  chart->addAxis(xAxis, Qt::AlignBottom);
  chart->addAxis(yAxis, Qt::AlignLeft);

  QLineSeries *series = new QLineSeries();
  series->setName("Graphic");

  for (int i = 0; i < values.size(); i++) {
    series->append(i, values[i]);
  }
  chart->addSeries(series);
  series->attachAxis(xAxis);
  series->attachAxis(yAxis);
  xAxis->setRange(0, values.size());
  yAxis->setRange(*std::min_element(values.begin(), values.end()),
                  *std::max_element(values.begin(), values.end()));
  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  ui->verticalLayout->addWidget(chartView);
}
}  // namespace s21
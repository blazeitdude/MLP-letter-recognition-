#include "learningmainwindow.hpp"
#include "ui_learningmainwindow.h"
#include <QtCharts>
#include <QApplication>

LearningMainWindow::LearningMainWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::LearningMainWindow)
{
	ui->setupUi(this);

    QChart *chart = new QChart();
    chart->setTitle("Ошибка на тестовой выборке"); // Задание заголовка

    // Создание объекта для хранения данных графика
    QLineSeries *series = new QLineSeries();

    // Добавление данных на график
    series->append(0, 0.1);
    series->append(1, 0.09);
    series->append(2, 0.07);
    series->append(3, 0.05);
    series->append(4, 0.03);
    series->append(5, 0.02);

    // Добавление объекта с данными на график
    chart->addSeries(series);

    // Создание осей координат
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Эпоха обучения"); // Задание заголовка оси X
    axisX->setLabelFormat("%i"); // Формат отображения меток на оси X
    chart->addAxis(axisX, Qt::AlignBottom); // Добавление оси X на график
    series->attachAxis(axisX); // Привязка данных к оси X

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Ошибка"); // Задание заголовка оси Y
    axisY->setLabelFormat("%.2f"); // Формат отображения меток на оси Y
    chart->addAxis(axisY, Qt::AlignLeft); // Добавление оси Y на график
    series->attachAxis(axisY); // Привязка данных к оси Y

    // Создание объекта для отображения графика
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);
}

LearningMainWindow::~LearningMainWindow()
{
	delete ui;
}

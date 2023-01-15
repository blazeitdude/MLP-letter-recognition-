#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <paintwidgets.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QPainter painter(this);
    ui->setupUi(this);
    widget = new QPaintWidget();
    ui->verticalLayout->addWidget(widget);
}

MainWindow::~MainWindow()
{
    widget->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::changeEvent(QEvent *e){
    QMainWindow::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
        }
}

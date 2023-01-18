#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <paintwidgets.h>
#include <QGridLayout>
#include "drawingwindow.h"
#include <QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MultiLayer Perceptron");
}

MainWindow::~MainWindow()
{
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

void MainWindow::on_pushButton_2_clicked()
{
//    this->hide();
//    drawingwindow win;
//    win.setModal(true);
//    win.exec();
    win = new drawingwindow(this);
    win->show();
}


void MainWindow::on_radioButton_clicked()
{

}


void MainWindow::on_radioButton_2_clicked()
{

}


void MainWindow::on_progressBar_valueChanged(int value)
{

}

void MainWindow::on_pushButton_4_clicked()
{

}


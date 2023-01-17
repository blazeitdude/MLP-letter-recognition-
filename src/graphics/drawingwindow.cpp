#include "drawingwindow.h"
#include "ui_drawingwindow.h"

drawingwindow::drawingwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawingwindow)
{
    ui->setupUi(this);
    widget = new QPaintWidget();
    ui->verticalLayout->addWidget(widget);
}

drawingwindow::~drawingwindow()
{
    widget->deleteLater();
    delete ui;
}



void drawingwindow::on_pushButton_clicked()
{
    this->close();
}


void drawingwindow::on_pushButton_2_clicked()
{

}


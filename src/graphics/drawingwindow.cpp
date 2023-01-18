#include "drawingwindow.h"
#include "ui_drawingwindow.h"
#include <QLabel>
#include <QImage>
#include <QString>
#include <QFileDialog>

drawingwindow::drawingwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawingwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Painter");
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

void drawingwindow::savePaint(){
    QString path = QFileDialog::getSaveFileName(widget, tr("Save as BMP image"), "", tr("BMP file (*.bmp)"));

    if (path.isEmpty())
        return;
    const int   drawingAreaHeight = 512;
    const int   drawingAreaWidth = 512;
    const int   pixelSize = 28;
    int width = 1;

    QImage      image(drawingAreaWidth, drawingAreaHeight, QImage::Format_Grayscale8);
    QImage      padImage(512 * width, drawingAreaHeight * width, QImage::Format_Grayscale8);
    QPainter    painter{&padImage};

    this->render(&painter);
    image = padImage.copy(width, width, drawingAreaWidth, drawingAreaHeight);
    //mage = image.scaled(QSize(pixelSize, pixelSize), Qt::IgnoreAspectRatio);
    image.save(path);
}

void drawingwindow::on_pushButton_2_clicked()
{
    savePaint();
}


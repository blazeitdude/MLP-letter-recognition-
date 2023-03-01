#include "secondwindow.hpp"
#include "ui_secondwindow.h"
#include <QDebug>

secondWindow::secondWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::secondWindow)
{

	ui->setupUi(this);
	int idFont = QFontDatabase::addApplicationFont("/Users/ldione/Desktop/MLP_Design/resources/MountainsofChristmas-Regular.ttf");
		QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
		QFont IC(itimCyrillic);
		IC.setPixelSize(16);
		this->setFont(IC);
	this->setFont(IC);
	paint = new PaintScene(this);
	ui->gridLayout->addWidget(paint);
	ui->horizontalSlider->setTickInterval(1);
	ui->horizontalSlider->setMinimum(1);
	ui->horizontalSlider->setMaximum(5);
	ui->horizontalSlider->setTickPosition(QSlider::TickPosition(1));
	ui->label->setAlignment(Qt::AlignCenter);
}

secondWindow::~secondWindow()
{
	delete ui;
}

void secondWindow::on_pushButton_clicked()
{
	save_image();
}

void secondWindow::on_pushButton_pressed()
{
}


void secondWindow::on_pushButton_released()
{
}


void	secondWindow::save_image() {
	QString path = QFileDialog::getSaveFileName(paint, tr("Save as BMP image"), "", tr("BMP file (*.bmp)"));
	QImage	image;

	if (path.isEmpty())
		return;
	image = paint->getImage();
	image.save(path);
}

void secondWindow::on_pushButton_2_clicked()
{
	QString path = QFileDialog::getOpenFileName(paint, "File Selection", "", tr("BMP file (*.bmp)"));
	QImage	img;

	if (path.isEmpty())
		return;
	img.load(path, "*.bmp");
	paint->setImage(img);
}


void secondWindow::on_horizontalSlider_valueChanged(int value)
{
	qDebug() << value << Qt::endl;
	switch (value) {
	case 1:
		ui->label_2->setText(QString("1"));
		break;
	case 2:
		ui->label_2->setText(QString("2"));
		break;
	case 3:
		ui->label_2->setText(QString("3"));
		break;
	case 4:
		ui->label_2->setText(QString("4"));
		break;
	case 5:
		ui->label_2->setText(QString("5"));
		break;
	}
}


void secondWindow::on_pushButton_4_clicked()
{
	this->hide();
	start_window = new LearningStartWindow();
	start_window->setFixedSize(450, 300);
	start_window->show();
}


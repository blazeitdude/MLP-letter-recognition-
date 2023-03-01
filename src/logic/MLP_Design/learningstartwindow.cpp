#include "learningstartwindow.hpp"
#include "ui_learningstartwindow.h"
#include <QDebug>

LearningStartWindow::LearningStartWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::LearningStartWindow)
{
	ui->setupUi(this);
	ui->horizontalSlider->setTickInterval(1);
	ui->horizontalSlider->setMinimum(5);
	ui->horizontalSlider->setMaximum(30);
	ui->horizontalSlider->setTickPosition(QSlider::TickPosition(5));
}

LearningStartWindow::~LearningStartWindow()
{
	delete ui;
}

void LearningStartWindow::on_horizontalSlider_valueChanged(int value)
{
	qDebug() << value << Qt::endl;
	switch (value) {
	case 5:
		ui->label->setText(QString("5"));
		break;
	case 6:
		ui->label->setText(QString("6"));
		break;
	case 7:
		ui->label->setText(QString("7"));
		break;
	case 8:
		ui->label->setText(QString("8"));
		break;
	case 9:
		ui->label->setText(QString("9"));
		break;
	case 10:
		ui->label->setText(QString("10"));
		break;
	case 11:
		ui->label->setText(QString("11"));
		break;
	case 12:
		ui->label->setText(QString("12"));
		break;
	case 13:
		ui->label->setText(QString("13"));
		break;
	case 14:
		ui->label->setText(QString("14"));
		break;
	case 15:
		ui->label->setText(QString("15"));
		break;
	case 16:
		ui->label->setText(QString("16"));
		break;
	case 17:
		ui->label->setText(QString("17"));
		break;
	case 18:
		ui->label->setText(QString("18"));
		break;
	case 19:
		ui->label->setText(QString("19"));
		break;
	case 20:
		ui->label->setText(QString("20"));
		break;
	case 21:
		ui->label->setText(QString("21"));
		break;
	case 22:
		ui->label->setText(QString("22"));
		break;
	case 23:
		ui->label->setText(QString("23"));
		break;
	case 24:
		ui->label->setText(QString("24"));
		break;
	case 25:
		ui->label->setText(QString("25"));
		break;
	case 26:
		ui->label->setText(QString("26"));
		break;
	case 27:
		ui->label->setText(QString("27"));
		break;
	case 28:
		ui->label->setText(QString("28"));
		break;
	case 29:
		ui->label->setText(QString("29"));
		break;
	case 30:
		ui->label->setText(QString("30"));
		break;

	}
}


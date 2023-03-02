#include "learningmainwindow.hpp"
#include "ui_learningmainwindow.h"

LearningMainWindow::LearningMainWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::LearningMainWindow)
{
	ui->setupUi(this);
}

LearningMainWindow::~LearningMainWindow()
{
	delete ui;
}

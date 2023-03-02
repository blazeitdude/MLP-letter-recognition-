#ifndef SECONDWINDOW_HPP
#define SECONDWINDOW_HPP

#include <QWidget>
#include <QFontDatabase>
#include <QDialog>
#include "paintscene.hpp"
#include <QImage>
#include "learningstartwindow.hpp"
#include "learningmainwindow.hpp"

namespace Ui {
class secondWindow;
}

class secondWindow : public QDialog
{
	Q_OBJECT

public:
	explicit secondWindow(QWidget *parent = nullptr);
	~secondWindow();

private slots:
	void	on_pushButton_clicked();

	void	on_pushButton_pressed();

	void	on_pushButton_released();

	void	save_image();

	void on_pushButton_2_clicked();

	void on_horizontalSlider_valueChanged(int value);

	void on_pushButton_4_clicked();

private:
	Ui::secondWindow*		ui;
	PaintScene*				paint;
	LearningStartWindow*	start_window;
};

#endif // SECONDWINDOW_HPP

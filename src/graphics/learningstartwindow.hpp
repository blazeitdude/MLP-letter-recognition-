#ifndef LEARNINGSTARTWINDOW_HPP
#define LEARNINGSTARTWINDOW_HPP

#include <QDialog>
#include "learningmainwindow.hpp"

namespace Ui {
class LearningStartWindow;
}

class LearningStartWindow : public QDialog
{
	Q_OBJECT

public:
	explicit LearningStartWindow(QWidget *parent = nullptr);
	~LearningStartWindow();

private slots:
	void on_horizontalSlider_valueChanged(int value);

	void on_pushButton_clicked();

private:
	Ui::LearningStartWindow *ui;
	LearningMainWindow*	main_window;
};

#endif // LEARNINGSTARTWINDOW_HPP

#ifndef LEARNINGSTARTWINDOW_HPP
#define LEARNINGSTARTWINDOW_HPP

#include <QDialog>

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

private:
	Ui::LearningStartWindow *ui;
};

#endif // LEARNINGSTARTWINDOW_HPP

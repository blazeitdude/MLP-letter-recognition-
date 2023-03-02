#ifndef LEARNINGMAINWINDOW_HPP
#define LEARNINGMAINWINDOW_HPP

#include <QDialog>

namespace Ui {
class LearningMainWindow;
}

class LearningMainWindow : public QDialog
{
	Q_OBJECT

public:
	explicit LearningMainWindow(QWidget *parent = nullptr);
	~LearningMainWindow();

private:
	Ui::LearningMainWindow *ui;
};

#endif // LEARNINGMAINWINDOW_HPP

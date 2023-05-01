#ifndef LEARNINGSTARTWINDOW_HPP
#define LEARNINGSTARTWINDOW_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class LearningStartWindow;
}

namespace s21 {
class LearningStartWindow : public QDialog
{
	Q_OBJECT

public:
	explicit LearningStartWindow(QWidget *parent = nullptr);
	~LearningStartWindow();
    void setAccuracy(const double accuracy);
    void setPrecision(const double precision);
    void setRecall(const double recall);
    void setMeasure(const double measure);
    void setTime(const double time);

private:
	Ui::LearningStartWindow *ui;
};
}

#endif // LEARNINGSTARTWINDOW_HPP

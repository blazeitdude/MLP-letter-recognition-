#ifndef LEARNINGSTARTWINDOW_HPP
#define LEARNINGSTARTWINDOW_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class LearningStartWindow;
}

namespace s21 {
class LearningStartWindow : public QDialog {
  Q_OBJECT

 public:
  explicit LearningStartWindow(QWidget *parent = nullptr);
  ~LearningStartWindow();
  void SetAccuracy(const double accuracy);
  void SetPrecision(const double precision);
  void SetRecall(const double recall);
  void SetMeasure(const double measure);
  void SetTime(const double time);

 private:
  Ui::LearningStartWindow *ui;
};
}  // namespace s21

#endif  // LEARNINGSTARTWINDOW_HPP

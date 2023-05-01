#ifndef LEARNINGMAINWINDOW_HPP
#define LEARNINGMAINWINDOW_HPP

#include <QDialog>

namespace Ui {
class LearningMainWindow;
}

namespace s21 {
class LearningMainWindow : public QDialog {
  Q_OBJECT

 public:
  explicit LearningMainWindow(QWidget *parent = nullptr);
  ~LearningMainWindow();
  void addData(const QString mode, const std::vector<double> values);

 private:
  Ui::LearningMainWindow *ui;
};

}  // namespace s21

#endif  // LEARNINGMAINWINDOW_HPP

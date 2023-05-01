#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.hpp"
#include <QMessageBox>
#include <QEvent>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

	void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    secondWindow *win;
};
}
#endif // MAINWINDOW_H

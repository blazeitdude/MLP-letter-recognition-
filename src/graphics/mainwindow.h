#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWidget>
#include "paintwidgets.h"
#include <QMdiArea>
#include "drawingwindow.h"
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_progressBar_valueChanged(int value);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    drawingwindow   *win;
    QProgressBar    *bar;
};




#endif // MAINWINDOW_H

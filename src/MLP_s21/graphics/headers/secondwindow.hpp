#ifndef SECONDWINDOW_HPP
#define SECONDWINDOW_HPP

#include <QWidget>
#include <QFontDatabase>
#include <QDialog>
#include <QImage>
#include <thread>
#include <chrono>
#include <QDir>
#include "learningstartwindow.hpp"
#include "learningmainwindow.hpp"
#include "../../controller/controller.hpp"
#include "settingswindow.h"

namespace Ui {
class secondWindow;
}

namespace s21 {
class secondWindow : public QDialog
{
	Q_OBJECT

public:
	explicit secondWindow(QWidget *parent = nullptr);
	~secondWindow();
    void changeAccept(bool accept);
    void predict();

    auto readPixels(const QImage &image) -> std::vector<double>;
    void	save_image();


private slots:

    void on_pushButton_learn_clicked();

    void on_pushButton_test_clicked();
    void showTestWin();
    void showTrainWin(const std::vector<double>& values);

    void on_saveImageButton_clicked();

    void on_uploadImageButton_clicked();

    void on_saveWeightsButton_clicked();

    void on_uploadWeightsButton_clicked();

    void on_settingsPushButton_clicked();

signals:
    void testDone();
    void trainDone(const std::vector<double>& values);

private:
	Ui::secondWindow*		ui;
	LearningStartWindow*	start_window;
    LearningMainWindow*     trainWindow;
    settingsWindow*         _settingsWindow;
    s21::Controller*        _controller;
    QString                 _filePath;
    QString                 _fileName;
    s21::Info               _info;
    const QString           _emnistPath = "../../datasets/";
    const QString           _weightsPath = "../../weights/";
    std::thread             _thread;
    static constexpr int defaultLayer = 2;
    static constexpr int asciiBias = 65;
};
}

#endif // SECONDWINDOW_HPP

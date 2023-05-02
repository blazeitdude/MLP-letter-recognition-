/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "../graphics/headers/paintscene.hpp"

QT_BEGIN_NAMESPACE

class Ui_secondWindow
{
public:
    QPushButton *saveImageButton;
    QLabel *predictLabel;
    QPushButton *pushButton_learn;
    QPushButton *uploadWeightsButton;
    QPushButton *saveWeightsButton;
    QPushButton *uploadImageButton;
    QPushButton *pushButton_test;
    QPushButton *settingsPushButton;
    s21::PaintScene *draw_widget;

    void setupUi(QWidget *secondWindow)
    {
        if (secondWindow->objectName().isEmpty())
            secondWindow->setObjectName(QString::fromUtf8("secondWindow"));
        secondWindow->resize(1230, 889);
        saveImageButton = new QPushButton(secondWindow);
        saveImageButton->setObjectName(QString::fromUtf8("saveImageButton"));
        saveImageButton->setGeometry(QRect(350, 730, 283, 62));
        saveImageButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        predictLabel = new QLabel(secondWindow);
        predictLabel->setObjectName(QString::fromUtf8("predictLabel"));
        predictLabel->setGeometry(QRect(670, 220, 201, 161));
        QFont font;
        font.setPointSize(38);
        predictLabel->setFont(font);
        pushButton_learn = new QPushButton(secondWindow);
        pushButton_learn->setObjectName(QString::fromUtf8("pushButton_learn"));
        pushButton_learn->setGeometry(QRect(850, 450, 283, 62));
        pushButton_learn->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        uploadWeightsButton = new QPushButton(secondWindow);
        uploadWeightsButton->setObjectName(QString::fromUtf8("uploadWeightsButton"));
        uploadWeightsButton->setGeometry(QRect(850, 720, 283, 62));
        uploadWeightsButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        saveWeightsButton = new QPushButton(secondWindow);
        saveWeightsButton->setObjectName(QString::fromUtf8("saveWeightsButton"));
        saveWeightsButton->setGeometry(QRect(850, 630, 283, 62));
        saveWeightsButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        uploadImageButton = new QPushButton(secondWindow);
        uploadImageButton->setObjectName(QString::fromUtf8("uploadImageButton"));
        uploadImageButton->setGeometry(QRect(40, 730, 283, 62));
        uploadImageButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        pushButton_test = new QPushButton(secondWindow);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));
        pushButton_test->setGeometry(QRect(850, 540, 283, 62));
        pushButton_test->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        settingsPushButton = new QPushButton(secondWindow);
        settingsPushButton->setObjectName(QString::fromUtf8("settingsPushButton"));
        settingsPushButton->setGeometry(QRect(850, 150, 283, 62));
        settingsPushButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
"height: 46px;\n"
"left: 115px;\n"
"top: 766px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF"));
        draw_widget = new s21::PaintScene(secondWindow);
        draw_widget->setObjectName(QString::fromUtf8("draw_widget"));
        draw_widget->setGeometry(QRect(50, 150, 512, 512));

        retranslateUi(secondWindow);

        QMetaObject::connectSlotsByName(secondWindow);
    } // setupUi

    void retranslateUi(QWidget *secondWindow)
    {
        secondWindow->setWindowTitle(QCoreApplication::translate("secondWindow", "Form", nullptr));
        saveImageButton->setText(QCoreApplication::translate("secondWindow", "Save Image", nullptr));
        predictLabel->setText(QCoreApplication::translate("secondWindow", "Prediction", nullptr));
        pushButton_learn->setText(QCoreApplication::translate("secondWindow", "Start Learning", nullptr));
        uploadWeightsButton->setText(QCoreApplication::translate("secondWindow", "Upload Weights", nullptr));
        saveWeightsButton->setText(QCoreApplication::translate("secondWindow", "Save Weights", nullptr));
        uploadImageButton->setText(QCoreApplication::translate("secondWindow", "Upload Image", nullptr));
        pushButton_test->setText(QCoreApplication::translate("secondWindow", "Test", nullptr));
        settingsPushButton->setText(QCoreApplication::translate("secondWindow", "SETTINGS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondWindow: public Ui_secondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H

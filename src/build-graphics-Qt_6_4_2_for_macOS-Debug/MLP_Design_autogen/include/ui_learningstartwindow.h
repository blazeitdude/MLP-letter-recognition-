/********************************************************************************
** Form generated from reading UI file 'learningstartwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNINGSTARTWINDOW_H
#define UI_LEARNINGSTARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_LearningStartWindow
{
public:
    QSlider *horizontalSlider;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *LearningStartWindow)
    {
        if (LearningStartWindow->objectName().isEmpty())
            LearningStartWindow->setObjectName("LearningStartWindow");
        LearningStartWindow->resize(450, 300);
        horizontalSlider = new QSlider(LearningStartWindow);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(30, 150, 160, 25));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(LearningStartWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 100, 41, 61));
        label->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 208px;\n"
"height: 46px;\n"
"left: 720px;\n"
"top: 246px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"text-align:center;\n"
"\n"
"color: #FFFFFF;\n"
""));
        pushButton = new QPushButton(LearningStartWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 210, 171, 51));

        retranslateUi(LearningStartWindow);

        QMetaObject::connectSlotsByName(LearningStartWindow);
    } // setupUi

    void retranslateUi(QDialog *LearningStartWindow)
    {
        LearningStartWindow->setWindowTitle(QCoreApplication::translate("LearningStartWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LearningStartWindow", "1", nullptr));
        pushButton->setText(QCoreApplication::translate("LearningStartWindow", "REPORT VIEW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearningStartWindow: public Ui_LearningStartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNINGSTARTWINDOW_H

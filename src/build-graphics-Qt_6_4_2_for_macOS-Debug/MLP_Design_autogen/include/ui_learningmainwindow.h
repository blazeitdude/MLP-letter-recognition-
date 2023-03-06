/********************************************************************************
** Form generated from reading UI file 'learningmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNINGMAINWINDOW_H
#define UI_LEARNINGMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearningMainWindow
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *LearningMainWindow)
    {
        if (LearningMainWindow->objectName().isEmpty())
            LearningMainWindow->setObjectName("LearningMainWindow");
        LearningMainWindow->resize(1000, 700);
        label = new QLabel(LearningMainWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 150, 700, 300));
        progressBar = new QProgressBar(LearningMainWindow);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(40, 520, 371, 23));
        progressBar->setValue(24);
        pushButton = new QPushButton(LearningMainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(800, 500, 141, 51));
        pushButton->setStyleSheet(QString::fromUtf8("width: 253px;\n"
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
        verticalLayoutWidget = new QWidget(LearningMainWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(160, 60, 491, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(LearningMainWindow);

        QMetaObject::connectSlotsByName(LearningMainWindow);
    } // setupUi

    void retranslateUi(QDialog *LearningMainWindow)
    {
        LearningMainWindow->setWindowTitle(QCoreApplication::translate("LearningMainWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LearningMainWindow", "\320\275\321\203 \321\202\320\270\320\277\320\260 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("LearningMainWindow", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearningMainWindow: public Ui_LearningMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNINGMAINWINDOW_H

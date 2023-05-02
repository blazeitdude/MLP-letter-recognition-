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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearningMainWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *LearningMainWindow)
    {
        if (LearningMainWindow->objectName().isEmpty())
            LearningMainWindow->setObjectName("LearningMainWindow");
        LearningMainWindow->resize(850, 550);
        verticalLayoutWidget = new QWidget(LearningMainWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 50, 541, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(LearningMainWindow);

        QMetaObject::connectSlotsByName(LearningMainWindow);
    } // setupUi

    void retranslateUi(QDialog *LearningMainWindow)
    {
        LearningMainWindow->setWindowTitle(QCoreApplication::translate("LearningMainWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearningMainWindow: public Ui_LearningMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNINGMAINWINDOW_H

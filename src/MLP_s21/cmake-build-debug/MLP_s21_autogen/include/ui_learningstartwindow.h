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

QT_BEGIN_NAMESPACE

class Ui_LearningStartWindow
{
public:
    QLabel *accuracyLabel;
    QLabel *precisionLabel;
    QLabel *recallLabel;
    QLabel *measureLabel;
    QLabel *timeLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *LearningStartWindow)
    {
        if (LearningStartWindow->objectName().isEmpty())
            LearningStartWindow->setObjectName("LearningStartWindow");
        LearningStartWindow->resize(557, 424);
        accuracyLabel = new QLabel(LearningStartWindow);
        accuracyLabel->setObjectName("accuracyLabel");
        accuracyLabel->setGeometry(QRect(290, 70, 171, 31));
        precisionLabel = new QLabel(LearningStartWindow);
        precisionLabel->setObjectName("precisionLabel");
        precisionLabel->setGeometry(QRect(290, 140, 171, 31));
        recallLabel = new QLabel(LearningStartWindow);
        recallLabel->setObjectName("recallLabel");
        recallLabel->setGeometry(QRect(290, 210, 171, 31));
        measureLabel = new QLabel(LearningStartWindow);
        measureLabel->setObjectName("measureLabel");
        measureLabel->setGeometry(QRect(290, 270, 171, 31));
        timeLabel = new QLabel(LearningStartWindow);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(290, 330, 171, 31));
        label = new QLabel(LearningStartWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 80, 58, 16));
        label_2 = new QLabel(LearningStartWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 140, 58, 16));
        label_3 = new QLabel(LearningStartWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 210, 58, 16));
        label_4 = new QLabel(LearningStartWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 280, 58, 16));
        label_5 = new QLabel(LearningStartWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 340, 58, 16));

        retranslateUi(LearningStartWindow);

        QMetaObject::connectSlotsByName(LearningStartWindow);
    } // setupUi

    void retranslateUi(QDialog *LearningStartWindow)
    {
        LearningStartWindow->setWindowTitle(QCoreApplication::translate("LearningStartWindow", "Dialog", nullptr));
        accuracyLabel->setText(QCoreApplication::translate("LearningStartWindow", "TextLabel", nullptr));
        precisionLabel->setText(QCoreApplication::translate("LearningStartWindow", "TextLabel", nullptr));
        recallLabel->setText(QCoreApplication::translate("LearningStartWindow", "TextLabel", nullptr));
        measureLabel->setText(QCoreApplication::translate("LearningStartWindow", "TextLabel", nullptr));
        timeLabel->setText(QCoreApplication::translate("LearningStartWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("LearningStartWindow", "Accuracy: ", nullptr));
        label_2->setText(QCoreApplication::translate("LearningStartWindow", "Precision: ", nullptr));
        label_3->setText(QCoreApplication::translate("LearningStartWindow", "Recall:", nullptr));
        label_4->setText(QCoreApplication::translate("LearningStartWindow", "Measure: ", nullptr));
        label_5->setText(QCoreApplication::translate("LearningStartWindow", "Time: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearningStartWindow: public Ui_LearningStartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNINGSTARTWINDOW_H

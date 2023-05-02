/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_settingsWindow
{
public:
    QRadioButton *radioButton_matrix;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QLabel *selectLabel;
    QRadioButton *radioButton_graph;
    QSpinBox *kgroupSpin;
    QLabel *label_2;
    QLabel *label;
    QCheckBox *crossValidationCheck;
    QComboBox *layers_comboBox;
    QComboBox *epochs_comboBox;

    void setupUi(QDialog *settingsWindow)
    {
        if (settingsWindow->objectName().isEmpty())
            settingsWindow->setObjectName("settingsWindow");
        settingsWindow->resize(632, 532);
        radioButton_matrix = new QRadioButton(settingsWindow);
        radioButton_matrix->setObjectName("radioButton_matrix");
        radioButton_matrix->setGeometry(QRect(20, 60, 229, 46));
        radioButton_matrix->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 208px;\n"
"height: 46px;\n"
"left: 720px;\n"
"top: 246px;\n"
"border: solid;\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF;\n"
""));
        radioButton_matrix->setChecked(true);
        doubleSpinBox = new QDoubleSpinBox(settingsWindow);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(190, 430, 62, 22));
        QFont font;
        font.setBold(true);
        doubleSpinBox->setFont(font);
        doubleSpinBox->setMaximum(1.000000000000000);
        doubleSpinBox->setSingleStep(0.050000000000000);
        doubleSpinBox->setValue(1.000000000000000);
        label_4 = new QLabel(settingsWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(380, 160, 131, 38));
        label_4->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 181px;\n"
"height: 41px;\n"
"left: 1089px;\n"
"top: 375px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF;"));
        selectLabel = new QLabel(settingsWindow);
        selectLabel->setObjectName("selectLabel");
        selectLabel->setGeometry(QRect(30, 410, 141, 61));
        QFont font1;
        font1.setPointSize(22);
        selectLabel->setFont(font1);
        radioButton_graph = new QRadioButton(settingsWindow);
        radioButton_graph->setObjectName("radioButton_graph");
        radioButton_graph->setGeometry(QRect(370, 60, 233, 50));
        radioButton_graph->setStyleSheet(QString::fromUtf8("position: absolute;\n"
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
        kgroupSpin = new QSpinBox(settingsWindow);
        kgroupSpin->setObjectName("kgroupSpin");
        kgroupSpin->setGeometry(QRect(450, 370, 121, 41));
        kgroupSpin->setValue(1);
        label_2 = new QLabel(settingsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 370, 81, 31));
        label = new QLabel(settingsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 160, 117, 38));
        label->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 181px;\n"
"height: 41px;\n"
"left: 1089px;\n"
"top: 375px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 32px;\n"
"line-height: 44px;\n"
"letter-spacing: 0.24em;\n"
"\n"
"color: #FFFFFF;"));
        crossValidationCheck = new QCheckBox(settingsWindow);
        crossValidationCheck->setObjectName("crossValidationCheck");
        crossValidationCheck->setGeometry(QRect(50, 360, 161, 51));
        QFont font2;
        font2.setPointSize(20);
        crossValidationCheck->setFont(font2);
        layers_comboBox = new QComboBox(settingsWindow);
        layers_comboBox->setObjectName("layers_comboBox");
        layers_comboBox->setGeometry(QRect(30, 230, 103, 51));
        epochs_comboBox = new QComboBox(settingsWindow);
        epochs_comboBox->setObjectName("epochs_comboBox");
        epochs_comboBox->setGeometry(QRect(390, 240, 103, 32));

        retranslateUi(settingsWindow);

        QMetaObject::connectSlotsByName(settingsWindow);
    } // setupUi

    void retranslateUi(QDialog *settingsWindow)
    {
        settingsWindow->setWindowTitle(QCoreApplication::translate("settingsWindow", "Dialog", nullptr));
        radioButton_matrix->setText(QCoreApplication::translate("settingsWindow", "Matrix", nullptr));
        label_4->setText(QCoreApplication::translate("settingsWindow", "Epochs", nullptr));
        selectLabel->setText(QCoreApplication::translate("settingsWindow", "Selection Part", nullptr));
        radioButton_graph->setText(QCoreApplication::translate("settingsWindow", "Graph", nullptr));
        label_2->setText(QCoreApplication::translate("settingsWindow", "K-Group", nullptr));
        label->setText(QCoreApplication::translate("settingsWindow", "Layers", nullptr));
        crossValidationCheck->setText(QCoreApplication::translate("settingsWindow", "Cross Validation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingsWindow: public Ui_settingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H

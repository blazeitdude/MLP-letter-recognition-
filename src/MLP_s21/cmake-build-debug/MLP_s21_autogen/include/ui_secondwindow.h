/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondWindow
{
public:
    QPushButton *pushButton;
    QSlider *horizontalSlider_epochs;
    QRadioButton *radioButton_matrix;
    QLabel *predictLabel;
    QLabel *label_numEpoc;
    QPushButton *pushButton_learn;
    QSlider *horizontalSlider_layer;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QRadioButton *radioButton_graph;
    QLabel *label_numLay;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *selectLabel;
    QCheckBox *crossValidationCheck;
    QLabel *label_2;
    QSpinBox *kgroupSpin;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_test;

    void setupUi(QWidget *secondWindow)
    {
        if (secondWindow->objectName().isEmpty())
            secondWindow->setObjectName("secondWindow");
        secondWindow->resize(1440, 1024);
        pushButton = new QPushButton(secondWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 870, 283, 62));
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
        horizontalSlider_epochs = new QSlider(secondWindow);
        horizontalSlider_epochs->setObjectName("horizontalSlider_epochs");
        horizontalSlider_epochs->setGeometry(QRect(1010, 220, 251, 25));
        horizontalSlider_epochs->setOrientation(Qt::Horizontal);
        radioButton_matrix = new QRadioButton(secondWindow);
        radioButton_matrix->setObjectName("radioButton_matrix");
        radioButton_matrix->setGeometry(QRect(650, 40, 229, 46));
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
        predictLabel = new QLabel(secondWindow);
        predictLabel->setObjectName("predictLabel");
        predictLabel->setGeometry(QRect(640, 670, 131, 91));
        QFont font;
        font.setPointSize(27);
        predictLabel->setFont(font);
        label_numEpoc = new QLabel(secondWindow);
        label_numEpoc->setObjectName("label_numEpoc");
        label_numEpoc->setGeometry(QRect(1160, 140, 51, 38));
        label_numEpoc->setStyleSheet(QString::fromUtf8("position: absolute;\n"
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
        pushButton_learn = new QPushButton(secondWindow);
        pushButton_learn->setObjectName("pushButton_learn");
        pushButton_learn->setGeometry(QRect(1080, 470, 283, 62));
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
        horizontalSlider_layer = new QSlider(secondWindow);
        horizontalSlider_layer->setObjectName("horizontalSlider_layer");
        horizontalSlider_layer->setGeometry(QRect(650, 220, 151, 25));
        horizontalSlider_layer->setOrientation(Qt::Horizontal);
        pushButton_6 = new QPushButton(secondWindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1080, 720, 283, 62));
        pushButton_6->setStyleSheet(QString::fromUtf8("width: 253px;\n"
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
        pushButton_5 = new QPushButton(secondWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1080, 630, 283, 62));
        pushButton_5->setStyleSheet(QString::fromUtf8("width: 253px;\n"
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
        radioButton_graph = new QRadioButton(secondWindow);
        radioButton_graph->setObjectName("radioButton_graph");
        radioButton_graph->setGeometry(QRect(1000, 40, 233, 50));
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
        label_numLay = new QLabel(secondWindow);
        label_numLay->setObjectName("label_numLay");
        label_numLay->setGeometry(QRect(780, 140, 19, 38));
        label_numLay->setStyleSheet(QString::fromUtf8("position: absolute;\n"
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
        label = new QLabel(secondWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(640, 140, 117, 38));
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
        pushButton_2 = new QPushButton(secondWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 870, 283, 62));
        pushButton_2->setStyleSheet(QString::fromUtf8("width: 253px;\n"
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
        label_4 = new QLabel(secondWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1010, 140, 131, 38));
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
        layoutWidget = new QWidget(secondWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 280, 512, 512));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selectLabel = new QLabel(secondWindow);
        selectLabel->setObjectName("selectLabel");
        selectLabel->setGeometry(QRect(660, 350, 141, 61));
        QFont font1;
        font1.setPointSize(22);
        selectLabel->setFont(font1);
        crossValidationCheck = new QCheckBox(secondWindow);
        crossValidationCheck->setObjectName("crossValidationCheck");
        crossValidationCheck->setGeometry(QRect(680, 300, 141, 51));
        label_2 = new QLabel(secondWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(980, 310, 81, 31));
        kgroupSpin = new QSpinBox(secondWindow);
        kgroupSpin->setObjectName("kgroupSpin");
        kgroupSpin->setGeometry(QRect(1080, 310, 121, 41));
        doubleSpinBox = new QDoubleSpinBox(secondWindow);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(820, 370, 62, 22));
        pushButton_test = new QPushButton(secondWindow);
        pushButton_test->setObjectName("pushButton_test");
        pushButton_test->setGeometry(QRect(1080, 550, 283, 62));
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

        retranslateUi(secondWindow);

        QMetaObject::connectSlotsByName(secondWindow);
    } // setupUi

    void retranslateUi(QWidget *secondWindow)
    {
        secondWindow->setWindowTitle(QCoreApplication::translate("secondWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("secondWindow", "Save Image", nullptr));
        radioButton_matrix->setText(QCoreApplication::translate("secondWindow", "Matrix", nullptr));
        predictLabel->setText(QCoreApplication::translate("secondWindow", "Picture", nullptr));
        label_numEpoc->setText(QCoreApplication::translate("secondWindow", "1", nullptr));
        pushButton_learn->setText(QCoreApplication::translate("secondWindow", "Start Learning", nullptr));
        pushButton_6->setText(QCoreApplication::translate("secondWindow", "Upload Weights", nullptr));
        pushButton_5->setText(QCoreApplication::translate("secondWindow", "Save Weights", nullptr));
        radioButton_graph->setText(QCoreApplication::translate("secondWindow", "Graph", nullptr));
        label_numLay->setText(QCoreApplication::translate("secondWindow", "1", nullptr));
        label->setText(QCoreApplication::translate("secondWindow", "Layers", nullptr));
        pushButton_2->setText(QCoreApplication::translate("secondWindow", "Upload Image", nullptr));
        label_4->setText(QCoreApplication::translate("secondWindow", "Epochs", nullptr));
        selectLabel->setText(QCoreApplication::translate("secondWindow", "Selection Part", nullptr));
        crossValidationCheck->setText(QCoreApplication::translate("secondWindow", "Cross validation", nullptr));
        label_2->setText(QCoreApplication::translate("secondWindow", "K-Group", nullptr));
        pushButton_test->setText(QCoreApplication::translate("secondWindow", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondWindow: public Ui_secondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H

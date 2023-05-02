/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1440, 1024);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Devanagari MT")});
        MainWindow->setFont(font);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("pony-icon-26.jpg")));
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #313131"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 440, 820, 90));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Mountains of Christmas")});
        font1.setBold(false);
        font1.setItalic(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 816px;\n"
"height: 89px;\n"
"left: 284px;\n"
"top: 418px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 64px;\n"
"line-height: 89px;\n"
"/* identical to box height */\n"
"\n"
"letter-spacing: 0.24em;\n"
""));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 590, 250, 65));
        pushButton->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 248px;\n"
"height: 62.35px;\n"
"left: 528px;\n"
"top: 735.65px;\n"
"\n"
"border: 3px solid #FE259B;\n"
"border-radius: 117px;\n"
"\n"
"position: absolute;\n"
"width: 156px;\n"
"height: 68px;\n"
"left: 574px;\n"
"top: 721px;\n"
"\n"
"font-family: 'Mountains of Christmas';\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 64px;\n"
"line-height: 89px;\n"
"text-align: center;\n"
"letter-spacing: 0.09em;\n"
"\n"
"color: #FE259B;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Multilayer Perceptron", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Multilayer Perceptron", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

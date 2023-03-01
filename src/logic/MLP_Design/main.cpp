#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsEffect>
#include <paintscene.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	int idFont = QFontDatabase::addApplicationFont("/Users/ldione/Desktop/MLP_Design/resources/MountainsofChristmas-Regular.ttf");
		QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
		QFont IC(itimCyrillic);
		IC.setPixelSize(16);
		w.setFont(IC);
		w.setFixedSize(1440, 1024);
	w.show();
    return a.exec();
}

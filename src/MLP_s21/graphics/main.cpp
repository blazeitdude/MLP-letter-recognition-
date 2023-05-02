#include <QApplication>
#include <QGraphicsEffect>
#include <QIcon>

#include "headers/mainwindow.h"
#include "headers/paintscene.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::MainWindow w;
  a.setWindowIcon(QIcon(":/pngegg.png"));
  int idFont = QFontDatabase::addApplicationFont(
      "/Users/cmilagro/Desktop/MLP_s21/resources/"
      "MountainsofChristmas-Regular.ttf");
  QString itimCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
  QFont IC(itimCyrillic);
  IC.setPixelSize(16);
  w.setFont(IC);
  w.setFixedSize(1440, 1024);
  w.show();
  return a.exec();
}

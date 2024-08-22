#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("小鱼记事本");
    QIcon icon(":/img/fish.png");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();

}

#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();

    return app.exec();

}

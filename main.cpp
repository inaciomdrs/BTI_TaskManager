#include "mainwindow.h"
#include <unistd.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    app.exec();
}

#include "mainthread.h"
#include "mainwindow.h"



MainThread::MainThread(int argc, char **argv)
{
    A = new QApplication(argc,argv);
}

MainThread::~MainThread()
{
    delete A;
}

void MainThread::run(){
    MainWindow w;
    w.show();
    A->exec();
}


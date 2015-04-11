#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QApplication>
#include <QDebug>

#include "thread.h"

class MainThread : public Thread
{
public:
    MainThread(int argc, char **argv);
    ~MainThread();
    void run();
private:
    QApplication *A;
};

#endif // MAINTHREAD_H

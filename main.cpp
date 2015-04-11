#include "mainthread.h"

int main(int argc, char *argv[])
{
    MainThread *M = new MainThread(argc,argv);
    M->run();
}

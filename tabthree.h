#ifndef TABTHREE_H
#define TABTHREE_H

#include "InfoSO.h"
#include "NameComputer.h"
#include "cpuinfo.h"

#include <vector>

#include <QDebug>

#define DEFAULT_TIMER 1000

class TabThree
{

public:
    TabThree();
    ~TabThree();
    std::string getNC();
    const char* getMemo();
    const char* getModelo();
    const char* getNomeSO();
    //char* getKernel(std::string);
    //void killProcess(std::string);

private:
    std::string computerName;
    const char *memory;
    const char *modelo;
    const char *soName;

    InfoSO *IS;
    NameComputer *NC;
    CpuInfo *C;

};

#endif // TABTHREE_H

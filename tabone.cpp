#include "tabone.h"
#include <QDebug>

TabOne::TabOne(int sleepTime): sleepTime(sleepTime)
{
    PL = new ProcessesList();
}

TabOne::~TabOne()
{
    delete PL;
}

void TabOne::run()
{
    while(true){
        PL->produzirListaProcessos();
        sleep(this->sleepTime);
    }
}

std::vector<process> TabOne::getListaProcessos(){
    return this->PL->getListaProcessos();
}

int TabOne::getNumeroProcessos(){
    return this->PL->numero_processos();
}

int TabOne::getNumeroThreads(){
    return this->PL->numero_threads();
}

void TabOne::setSleepTime(int miliseconds){
    this->sleepTime = miliseconds;
}

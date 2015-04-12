#include "tabone.h"

TabOne::TabOne()
{
    PL = new ProcessesList();
    PL->produzirListaProcessos();
    this->go = false;
}

TabOne::~TabOne()
{
    delete PL;
}

void TabOne::run()
{
    while(true){
        if(go){
            PL->produzirListaProcessos();
            go = false;
            emit updateGUITable();
        }
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

void TabOne::timeToProduce(){
    go = true;
}

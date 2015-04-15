#include "tabone.h"

TabOne::TabOne()
{
    PL = new ProcessesList();
    PL->produzirListaProcessos();

    this->go = false;
    this->timer = startTimer(DEFAULT_TIMER);
}

TabOne::~TabOne()
{
    killTimer(this->timer);
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

void TabOne::timerEvent(QTimerEvent *event){
    go = true;
}

void TabOne::changeTimer(int value){
    killTimer(this->timer);
    this->timer = startTimer(value*100);
}

int TabOne::getPidFrom(std::string processName){
    std::vector<process> LP;
    LP = PL->getListaProcessos();

    for (int var = 0; var < LP.size(); ++var) {
        if(LP[var].nome.compare(processName) == 0){
            return LP[var].pid;
        }
    }

    return -1;
}

void TabOne::killProcess(std::string name){
    kill(getPidFrom(name),SIGKILL);
}

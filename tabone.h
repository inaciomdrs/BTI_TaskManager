#ifndef TABONE_H
#define TABONE_H

#include "thread.h"
#include "processeslist.h"

#include <vector>
#include <unistd.h>

class TabOne : public Thread
{
public:
    TabOne(int sleepTime);
    ~TabOne();
    void run();
    std::vector<process> getListaProcessos();
    int getNumeroProcessos();
    int getNumeroThreads();
    void setSleepTime(int);

private:
    int sleepTime;
    ProcessesList *PL;
};

#endif // TABONE_H

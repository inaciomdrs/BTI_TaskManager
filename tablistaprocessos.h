#ifndef TABLISTAPROCESSOS_H
#define TABLISTAPROCESSOS_H

#include "thread.h"

class TabListaProcessos : public Thread
{
public:
    TabListaProcessos();
    ~TabListaProcessos();
    void run();
};

#endif // TABLISTAPROCESSOS_H

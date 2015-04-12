#ifndef TABONE_H
#define TABONE_H

#include "thread.h"
#include "processeslist.h"

#include <vector>
#include <unistd.h>
#include <QDebug>
#include <QObject>

class TabOne : public QObject, public Thread
{
    Q_OBJECT

public:
    TabOne();
    ~TabOne();
    void run();
    std::vector<process> getListaProcessos();
    int getNumeroProcessos();
    int getNumeroThreads();

private:
    bool go;
    ProcessesList *PL;

public slots:
    void timeToProduce();

signals:
    void updateGUITable();

};

#endif // TABONE_H


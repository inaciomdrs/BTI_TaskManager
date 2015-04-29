#ifndef TABONE_H
#define TABONE_H

#include "thread.h"
#include "processeslist.h"

#include <vector>
#include <unistd.h>
#include <signal.h>

#include <QDebug>
#include <QObject>

#define DEFAULT_TIMER 100

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
    int getPidFrom(std::string);
    void killProcess(std::string);

private:
    bool go;
    int timer;
    ProcessesList *PL;

public slots:
    void timerEvent(QTimerEvent *event);
    void changeTimer(int value);


signals:
    void updateGUITable();

};

#endif // TABONE_H


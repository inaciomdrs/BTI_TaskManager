#ifndef PROCESSESLIST_H
#define PROCESSESLIST_H

#include <qdir.h>
#include <QStandardItem>
#include <QList>
#include <QString>

#include <sys/types.h>
#include <pwd.h>

#include <string>
#include <sstream>
#include <cstring>
#include <QDebug>
#include <fstream>
#include <vector>

typedef struct {
    std::string nome, status, user;
    int pid, ppid, threads, trocas_contexto;
} process;


class ProcessesList
{
public:
    ProcessesList();
    ~ProcessesList();
    void produzirListaProcessos();
    std::vector<process> getListaProcessos();
    int numero_processos();
    int numero_threads();

private:
    std::vector<process> listaProcessos;
    int numThreads;
};

#endif // PROCESSESLIST_H

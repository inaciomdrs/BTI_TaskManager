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
#include <fstream>
#include <vector>

// Fonte desse macro: http://rootdirectory.de/wiki/SSTR()
// Autor: DevSolar (http://stackoverflow.com/users/60281/devsolar)
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#define QSTRING(x) QString::fromStdString(x)

typedef struct {
    std::string nome, status, user;
    int pid, ppid, threads, trocas_contexto;
} process;


class ProcessesList
{
public:
    ProcessesList();
    ~ProcessesList();
    std::vector<process> fillListaProcessos();
    int numero_processos();
    int numero_threads();

private:
    std::vector<process> listaProcessos;
    int numThreads;
    void produzirListaProcessos();
};

#endif // PROCESSESLIST_H

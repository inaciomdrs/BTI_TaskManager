#include "processeslist.h"

ProcessesList::ProcessesList()
{
}

ProcessesList::~ProcessesList()
{
    this->listaProcessos.clear();
}

std::vector<process> ProcessesList::getListaProcessos(){
    return this->listaProcessos;
}

int ProcessesList::numero_processos(){
    return this->listaProcessos.size();
}

int ProcessesList::numero_threads(){
    return this->numThreads;
}

char* getUser(int uid){
    struct passwd *user_info = getpwuid(uid);

    if(!user_info){
        return "none";
    }

    return user_info->pw_name;
}


void ProcessesList::produzirListaProcessos(){
    this->listaProcessos.clear();

    QDir *directory;
    std::ifstream *arquivo;
    QString *S;

    QStringList files;
    std::string data, filename;

    QDir aDir("/proc");

    aDir.setFilter(QDir::Dirs);
    QStringList entries = aDir.entryList();
    this->numThreads = 0;

    for( QStringList::ConstIterator entry=entries.begin(); entry!=entries.end(); ++entry)
    {
        S = new QString("/proc/" + QString(*entry));

        if((S->compare("/proc/.") == 0) || (S->compare("/proc/..") == 0)){
            continue;
        }

        directory = new QDir(*S);

        if(!directory->exists()){
            continue;
        } else if(!((S->toStdString()[6] >= '0') && (S->toStdString()[6] <= '9'))){
            continue;
        }

        directory->setFilter(QDir::Files);

        filename = S->toStdString() + "/status";

        arquivo = new std::ifstream(filename.c_str());

        if(!arquivo){
            continue;
        }

        process P;

        *arquivo >> data; // Lê "Name:"
        *arquivo >> data; // Lê o nome propriamente dito
        P.nome = data;

        *arquivo >> data; // Lê "State:"
        *arquivo >> data; // Lê a sigla
        *arquivo >> data; // Lê o estado propriamente dito

        if(data.size() > 2){
            data.erase(0,1);
            data.erase(data.size()-1);
        }

        P.status = data;

        do {
            *arquivo >> data;
        } while(data.compare("Pid:") != 0);

        *arquivo >> data; // Lê o pid propriamente dito
        P.pid = atoi(data.c_str());

        *arquivo >> data; // Lê "PPid:"
        *arquivo >> data; // Lê o ppid propriamente dito
        P.ppid = atoi(data.c_str());

        //

        do {
            *arquivo >> data;
        } while(data.compare("Uid:") != 0);

        *arquivo >> data; // Lê o uid (id do usuário real) do processo
        int uid = atoi(data.c_str());
        std::string username(getUser(uid));

        P.user = username;

        do {
            *arquivo >> data;
        } while(data.compare("Threads:") != 0);

        *arquivo >> data; // Lê o numero de threads propriamente dito
        P.threads = atoi(data.c_str());
        this->numThreads += P.threads;

        do {
            *arquivo >> data;
        } while(data.compare("voluntary_ctxt_switches:") != 0);

        *arquivo >> data; // Lê a quantidade de trocas de contexto voluntarias propriamente dita
        int trocas_voluntarias = atoi(data.c_str());

        *arquivo >> data; // Lê "nonvoluntary_ctxt_switches:"
        *arquivo >> data; // Lê a quantidade de trocas de contexto não-voluntarias propriamente dita
        int trocas_nao_voluntarias = atoi(data.c_str());

        P.trocas_contexto = trocas_voluntarias + trocas_nao_voluntarias;

        this->listaProcessos.push_back(P);

    }

    arquivo->close();
    delete arquivo;
}

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

std::string processName(QString data){
    QStringList elements = data.split("	");
    return elements.at(1).toStdString();
}

std::string processStatus(QString data){
    QStringList elements = data.split("	");
    QString s = elements.at(1);

    if(s.size() > 2){
        s.remove(0,3);
        if(s.size() > 2){
            s.remove(s.size()-1,1);
        }
    }

    return s.toStdString();
}

std::string processUser(QString data){
    QStringList elements = data.split("	");
    QString s = elements.at(1);

    bool ok;
    int uid = s.toInt(&ok);

    if(ok){
        return getUser(uid);
    } else {
        return "stranger";
    }
}

int processPid(QString data){
    QStringList elements = data.split("	");
    QString s = elements.at(1);

    bool ok;
    int pid = s.toInt(&ok);

    if(ok){
        return pid;
    } else {
        return -1;
    }
}

int processPPid(QString data){
    QStringList elements = data.split("	");
    QString s = elements.at(1);

    bool ok;
    int ppid = s.toInt(&ok);

    if(ok){
        return ppid;
    } else {
        return -1;
    }
}
int processThreadsNumber(QString data){
    QStringList elements = data.split("	");
    QString s = elements.at(1);

    bool ok;
    int threads = s.toInt(&ok);

    if(ok){
        return threads;
    } else {
        return -1;
    }
}
int processTrocasContexto(QString dataA, QString dataB){
    QStringList elementsA = dataA.split("	");
    QString sA = elementsA.at(1);

    QStringList elementsB = dataB.split("	");
    QString sB = elementsB.at(1);


    bool okA, okB;

    int voluntary = sA.toInt(&okA);
    int unvoluntary = sB.toInt(&okB);

    if(okA && okB){
        return voluntary+unvoluntary;
    } else {
        if(okA){
            return voluntary;
        } else if(okB){
            return unvoluntary;
        }
    }

    return -1;
}

void ProcessesList::produzirListaProcessos(){
    this->listaProcessos.clear();

    QDir *directory;
    QFile *arquivo;
    QString *S;

    QStringList files;
    std::string data;

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

        arquivo = new QFile(*S + "/status");

        if((!arquivo)){
            qDebug() << "ERRO 1! (" << *S << ")";
            continue;
        } else if(!arquivo->open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << arquivo->errorString();
            qDebug() << "ERRO 2! (" << *S << ")";
            continue;
        }

        process P;

        QTextStream buffer(arquivo);
        QStringList fileContent = buffer.readAll().split("\n");
        QString buf;

        P.nome = processName(fileContent.at(0));
        P.status = processStatus(fileContent.at(1));

        P.pid = processPid(fileContent.at(3));
        P.ppid = processPPid(fileContent.at(4));

        P.user = processUser(fileContent.at(6));

        for (int var = 7; var < fileContent.size(); ++var) {
            buf = fileContent.at(var);
            if(buf.startsWith("Threads")){
                break;
            }
        }

        P.threads = processThreadsNumber(buf);
        this->numThreads += P.threads;

        P.trocas_contexto = processTrocasContexto(fileContent.at(fileContent.size()-3),fileContent.at(fileContent.size()-2));

        this->listaProcessos.push_back(P);

        arquivo->close();
    }

    delete arquivo;
    delete directory;
    delete S;
}

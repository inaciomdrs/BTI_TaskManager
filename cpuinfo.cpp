#include "cpuinfo.h"

using namespace std;

CpuInfo::CpuInfo()
{
}

CpuInfo::~CpuInfo()
{
}

const char* CpuInfo::getModel()
{
    const char* arg;
    int cont = 1;
    string line, newline;
    ifstream fileModelName ("/proc/cpuinfo"); // ifstream = padrão ios:in
    if (fileModelName)
    {
        while(line.compare("name") != 0){
            fileModelName >> line;
        }
        fileModelName >> line;
        fileModelName >> line;

        do {
            newline += line.c_str();
            newline += " ";
            fileModelName >> line;
        } while(line.compare("stepping") != 0);

        fileModelName.close();
        arg = newline.c_str();
        return arg;
    } else {
            qDebug() << "Unable to open MODEL file\n";
            return "My Model";
    }
}

const char* CpuInfo::getMemoria()
{
    const char* arg;
    int cont = 1;
    string line;
    ifstream fileMemory ("/proc/meminfo"); // ifstream = padrão ios:in
    if (fileMemory)
    {
        while (! fileMemory.eof() ) //enquanto end of file for false continua
        {
            getline (fileMemory,line); // como foi aberto em modo texto(padrão)
            while (cont < 4){
                getline(fileMemory, line);
                //cout << line << endl;
                cont++;
            }
            cont++;
        }
        fileMemory.close();
        //qDebug() << QString::fromStdString(line.c_str());
        arg = line.c_str();

        return arg;
    } else {
            qDebug() << "Unable to open file";
            return "My Memory";
    } 
}

#include "cpuinfo.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <QString>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <QDir>
#include <stdlib.h>
#include <QDebug>
#include <fstream>

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
    string line;
    ifstream myfile ("/proc/cpuinfo"); // ifstream = padrão ios:in
    if (myfile)
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
          getline (myfile,line); // como foi aberto em modo texto(padrão)
            if (cont == 4){
                getline (myfile,line);
            }
          cont++;
        }
        myfile.close();
        arg = line.c_str();
        return arg;
    } else {
            cout << "Unable to open MODEL file\n";
            return "My Model";
    }
}

const char* CpuInfo::getMemoria()
{
    const char* arg;
    int cont = 1;
    string line;
    ifstream myfile2 ("/proc/meminfo"); // ifstream = padrão ios:in
    if (myfile2)
    {
        while (! myfile2.eof() ) //enquanto end of file for false continua
        {
            getline (myfile2,line); // como foi aberto em modo texto(padrão)
            while (cont < 4){
                getline(myfile2, line);
                cout << line << endl;
                cont++;
            }
            cont++;
        }
        myfile2.close();
        arg = line.c_str();
        return arg;
    } else {
            cout << "Unable to open file";
            return "My Memory";
    } 
}

#include "InfoSO.h"

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

InfoSO::InfoSO()
{
}

InfoSO::~InfoSO()
{
}

const char* InfoSO::getSO()
{
    const char* arg;
    string line, buff;
    ifstream fileSO ("/proc/version"); // ifstream = padrão ios:in
    if (fileSO)
    {
        while(fileSO >> buff){
            line += buff;
            line += " ";
        }
        fileSO.close();

        line.erase(31,line.size()-31);
        arg = line.c_str();
    } else {
        qDebug() << "Unable to open SO NAME file\n";
        arg = "Linux";
    }        
    return arg;
}

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
    string line;
    ifstream myfile ("/proc/version"); // ifstream = padrão ios:in
    if (myfile)
    {
      while (! myfile.eof() )
      {
        getline (myfile,line);
      }
      myfile.close();
      arg = line.c_str();
    } else {
        cout << "Unable to open SO NAME file\n";
        arg = "Linux";
    }
    return arg;
}

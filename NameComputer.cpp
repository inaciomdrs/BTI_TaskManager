#include "NameComputer.h"

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

NameComputer::NameComputer(){
}

NameComputer::~NameComputer(){
}

const char* NameComputer::getNameComputer(){
    string line;
    ifstream myfile ("/etc/hostname");
    if (myfile)
    {
      while (! myfile.eof() ) 
      {
        getline (myfile,line); 
      }
      myfile.close();
      this->namecomputer = line.c_str();
      return namecomputer;
    } else {
        cout << "Unable to open COMPUTER NAME file\n";
        return "My PC";
    }
}

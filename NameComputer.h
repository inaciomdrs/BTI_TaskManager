#ifndef NAMECOMPUTER_H
#define NAMECOMPUTER_H

#include <QString>
#include <QDebug>
#include <fstream>

using namespace std;

class NameComputer{
public:
    const char* namecomputer;
  NameComputer();
  ~NameComputer();
  const char* getNameComputer();
};

#endif;

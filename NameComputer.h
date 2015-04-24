#ifndef NAMECOMPUTER_H
#define NAMECOMPUTER_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

using namespace std;

class NameComputer{
public:
    std::string namecomputer;
  NameComputer();
  ~NameComputer();
  std::string getNameComputer();
};

#endif;

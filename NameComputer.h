#ifndef NAMECOMPUTER_H
#define NAMECOMPUTER_H

#include <fstream>
#include <iostream>

using namespace std;

class NameComputer{
public:
    const char* namecomputer;
  NameComputer();
  ~NameComputer();
  const char* getNameComputer();
};

#endif;

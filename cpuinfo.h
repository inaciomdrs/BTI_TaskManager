#ifndef CPUINFO_H
#define CPUINFO_H

#include <fstream>
//#include <iostream>
#include <QString>
#include <QDebug>
 
using namespace std;
 
class CpuInfo{
public:
  CpuInfo();
  ~CpuInfo();
  const char* getModel();
  const char* getMemoria();
};

#endif;

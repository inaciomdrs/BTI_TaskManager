#ifndef CPUINFO_H
#define CPUINFO_H

#include <fstream>
#include <iostream>
 
using namespace std;
 
class CpuInfo{
public:
  CpuInfo();
  ~CpuInfo();
  const char* getModel();
  const char* getMemoria();
};

#endif;

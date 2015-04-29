#ifndef DESEMPENHO_H
#define DESEMPENHO_H


#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;
 
class Desempenho{
public:
	Desempenho();
	~Desempenho();
	string GetStdoutFromCommand(string cmd);
	int getMemTotal();
	int getSwapTotal();
	int getMemUsada();
	int getSwapUsada();
	int getUsoMem();
	int getUsoSwap();
	int getUsoCPU0();
	int getUsoCPU1();
	int getUsoCPU2();
    int getUsoCPU3();
	int calculaPorcentagem(int total, int valor);
    string getTempoOcioso();
	string getTempoUsoCPU();
	string getUptime();

private:
	int memTotal;
	int swapTotal;
	int memUsada;
	int swapUsada;
	int usoMem;
	int usoSwap;
	int usoCPU0;
	int usoCPU1;
	int usoCPU2;
	int usoCPU3;
    string tempoOcioso;
	string tempoUsoCPU;
	string uptime;
};

#endif;

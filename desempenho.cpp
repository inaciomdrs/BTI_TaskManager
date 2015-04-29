#include "desempenho.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
//#include <QString>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
//#include <QDir>
#include <stdlib.h>
#include <QDebug>
#include <fstream>

using namespace std;

Desempenho::Desempenho()
{
}

Desempenho::~Desempenho()
{
}

string Desempenho::GetStdoutFromCommand(string cmd){
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
                pclose(stream);
    }

    return data;
}

int Desempenho::getMemTotal(){
    string cmd = GetStdoutFromCommand("procinfo");
    string saida = cmd.substr(93, 7);
    this->memTotal = atoi(saida.c_str());

    return this->memTotal;
}

int Desempenho::getSwapTotal(){
    string cmd = GetStdoutFromCommand("procinfo");
    string saida = cmd.substr(197, 7);
    this->swapTotal = atoi(saida.c_str());

    return this->swapTotal;
}

int Desempenho::getMemUsada(){
    string cmd = GetStdoutFromCommand("procinfo");
    string saida = cmd.substr(105,7);
    this->memUsada = atoi(saida.c_str());

    return this->memUsada;
}

int Desempenho::getSwapUsada(){
    string cmd = GetStdoutFromCommand("procinfo");
    string saida = cmd.substr(208, 7);
    this->swapUsada = atoi(saida.c_str());

    return this->swapUsada;
}

int Desempenho::getUsoMem()
{
    this->usoMem = this->calculaPorcentagem(this->getMemTotal(), this->getMemUsada());
    
    return this->usoMem;
}

int Desempenho::getUsoSwap()
{
    this->usoSwap = this->calculaPorcentagem(this->getSwapTotal(), this->getSwapUsada());
    
    return this->usoSwap;
}

string Desempenho::getTempoUsoCPU(){
    string cmd = GetStdoutFromCommand("cat /proc/uptime");
    this->tempoUsoCPU = cmd.substr(1, 7);

    return this->tempoUsoCPU;
}

string Desempenho::getTempoOcioso(){
    string cmd = GetStdoutFromCommand("cat /proc/uptime");
    this->tempoOcioso = cmd.substr(8, 10);


    return this->tempoOcioso;
}

string Desempenho::getUptime(){
    string cmd = GetStdoutFromCommand("uptime");
    this->uptime = cmd.substr(13, 5);

    return this->uptime;
}

int Desempenho::getUsoCPU0(){
    string cmd = GetStdoutFromCommand("mpstat -P 0");
    string saida = cmd.substr(191,4);
    this->usoCPU0 = atoi(saida.c_str());
    return this->usoCPU0;
}

int Desempenho::getUsoCPU1(){
    string cmd = GetStdoutFromCommand("mpstat -P 1");
    string saida = cmd.substr(191,5);
    this->usoCPU1 = atoi(saida.c_str());

    return this->usoCPU1;
}

int Desempenho::getUsoCPU2(){
    string cmd = GetStdoutFromCommand("mpstat -P 2");
    string saida = cmd.substr(191,5);
    this->usoCPU2 = atoi(saida.c_str());

    return this->usoCPU2;
}

int Desempenho::getUsoCPU3(){
    string cmd = GetStdoutFromCommand("mpstat -P 3");
    string saida = cmd.substr(191,5);
    this->usoCPU3 = atoi(saida.c_str());

    return this->usoCPU3;
}

int Desempenho::calculaPorcentagem(int total, int valor){
    
    int resultado;
    resultado = ((valor*100)/total);

    return resultado;
}

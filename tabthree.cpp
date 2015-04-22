#include "tabthree.h"

TabThree::TabThree()
{
    IS = new InfoSO();
    NC = new NameComputer();
    C = new CpuInfo();
}

TabThree::~TabThree()
{
    delete IS;
    delete NC;
    delete C;
    delete computerName;
    delete memory;
    delete modelo;
    delete soName;
}

void TabThree::run()
{
    this->soName = IS->getSO();
    this->computerName = NC->getNameComputer();
    this->memory = C->getMemoria();
    this->modelo = C->getModel();
}

const char* TabThree::getNC(){
    return this->computerName;
}

const char* TabThree::getNomeSO(){
    return this->soName;
}

const char* TabThree::getModelo(){
    return this->modelo;
}

const char* TabThree::getMemo(){
    return this->memory;
}


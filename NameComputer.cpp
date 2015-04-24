#include "NameComputer.h"

using namespace std;

NameComputer::NameComputer(){
}

NameComputer::~NameComputer(){
}

std::string NameComputer::getNameComputer(){
    string line, newline;
    QFile filePCName("/etc/hostname");

    if(!filePCName.open(QIODevice::ReadOnly | QIODevice::Text)){
        return "";
    }

    QTextStream buffer(&filePCName);

    QString s = buffer.readLine();

    return s.toStdString();
}

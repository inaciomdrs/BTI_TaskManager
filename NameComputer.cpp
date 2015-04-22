#include "NameComputer.h"

using namespace std;

NameComputer::NameComputer(){
}

NameComputer::~NameComputer(){
}

const char* NameComputer::getNameComputer(){
    string line, newline;
    const char* arg;
    ifstream filePCName ("/etc/hostname");
    if (filePCName)
    {
        while(filePCName >> line){
            newline += line;
            newline += " ";
        }
        filePCName.close();
        arg = newline.c_str();
        qDebug() << QString::fromStdString(arg);
    } else {
        arg = "My PC";
    }
    return arg;
}

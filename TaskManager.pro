#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T22:53:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaskManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp \
    processeslist.cpp \
    tabone.cpp \
    mainthread.cpp

HEADERS  += mainwindow.h \
    thread.h \
    processeslist.h \
    tabone.h \
    mainthread.h

FORMS    += mainwindow.ui

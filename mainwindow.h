#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QSplitter>
#include <QTimer>
#include <QList>
#include <QDebug>

#include "processeslist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_dial_valueChanged(int value);
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSplitter *splitter;
    ProcessesList *PL;
    int timerId;

    void updateProcessesList();

};

#endif // MAINWINDOW_H

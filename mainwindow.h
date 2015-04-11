#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QSplitter>
#include <QTimer>
#include <QList>
#include <QDebug>

#include "tabone.h"

#define SLEEP_TIME_START 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateProcessesList();
    QStandardItemModel* getModel();
    ~MainWindow();

private slots:
    void on_dial_valueChanged(int value);
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSplitter *splitter;
    TabOne *TOne;
    int timerId;
};

#endif // MAINWINDOW_H

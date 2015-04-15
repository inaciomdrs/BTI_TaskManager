#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QSplitter>
#include <QTimer>
#include <QList>
#include <QDebug>

#include "tabone.h"

#define SLEEP_TIME_START 1000
// Fonte desse macro: http://rootdirectory.de/wiki/SSTR()
// Autor: DevSolar (http://stackoverflow.com/users/60281/devsolar)
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#define QSTRING(x) QString::fromStdString(x)

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

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSplitter *splitter;
    TabOne *TOne;
    std::string processName;

signals:
    void timeChanged(int newTime);

private slots:
    void on_dial_valueChanged(int value);
    void updateProcessesTable();

    void on_pushButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H

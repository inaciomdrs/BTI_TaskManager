#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PL = new ProcessesList();

    model = new QStandardItemModel();
    QStringList headers;
    headers << tr("Nome") << tr("Status") << tr("PID") << tr("PPID") << tr("Usuário") << tr("Threads") << tr("Trocas de Contexto");
    model->setHorizontalHeaderLabels(headers);

    PL->fillListaProcessos(model);
    ui->lcdNumber->display(PL->numero_processos());
    ui->lcdNumber_2->display(PL->numero_threads());

    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);

 }

MainWindow::~MainWindow()
{
    delete ui;
    delete PL;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timerId = startTimer(1000);

    PL = new ProcessesList();

    ui->setupUi(this);

    updateProcessesList();

    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);
}

MainWindow::~MainWindow()
{
    killTimer(timerId);
    delete ui;
    delete model;
    delete splitter;
    delete PL;
}

void MainWindow::on_dial_valueChanged(int value)
{
    killTimer(timerId);
    timerId = startTimer(value);
}

void MainWindow::updateProcessesList(){
    model = new QStandardItemModel();
    QStringList headers;
    headers << tr("Nome") << tr("Status") << tr("PID") << tr("PPID") << tr("Usuário") << tr("Threads") << tr("Trocas de Contexto");
    model->setHorizontalHeaderLabels(headers);

    std::vector<process> listaProcessos = PL->fillListaProcessos();

    QList<QStandardItem*>  L;
    int sz = listaProcessos.size();


    for (int item = 0; item < sz; ++item) {
        L.clear();

        L << new QStandardItem(QSTRING(listaProcessos[item].nome));
        L << new QStandardItem(QSTRING(listaProcessos[item].status));
        L << new QStandardItem(QSTRING((SSTR(listaProcessos[item].pid))));
        L << new QStandardItem(QSTRING((SSTR(listaProcessos[item].ppid))));
        L << new QStandardItem(QSTRING((listaProcessos[item].user)));
        L << new QStandardItem(QSTRING((SSTR(listaProcessos[item].threads))));
        L << new QStandardItem(QSTRING((SSTR(listaProcessos[item].trocas_contexto))));

        model->appendRow(L);
    }

    ui->lcdNumber->display(PL->numero_processos());
    ui->lcdNumber_2->display(PL->numero_threads());

}

void MainWindow::timerEvent(QTimerEvent *event){
    updateProcessesList();
    update();
}

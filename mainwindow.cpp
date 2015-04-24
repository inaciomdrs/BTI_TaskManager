#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabthree.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TOne = new TabOne();
    TOne->start();

    T3 = new TabThree();
    T3->start();

    connect(TOne,SIGNAL(updateGUITable()),this,SLOT(updateProcessesTable()));
    connect(this,SIGNAL(timeChanged(int)),TOne,SLOT(changeTimer(int)));

    updateProcessesList();

    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);

    ui->label_7->setText(QSTRING(T3->getNC()));
    ui->label_8->setText(QSTRING(T3->getNomeSO()));
    ui->label_9->setText(QSTRING(T3->getModelo()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete splitter;
    delete TOne;
    delete T3;
}

void MainWindow::updateProcessesList(){
    model = new QStandardItemModel();
    QStringList headers;
    headers << tr("Nome") << tr("Status") << tr("PID") << tr("PPID") << tr("Usuário") << tr("Threads") << tr("Trocas de Contexto");
    model->setHorizontalHeaderLabels(headers);

    std::vector<process> listaProcessos = TOne->getListaProcessos();

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

    ui->lcdNumber->display(TOne->getNumeroProcessos());
    ui->lcdNumber_2->display(TOne->getNumeroThreads());

}

void MainWindow::on_dial_valueChanged(int value)
{
    emit timeChanged(value);
}

QStandardItemModel* MainWindow::getModel(){
    return this->model;
}

void MainWindow::updateProcessesTable(){
    updateProcessesList();
    repaint();
}

void MainWindow::on_pushButton_clicked()
{
    TOne->killProcess(this->processName);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    this->processName = index.data().toString().toStdString();
}

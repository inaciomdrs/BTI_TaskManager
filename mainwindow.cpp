#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabthree.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Desempenho();

    TOne = new TabOne();
    TOne->start();

    T3 = new TabThree();

    connect(TOne,SIGNAL(updateGUITable()),this,SLOT(updateProcessesTable()));
    connect(this,SIGNAL(timeChanged(int)),TOne,SLOT(changeTimer(int)));

    ui->label_7->setText(QSTRING(T3->getNC()));
    ui->label_8->setText(QSTRING(T3->getNomeSO()));
    ui->label_9->setText(QSTRING(T3->getModelo()));

    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);

    ui->grafico1->addGraph();
    ui->grafico1->addGraph();
    ui->grafico1->addGraph();
    ui->grafico1->addGraph();

    ui->grafico1->graph(0)->setPen(QPen(Qt::red));
    ui->grafico1->graph(1)->setPen(QPen(Qt::green));
    ui->grafico1->graph(2)->setPen(QPen(Qt::yellow));
    ui->grafico1->graph(3)->setPen(QPen(Qt::blue));

    ui->grafico1->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->grafico1->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->grafico1->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->grafico1->graph(3)->setLineStyle(QCPGraph::lsLine);

    ui->grafico2->addGraph();
    ui->grafico2->addGraph();

    ui->grafico2->graph(0)->setPen(QPen(Qt::red));
    ui->grafico2->graph(1)->setPen(QPen(Qt::green));

    ui->grafico2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->grafico2->graph(1)->setLineStyle(QCPGraph::lsLine);

    ui->grafico1->xAxis->setLabel("Segundos");
    ui->grafico1->yAxis->setLabel("CPU's");

    ui->grafico1->xAxis->setRange(0, 100);
    ui->grafico1->yAxis->setRange(0, 100);

    ui->grafico1->axisRect()->setupFullAxesBox();

    ui->grafico2->xAxis->setLabel("Segundos");
    ui->grafico2->yAxis->setLabel("Memoria e SWAP");

    ui->grafico2->xAxis->setRange(0, 100);
    ui->grafico2->yAxis->setRange(0, 100);

    ui->grafico2->axisRect()->setupFullAxesBox();

    updateProcessesList();
    updateResourceUseGraphics();

}

MainWindow::~MainWindow()
{

    if(ui){
        delete ui;
    }

    if(model){
        delete model;
    }

    if(splitter){
        delete splitter;
    }

    if(TOne){
        delete TOne;
    }

    if(T3){
        delete T3;
    }

    if(d){
        delete d;
    }


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

    ui->tableView->setModel(model);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);

}

void MainWindow::updateResourceUseGraphics(){
    ui->pb_cpu0_2->setValue(d->getUsoCPU0());
    ui->pb_cpu1_2->setValue(d->getUsoCPU1());

    ui->pb_memoria->setValue(d->getUsoMem());
    ui->pb_swap->setValue(d->getUsoSwap());

    ui->lineEdit->setText(QString::fromStdString(d->getTempoUsoCPU()));
    ui->lineEdit_2->setText(QString::fromStdString(d->getTempoOcioso()));
    ui->lineEdit_3->setText(QString::fromStdString(d->getUptime()));

    QVector<double> vectorUsoCPU0(100), vectorUsoCPU1(100), vectorUsoCPU2(100), vectorUsoCPU3(100), segundos(100);
    QVector<double> vectorUsoMem(100), vectorUsoSWAP(100);

    for(int i = 0 ; i < 100 ; i++){
        vectorUsoCPU0[i] = d->getUsoCPU0();
        vectorUsoCPU1[i] = d->getUsoCPU1();
        //vectorUsoCPU2[i] = d.getUsoCPU2();
        //vectorUsoCPU3[i] = d.getUsoCPU3();
        //qDebug() << "CHEGAMO AQUI!";
        vectorUsoMem[i] = d->getUsoMem();
        vectorUsoSWAP[i] = d->getUsoSwap();
        segundos[i] = i;

        ui->grafico1->graph(0)->setData(segundos, vectorUsoCPU0);
        ui->grafico1->graph(1)->setData(segundos, vectorUsoCPU1);
        ui->grafico1->graph(2)->setData(segundos, vectorUsoCPU2);
        ui->grafico1->graph(3)->setData(segundos, vectorUsoCPU3);

        ui->grafico2->graph(0)->setData(segundos, vectorUsoMem);
        ui->grafico2->graph(1)->setData(segundos, vectorUsoSWAP);

        ui->grafico1->replot();
    }
    for(int i = 0 ; i <= 100 ; i++){
        ui->dial->setValue(i);
        i+10;
        sleep(0.01);
    }
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
    updateResourceUseGraphics();
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

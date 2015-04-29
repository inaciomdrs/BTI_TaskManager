/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_2;
    QCustomPlot *grafico1;
    QCustomPlot *grafico2;
    QGroupBox *groupBox;
    QProgressBar *pb_cpu0_2;
    QGroupBox *groupBox_2;
    QProgressBar *pb_cpu1_2;
    QGroupBox *groupBox_4;
    QProgressBar *pb_swap;
    QGroupBox *groupBox_3;
    QProgressBar *pb_memoria;
    QGroupBox *groupBox_5;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QWidget *tab_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDial *dial;
    QLabel *label_2;
    QLabel *label_10;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1055, 654);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 1031, 481));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 10, 1001, 431));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        grafico1 = new QCustomPlot(tab_2);
        grafico1->setObjectName(QStringLiteral("grafico1"));
        grafico1->setGeometry(QRect(70, 10, 941, 121));
        grafico2 = new QCustomPlot(tab_2);
        grafico2->setObjectName(QStringLiteral("grafico2"));
        grafico2->setGeometry(QRect(70, 150, 941, 121));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(70, 280, 141, 61));
        pb_cpu0_2 = new QProgressBar(groupBox);
        pb_cpu0_2->setObjectName(QStringLiteral("pb_cpu0_2"));
        pb_cpu0_2->setGeometry(QRect(20, 20, 118, 23));
        pb_cpu0_2->setValue(24);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 280, 141, 51));
        pb_cpu1_2 = new QProgressBar(groupBox_2);
        pb_cpu1_2->setObjectName(QStringLiteral("pb_cpu1_2"));
        pb_cpu1_2->setGeometry(QRect(10, 20, 118, 23));
        pb_cpu1_2->setValue(24);
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(70, 330, 151, 61));
        pb_swap = new QProgressBar(groupBox_4);
        pb_swap->setObjectName(QStringLiteral("pb_swap"));
        pb_swap->setGeometry(QRect(20, 20, 118, 23));
        pb_swap->setValue(24);
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(230, 330, 131, 51));
        pb_memoria = new QProgressBar(groupBox_3);
        pb_memoria->setObjectName(QStringLiteral("pb_memoria"));
        pb_memoria->setGeometry(QRect(0, 20, 118, 23));
        pb_memoria->setValue(24);
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(540, 270, 171, 171));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 171, 16));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 113, 20));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 111, 16));
        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 90, 113, 20));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 141, 16));
        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 140, 113, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(8, 60, 121, 51));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 60, 171, 16));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 80, 651, 16));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 100, 631, 16));
        tabWidget->addTab(tab_3, QString());
        label_6->raise();
        label_7->raise();
        label_9->raise();
        label_8->raise();
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(990, -10, 50, 64));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(900, 10, 91, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 560, 151, 16));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 530, 64, 23));
        lcdNumber->setProperty("intValue", QVariant(2));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(10, 560, 64, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 530, 151, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 530, 151, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1055, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Lista de Processos", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "CPU 1", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "CPU 2", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Swap", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Mem\303\263ria", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "CPU Info", 0));
        label_3->setText(QApplication::translate("MainWindow", "Tempo de Uso de CPU", 0));
        label_4->setText(QApplication::translate("MainWindow", "Tempo Ocioso", 0));
        label_5->setText(QApplication::translate("MainWindow", "Uptime", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Desempenho", 0));
        label_6->setText(QApplication::translate("MainWindow", "Icone do Sistema", 0));
        label_7->setText(QApplication::translate("MainWindow", "Nome do Computador", 0));
        label_8->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es do SO (nome, kernel)", 0));
        label_9->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es de Hardware (CPU, mem\303\263ria principal, mem\303\263ria secund\303\241ria dispon\303\255vel)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Sistema", 0));
        label_2->setText(QApplication::translate("MainWindow", "Atualiza\303\247\303\243o", 0));
        label_10->setText(QApplication::translate("MainWindow", "N\303\272mero de threads", 0));
        label->setText(QApplication::translate("MainWindow", "N\303\272mero de processos", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Finalizar Processo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

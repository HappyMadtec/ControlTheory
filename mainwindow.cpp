#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();

}

void MainWindow::on_quitButton_4_clicked()
{
    QApplication::quit();

}


void MainWindow::on_transferFunctionButton_4_clicked()
{
    if(! transferFunctionTab)
    {
        transferFunctionTab = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(transferFunctionTab);
        QLabel *label = new QLabel("Transfer Function");
        layout->addWidget(label);
        transferFunctionTab->setLayout(layout);
        ui->tabWidget->addTab(transferFunctionTab, "Transfer Function");

    }
    ui->tabWidget->setCurrentWidget(transferFunctionTab);
}


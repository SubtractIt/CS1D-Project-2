#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_adminLogin_clicked()
{
    Login* adminLogin = new Login;
    adminLogin -> setWindowTitle("Administrative Login");
    adminLogin -> show();
}

void MainWindow::on_pushButton_clicked()
{
    Trip* tripPlanning = new Trip;
    tripPlanning->setWindowTitle("Trip Planning");
    tripPlanning->show();
    qInfo() << "test trip";
}


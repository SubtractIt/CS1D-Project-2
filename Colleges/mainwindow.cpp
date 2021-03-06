#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setColor(QColor(Qt::black));
    shadow->setOffset(2,2);
    shadow->setBlurRadius(10);

    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect(this);
    shadow2->setColor(QColor(Qt::black));
    shadow2->setOffset(2,2);
    shadow2->setBlurRadius(10);

    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect(this);
    shadow3->setColor(QColor(Qt::black));
    shadow3->setOffset(2,2);
    shadow3->setBlurRadius(10);

    ui->find->setGraphicsEffect(shadow);
    ui->your->setGraphicsEffect(shadow2);
    ui->future->setGraphicsEffect(shadow3);

    QMovie* movie = new QMovie("confetti.gif");
    //QLabelprocessLabel = new QLabel(this);
    ui->confetti->setMovie(movie);
    movie->start();
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


void MainWindow::on_display_clicked()
{
    Display display;
    display.setModal(true);
    display.exec();
}


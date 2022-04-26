#include "trippopup.h"
#include "ui_trippopup.h"
#include "collegehashmap.h"

#include <QDebug>

trippopup::trippopup(std::vector<Purchaser*> purchasers, double totalDistance, double totalSpent, CollegeHashMap colleges, std::queue<College> route, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trippopup)
{
    ui->setupUi(this);

    this->ui->totalDistanceLabel->setText("Total distance: " + QString::number(totalDistance) + " mi.");
    this->ui->totalSpentLabel->setText("Total spent: $" + QString::number(totalSpent));

    qInfo() << purchasers.size();
    for (int i = 0; i < purchasers.size(); i++){
        QString collegeName = colleges.find(purchasers[i]->getCollegeID()).getName();
        this->ui->spentList->addItem(collegeName + " : $" + QString::number(purchasers[i]->getTotalSpent()));
    }

    while (!route.empty()){
        this->ui->routeList->addItem(route.front().getName());
        route.pop();
    }
}

trippopup::~trippopup()
{
    delete ui;
}

#include "trip.h"
#include "ui_trip.h"

Trip::Trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trip)
{
    ui->setupUi(this);
}

Trip::~Trip()
{
    delete ui;
}

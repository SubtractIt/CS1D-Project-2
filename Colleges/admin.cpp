#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    QString path;

    #if __APPLE__ && TARGET_OS_MAC
          path = "../../../../Colleges/colleges.db";
    #elif __linux__
          path = "../Colleges/colleges.db";
    #else
          path = "..\Colleges\colleges.db";
    #endif

    db = new DbManager(path);

    setCollegeEditOptions();

    if(db->getAllColleges().size() != 0) {
        QString selected = ui->collegeEdit->currentText();
        int id = selected.section(' ',0,0).toInt();
        setSouvEditFields(id);
    }

}

Admin::~Admin()
{
    delete db;
    delete ui;
}

void Admin::setCollegeEditOptions() {
   currentColleges = db->getAllColleges();
   currentIds = db->getAllIds();

   ui->collegeEdit->clear();

   QString name;
   int id;
   QString collegeInfo;
   College current;

<<<<<<< HEAD
   for(int i : currentIds) {
    qDebug() << "test";
       current = currentColleges.find(i)->college;
        qDebug() << current.getID();
       qDebug() << "here";
=======
   std::vector<int> ids;
   for (int id : currentIds) ids.push_back(id);


    for (int i : ids) {
       current = currentColleges.find(i);
>>>>>>> 09b70419fa151580b534b4f0a413f43bd93bb7a2
       name = current.getName();
       id = current.getID();
<<<<<<< HEAD
       qDebug() << id;
       qDebug() << "here4";
       collegeInfo = QString::number(id) + " - " + name;
       qDebug() << collegeInfo;
       qDebug() << "here5";
=======
       collegeInfo = QString::number(id) + " - " + name;
>>>>>>> 09b70419fa151580b534b4f0a413f43bd93bb7a2
       ui->collegeEdit->addItem(collegeInfo);
   }
}

void Admin::setSouvEditFields(int id) {
    currentColleges = db->getAllColleges();
    currentIds = db->getAllIds();

    College current;

    for(int i : currentIds) {
        if(id == currentColleges.find(i).getID()) {
            current = currentColleges.find(i);
        }
    }

    std::vector<Souvenir> currentSouvs = current.getSouvenirs();

    ui->deleteOptions->clear();

    // May need if for never being 0 here

    ui->souvTable->setRowCount(currentSouvs.size());
    QStringList tableRows;
    QDoubleSpinBox* souvPrice;
    QString deleteSouvNames;

    for(size_t i = 0; i < currentSouvs.size(); ++i) {
        souvPrice = new QDoubleSpinBox(ui->souvTable);
        souvPrice->setValue(currentSouvs[i].price);
        ui->souvTable->setCellWidget(i,0,souvPrice);

        tableRows << currentSouvs[i].name;

        deleteSouvNames = QString::number(i+1) + " - " + currentSouvs[i].name + " $" + QString::number(currentSouvs[i].price);
        ui->deleteOptions->addItem(deleteSouvNames);
    }

    ui->souvTable->setVerticalHeaderLabels(tableRows);
}

void Admin::on_collegeEdit_currentIndexChanged(const QString &arg1)
{
    QString selected = ui->collegeEdit->currentText();
    int id = selected.section(' ',0,0).toInt();
    setSouvEditFields(id);

    ui->addName->clear();
    ui->addPrice->clear();
}

void Admin::on_addSouv_clicked()
{

}

void Admin::on_deleteSouv_clicked()
{

}

void Admin::on_modifySouv_clicked()
{

}

#include "trip.h"
#include "ui_trip.h"

#include <QSpinBox>
#include <QPushButton>

Trip::Trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trip)
{
    ui->setupUi(this);
    qInfo() << "ran1";

    QString path;

 // Creating database connection
    #if __APPLE__ && TARGET_OS_MAC
          path = "../../../../Colleges/colleges.db";
    #elif __linux__
          path = "../Colleges/colleges.db";
    #else
          path = "..\Colleges\colleges.db";
    #endif

    db = new DbManager(path);

    this->currentColleges = db->getAllColleges();
    this->currentIDs = db->getAllIds();

    if (currentColleges.size() > 0){
        this->populateTable(currentIDs[0]);
    }

    qInfo() << "ran";

    //populate combobox now

}

void Trip::populateTable(int id){
    QTableWidget* table = this->ui->buyingTable;

    College current; // Object for corresponding id, yet to be set

    // Loop through colleges to find the corresponding college
    // for the passed in id
    for(int i : currentIDs) {
        if(id == currentColleges.find(i).getID()) {
            current = currentColleges.find(i);
            break;
        }
    }

    // Now that college is found, get the souvenirs to load the buying table
    std::vector<Souvenir> currentSouvs = current.getSouvenirs();

    table->setRowCount(currentSouvs.size());

    // Helper variables to set table and dropdown menu
    QStringList     tableRows;       // Row headers ro hold souv name
    QSpinBox* purchaseCount;       // Spinbox to set number of items to buy
    QPushButton* buyButton; // Button to add item to trip

    // Loop through every souvenir and set row label and price
    // adjuster for table and # - name $## for the delete options
    for(int i = 0; i < currentSouvs.size(); ++i) {
        // Create new spin box and assign to according cell in table
        purchaseCount = new QSpinBox(table);
        purchaseCount->setMaximum(100);
        purchaseCount->setValue(0);
        table->setCellWidget(i,0,purchaseCount);;

        buyButton = new QPushButton(table);
        buyButton->setText("Add Item(s)");
        table->setCellWidget(i, 1, buyButton);

        //Connect add item button to slot
        connect(buyButton, SIGNAL(clicked()), this, SLOT(onAddItemClicked()));

        // Add souvenir name to row labels
        tableRows << currentSouvs[i].name + " - $" + QString::number(currentSouvs[i].price);

        // Create delete option message with # - name $##
        // and add to the delete dropdown options


    }

    // Take the row labels and set the table to them
    table->setVerticalHeaderLabels(tableRows);
}

void Trip::onAddItemClicked(){
    qInfo() << "clicked";

    QWidget *w = qobject_cast<QWidget *>(sender()->parent());
        if(w){
            int row = ui->buyingTable->indexAt(w->pos()).row();
            qInfo() << "row: " << row;
        }

}

Trip::~Trip()
{
    delete ui;
    delete db;
}

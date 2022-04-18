#include "trip.h"
#include "ui_trip.h"

#include <QSpinBox>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>

Trip::Trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trip)
{
    ui->setupUi(this);
    qInfo() << "ran1";

    this->buying = false;

    QString path;

 // Creating database connection
    #if __APPLE__ && TARGET_OS_MAC
          path = "../../../../Colleges/colleges.db";
    #elif __linux__
          path = "../Colleges/colleges.db";
    #else
          path = "D:/Qt/PROJECT 2 CS1D/CS1D-Project-2/Colleges/colleges.db";
    #endif

    db = new DbManager(path);

    this->currentColleges = db->getAllColleges();
    this->currentIDs = db->getAllIds();

    //populate colleges table

    QStringList     tableRows;       // Row headers ro hold souv name
    QPushButton* buyButton; // Button to add item to trip

    QTableWidget* table = this->ui->collegesTable;

    table->setRowCount(currentIDs.size());
    for (int i = 0; i < currentIDs.size(); i++){
        College current = this->currentColleges.find(i + 1);

        buyButton = new QPushButton(table);
        buyButton->setText("Add College To Trip");
        buyButton->setMinimumWidth(200);
        //Store row of button in object name
        buyButton->setObjectName(QString::number(i));
        table->setCellWidget(i, 0, buyButton);

        //Connect add item button to slot
        connect(buyButton, SIGNAL(clicked()), this, SLOT(onAddCollegeClicked()));

        // Add souvenir name to row labels
        tableRows << QString::number(current.getID()) + " - " + current.getName();

    }

    table->setVerticalHeaderLabels(tableRows);

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

    this->ui->purchaserCollegeLabel->setText("Current College: " + current.getName());

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
        //Store row of button in object name
        buyButton->setObjectName(QString::number(i));
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

    QPushButton *pb = qobject_cast<QPushButton *>(QObject::sender());
    int row = pb->objectName().toInt();
    Souvenir selected = this->route.front().getSouvenirs()[row];


    qInfo() << "Clicked item: " << selected.name;

    Purchaser* currentPurchaser = this->purchasers.back();

    currentPurchaser->purchaseItem(row);

}

Trip::~Trip()
{
    delete ui;
    delete db;

}

void Trip::onAddCollegeClicked(){
    if (planning){
        QPushButton *pb = qobject_cast<QPushButton *>(QObject::sender());
        int row = pb->objectName().toInt();
        College selected = this->currentColleges.find(row + 1);

        qInfo() << "College name added: " << selected.getName();

        //type of college trip being done
        /*
         * 1 - Custom trip (choose initial)
         * 2 - Custom trip (specific order)
         * 3 - From Saddleback
         * 4 - From Michigan
         * 5 - BFS
         * 6 - DFS
         */

        switch(this->mode){
        case 1:
            break;
        case 2:
            this->route.push(selected);
            this->selectedColleges.insert(selected.getID(), selected);
            this->selectedIDs.push_back(selected.getID());
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;

        }

        ui->collegesList->addItem(QString::number(selected.getID()) + " - " + selected.getName());
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add colleges before choosing type of trip.");
    }

    this->selectedIDs.push_back(selected.getID());
}

void Trip::on_chooseStartTrip_clicked() {
    this->mode = 1;
    this->planning = 1;

    QStringList listOfColleges;

    College current;
    for (int i : this->currentIDs){
        current = this->currentColleges.find(i);
        listOfColleges.push_back(QString::number(current.getID()) + " - " + current.getName());
    }

    bool ok;
    QString item = QInputDialog::getItem(this, "Initial College Location",
                                             tr("Choose a starting college:"), listOfColleges, 0, false, &ok);
        if (ok && !item.isEmpty()){
            int id = item.section(' ', 0, 0).toInt();

            //Add starting college to route as first item + add id to currentIDs
            College initial = this->currentColleges.find(id);
            this->currentIDs.push_back(id);
            this->route.push(initial);
            qInfo() << "Top of route: " << this->route.front().getName();
        }

}

void Trip::on_specificOrderTrip_clicked()
{
    this->mode = 2;
    this->planning = true;
}


void Trip::on_fromSaddlebackTrip_clicked()
{
    this->mode = 3;
    this->buying = true;
    College saddleback = this->currentColleges.find(5);

    //We're starting from saddleback, so push Saddleback to be the first entry in our route queue
    this->route.push(saddleback);
    this->selectedIDs.push_back(5);

    //Add every college but Saddleback to selected colleges
    for (int i = 1; i <= this->currentIDs.size(); i++){
        if (i == 5){
            //Ignore, we already added Saddleback
        } else {
            this->selectedColleges.insert(i, currentColleges.find(i));
            this->selectedIDs.push_back(i);
        }

    }

    //Use Dijkstras here i think

    this->buyNext();
}


void Trip::on_michiganTrip_clicked()
{
    College michigan = this->currentColleges.find(6);

    this->route.push(michigan);
    this->selectedIDs.push_back(6);

    this->mode = 4;
}

void Trip::on_executeTrip_clicked() {
    int numColleges = this->selectedColleges.size();

    if (planning){
        this->buying = true;

        switch(this->mode){
        case 1:
            break;
        case 2:
            //Use Dijkstra's now
            this->buyNext();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot execute trip before planning.");
    }

}

void Trip::buyNext(){
    qInfo() << buying;
    if (!this->route.empty() && buying == true){
        int id = this->route.front().getID();
        College current = this->route.front();
        this->populateTable(id);

        Purchaser *purchaser = new Purchaser(current.getSouvenirs(), current.getID());

        this->purchasers.push_back(purchaser);
    } else if (buying == true) {
        //were done buying now
        College current;
        for (std::vector<Purchaser*>::iterator itr = this->purchasers.begin(); itr != this->purchasers.end(); itr++){
            current = this->currentColleges.find((*itr)->getCollegeID());
            qInfo() << "Total spent at " << current.getName() << ": " << (*itr)->getTotalSpent();
        }

        this->buying = false;
        this->planning = false;


        //Clear trip stuff here, maybe a function?
        this->purchasers.clear();
        for (int i : selectedIDs){
            //this->selectedColleges.erase(i);
        }
        this->selectedIDs.clear();


    }
}

void Trip::on_nextCollegeButton_clicked()
{
    if (!this->route.empty())
        this->route.pop();
    this->buyNext();
}


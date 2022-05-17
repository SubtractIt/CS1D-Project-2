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


    this->totalDistance = 0;
    this->buying = false;

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

    totalSpent = 0;

}

void Trip::populateTable(int id){
    QTableWidget* table = this->ui->buyingTable;

    College current = currentColleges.find(id); // Object for corresponding id, yet to be set

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
    int count = static_cast<QSpinBox*>(ui->buyingTable->cellWidget(row,0))->value();
    qInfo() << "count: " << QString::number(count);
    Purchaser* currentPurchaser = this->purchasers.back();

    for (int i = 0; i < count; i++){
        currentPurchaser->purchaseItem(row);
    }

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
         */

        switch(this->mode){
        case 1:
            this->selectedColleges.insert(selected.getID(), selected);
            this->selectedIDs.push_back(selected.getID());

            qInfo() << "were adding id " << selected.getID();
            break;
        case 2:
        {
            qInfo() << "case 2";
            if (!route.empty()){
                int previousID = route.back().getID();
                College previous = currentColleges.find(previousID);

                this->route.push(selected);
                this->selectedColleges.insert(selected.getID(), selected);
                this->selectedIDs.push_back(selected.getID());

                WeightedGraph graph;
                std::unordered_map<int, std::vector<int>> routes;
                std::unordered_map<int, float> costs;
                graph.addColleges(selectedColleges, selectedIDs);


                graph.dijkstra(previous.getID(), routes, costs);

                qInfo() << "called dijkstra's going from " << previous.getName();

                totalDistance += costs[selected.getID()];

                qInfo() << "cost from " << previous.getName() << "to " << selected.getName() << " is: " << costs[selected.getID()];
            } else {
                this->route.push(selected);
                this->selectedColleges.insert(selected.getID(), selected);
                this->selectedIDs.push_back(selected.getID());
            }

            break;
        }
        case 3:
            this->selectedColleges.insert(selected.getID(), selected);
            this->selectedIDs.push_back(selected.getID());
            break;
        case 4:
            this->selectedColleges.insert(selected.getID(), selected);
            this->selectedIDs.push_back(selected.getID());
            break;

        }

        ui->collegesList->addItem(QString::number(selected.getID()) + " - " + selected.getName());
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add colleges before choosing type of trip.");
    }

    //this->selectedIDs.push_back(selected.getID());
}

void Trip::on_chooseStartTrip_clicked() {
    this->mode = 1;
    this->planning = 1;
    this->selectedIDs.clear();

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
            //this->selectedIDs.push_back(id);
            this->route.push(initial);
            qInfo() << "Top of route: " << this->route.front().getName();

            ui->collegesList->addItem(QString::number(initial.getID()) + " - " + initial.getName());
            this->selectedColleges.insert(id, initial);

        }

}

void Trip::on_specificOrderTrip_clicked()
{
    this->mode = 2;
    this->planning = true;

    QMessageBox popup;
    popup.information(0, "Trip Planner", "Custom specific order trip started! Choose colleges and visit them in the order you choose, then execute trip.");
}


void Trip::on_fromSaddlebackTrip_clicked()
{
    this->mode = 3;
    this->planning = true;
    this->buying = true;
    College saddleback = this->currentColleges.find(5);


    //We're starting from saddleback, so push Saddleback to be the first entry in our route queue
    this->route.push(saddleback);
    this->selectedIDs.push_back(5);

    //Add every college but Saddleback to selected colleges
    //This populates selectIDs and selectedColleges with every college
    for (int i = 1; i <= this->currentIDs.size(); i++){
        if (i == 5){
            //Ignore, we already added Saddleback
        } else {
            this->selectedColleges.insert(i, currentColleges.find(i));
            this->selectedIDs.push_back(i);
        }

    }


    //Use Dijkstras here i think
    WeightedGraph graph;
    graph.addColleges(selectedColleges, selectedIDs);
    //graph.dijkstras();


    //push from whatever dijkstra's returns to the route queue now

    this->buyNext();
    this->ui->executeTrip->click(); //this is the problem child line


}


void Trip::on_michiganTrip_clicked()
{
    College michigan = this->currentColleges.find(6);

    this->route.push(michigan);
    this->selectedIDs.push_back(6);

    ui->collegesList->addItem(QString::number(michigan.getID()) + " - " + michigan.getName());

    this->mode = 4;
    this->planning = true;

    QMessageBox popup;
    popup.information(0, "Trip Planner", "Trip from Michigan started! Choose additional colleges to add, then execute trip.");

}

//type of college trip being done
/*
 * 1 - Custom trip (choose initial)
 * 2 - Custom trip (specific order)
 * 3 - From Saddleback
 * 4 - From Michigan
 */

void Trip::on_executeTrip_clicked() {

    int numColleges = this->selectedColleges.size();

    if (planning){
        this->buying = true;
        switch(this->mode){
        case 1:
        {

            qInfo() << currentColleges.size();
            qInfo() << "all ids" << currentIDs.size();
            //initial restaurant is already at the top of the route at this point
            qInfo() << "initial pick";

            College texas = currentColleges.find(13);
            std::unordered_map<int, float> distances = texas.getDistances();
            for (const auto itr : distances){
                qInfo() << itr.first << " - " << itr.second;
            }

            qInfo() << "selected ids size: " << selectedIDs.size();
            for (int i : selectedIDs){
                qInfo() << "a selected id: " << i;
            }

            WeightedGraph graph;
            graph.addColleges(this->currentColleges, this->currentIDs);
            int v = 5;
            std::unordered_map<int, std::vector<int>> routes;
            std::unordered_map<int, float> costs;

            int currentID = this->route.front().getID();
            int selectedID = 0;
            College currentCollege = this->currentColleges.find(currentID);
            double shortestDistance = 1000000.0;

            //Call Dijkstra's
            graph.dijkstra(currentID, routes, costs);

            std::vector<int> visited;
            visited.push_back(currentID);
            this->selectedIDs.push_back(currentID);

            qInfo() << "first id : " << currentID;
            qInfo() << "size: " << selectedColleges.size();
            while (selectedColleges.size() != 1){
                qInfo() << "Current college: " << currentCollege.getName();
                qInfo() << "selected colleges size: " << selectedColleges.size();
                shortestDistance = 10000000.0;
                std::vector<int>::iterator found;
                for (std::vector<int>::iterator itr = selectedIDs.begin(); itr != selectedIDs.end(); itr++){
                    if (costs[*itr] < shortestDistance && *itr != currentID && std::find(visited.begin(), visited.end(), *itr) == visited.end()){
                        qInfo() << "found: " << *itr;
                        shortestDistance = costs[*itr];
                        qInfo() << "shortest distance: " << costs[*itr];
                        selectedID = *itr;
                        found = itr;
                    }
                }
                College selected = selectedColleges.find(selectedID);
                this->route.push(selected);
                selectedIDs.erase(found);
                qInfo() << "Shortest distance: " << QString::number(shortestDistance);

                //Find the distance now between currentCollege and selectedCollege using Dijkstra's now
                graph.dijkstra(currentID, routes, costs);
                totalDistance += costs[selectedID];
                qInfo() << "cost: " << QString::number(costs[selectedID]);
                qInfo() << "route for cost: ";
                std::vector<int> route = routes[selectedID];
                for (int j : route){
                    qInfo() << currentColleges.find(j).getName();
                }

                graph.dijkstra(selectedID, routes, costs);
                visited.push_back(selectedID);
                selectedColleges.erase(currentID);
                currentID = selectedID;
                currentCollege = selected;
            }

            //There should be only one college left now
            qInfo() << "COLLEGES LEFT: " << selectedColleges.size();
            qInfo() << "SELECTED IDS SIZE: " << selectedIDs.size();


            //College last = selectedColleges.find(selectedIDs[0]);

            this->buyNext();
        }

            break;
        case 2:
            //Use Dijkstra's now
            this->buyNext();
            break;
        case 3:
        {
            //Saddleback is already at the top of the route at this point
            WeightedGraph graph;
            qInfo() << "selected colleges size: " << selectedColleges.size();

            //test
            College saddlebackobj = this->currentColleges.find(5);
            selectedColleges.insert(5, saddlebackobj);
            graph.addColleges(this->currentColleges, this->currentIDs);
            int v = 5;
            std::unordered_map<int, std::vector<int>> routes;
            std::unordered_map<int, float> costs;
            graph.dijkstra(v, routes, costs);


            int currentID = 5;
            int selectedID = 0;
            College currentCollege = this->currentColleges.find(currentID);
            double shortestDistance = 1000000.0;

            std::vector<int> visited;
            visited.push_back(5);
            while (selectedColleges.size() != 1){
                //qInfo() << "Current college: " << currentCollege.getName();
                shortestDistance = 10000000.0;
                std::vector<int>::iterator found;
                for (std::vector<int>::iterator itr = selectedIDs.begin(); itr != selectedIDs.end(); itr++){
                    if (costs[*itr] < shortestDistance && *itr != currentID && std::find(visited.begin(), visited.end(), *itr) == visited.end()){
                        //qInfo() << "found: " << *itr;
                        shortestDistance = costs[*itr];
                        selectedID = *itr;
                        found = itr;
                    }
                }
                College selected = selectedColleges.find(selectedID);
                this->route.push(selected);
                selectedIDs.erase(found);
                qInfo() << "Shortest distance: " << QString::number(shortestDistance);

                //Find the distance now between currentCollege and selectedCollege using Dijkstra's now
                graph.dijkstra(currentID, routes, costs);
                totalDistance += costs[selectedID];
                qInfo() << "cost: " << QString::number(costs[selectedID]);

                graph.dijkstra(selectedID, routes, costs);
                visited.push_back(selectedID);
                selectedColleges.erase(currentID);
                currentID = selectedID;
                currentCollege = selected;
            }

            //There should be only one college left now, add it to our queue
            qInfo() << "COLLEGES LEFT: " << selectedColleges.size();

            /*
            for (int id : this->selectedIDs){
                qInfo() << 5;
                if (id == 5){
                    continue;
                }

                for (auto it = routes[id].begin(); it != routes[id].end();
                     ++it) {
                    std::cout << currentColleges.find(*it).getName().toStdString() << " (" << *it << ")";

                    if (it != routes[id].end() - 1) {
                        std::cout << " -> ";
                    } else if (it == routes[id].end() - 1){
                        //We are at the destination now, add it to the route
                        College nextCollegeToVisit = currentColleges.find(*it);
                        this->route.push(nextCollegeToVisit);

                    }
                }
                this->totalDistance += costs[id];
            }

            */

            break;
        }
        case 4:
        {
            //Saddleback is already at the top of the route at this point
            qInfo() << "top of route: " << route.front().getName();

            WeightedGraph graph;

            College michigan = this->currentColleges.find(6);
            selectedColleges.insert(6, michigan);

            graph.addColleges(this->currentColleges, this->currentIDs);
            int v = 6;
            std::unordered_map<int, std::vector<int>> routes;
            std::unordered_map<int, float> costs;
            graph.dijkstra(6, routes, costs);

            int currentID = 6;
            int selectedID = 0;
            College currentCollege = this->currentColleges.find(currentID);
            double shortestDistance = 1000000.0;

            std::vector<int> visited;
            visited.push_back(6);
            while (selectedColleges.size() != 1){
                //qInfo() << "Current college: " << currentCollege.getName();
                shortestDistance = 10000000.0;
                std::vector<int>::iterator found;
                for (std::vector<int>::iterator itr = selectedIDs.begin(); itr != selectedIDs.end(); itr++){
                    if (costs[*itr] < shortestDistance && *itr != currentID && std::find(visited.begin(), visited.end(), *itr) == visited.end()){
                        //qInfo() << "found: " << *itr;
                        shortestDistance = costs[*itr];
                        selectedID = *itr;
                        found = itr;
                    }
                }
                College selected = selectedColleges.find(selectedID);
                this->route.push(selected);
                selectedIDs.erase(found);
                qInfo() << "Shortest distance: " << QString::number(shortestDistance);

                //Find the distance now between currentCollege and selectedCollege using Dijkstra's now
                graph.dijkstra(currentID, routes, costs);
                totalDistance += shortestDistance;
                qInfo() << "cost: " << QString::number(costs[selectedID]);

                graph.dijkstra(selectedID, routes, costs);
                visited.push_back(selectedID);
                selectedColleges.erase(currentID);
                currentID = selectedID;
                currentCollege = selected;
            }

            this->buyNext();
            break;

        }
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
            this->totalSpent += (*itr)->getTotalSpent();
        }

        qInfo() << "Total distance: " << QString::number(this->totalDistance);

        trippopup* popup = new trippopup(this->purchasers, this->totalDistance, this->totalSpent, currentColleges, routeToPass);
        this->buying = false;
        this->planning = false;

        totalSpent = 0;
        totalDistance = 0;

        //Clear trip stuff here, maybe a function?
        this->purchasers.clear();
        for (int i : selectedIDs){
            this->selectedColleges.erase(i);
        }

        CollegeHashMap empty;
        this->selectedColleges = empty;

        this->selectedIDs.clear();
        while(!routeToPass.empty()) routeToPass.pop();
        while (!route.empty()) route.pop();

        this->ui->collegesList->clear();

        this->ui->purchaserCollegeLabel->setText("Current College: ");
        this->ui->buyingTable->setRowCount(0);

        popup->setWindowTitle("Trip Final Information");
        popup->show();

    }
}

void Trip::on_nextCollegeButton_clicked()
{
    if (!this->route.empty()){
        routeToPass.push(route.front());
        route.pop();
    }

    this->buyNext();
}


void Trip::on_addAllButton_clicked(){
    qInfo() << "selected size: " << selectedIDs.size();
    for (int i : currentIDs){
        if (std::find(selectedIDs.begin(), selectedIDs.end(), i) == selectedIDs.end() && route.front().getID() != currentColleges.find(i).getID()){
            selectedIDs.push_back(i);
            College college = currentColleges.find(i);
            selectedColleges.insert(i, college);
            ui->collegesList->addItem(QString::number(college.getID()) + " - " + college.getName());

        }
    }
}

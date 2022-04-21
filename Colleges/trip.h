#ifndef TRIP_H
#define TRIP_H

#include "dbmanager.h"
#include "college.h"
#include "collegehashmap.h"
#include "purchaser.h"
#include "graph.h"

#include <QDialog>
#include <queue>

namespace Ui {
class Trip;
}

class Trip : public QDialog
{
    Q_OBJECT

public:
    explicit Trip(QWidget *parent = nullptr);

    void populateTable(int id);

    void buyNext();

    ~Trip();

private slots:
    void onAddItemClicked();

    void on_chooseStartTrip_clicked();

    void on_executeTrip_clicked();

    void onAddCollegeClicked();

    void on_specificOrderTrip_clicked();

    void on_fromSaddlebackTrip_clicked();

    void on_michiganTrip_clicked();

    void on_nextCollegeButton_clicked();

private:
    Ui::Trip *ui;

    DbManager*       db;              /// connection to database
    CollegeHashMap   currentColleges; /// Hashmap to hold all current college objects
    std::vector<int> currentIDs;

    std::vector<Purchaser*> purchasers;
    CollegeHashMap   selectedColleges;
    std::vector<int> selectedIDs;

    std::queue<College> route;

    bool planning;
    bool buying;

    //type of college trip being done
    /*
     * 1 - Custom trip (choose initial)
     * 2 - Custom trip (specific order)
     * 3 - From Saddleback
     * 4 - From Michigan
     * 5 - BFS
     * 6 - DFS
     */
    int mode;

    College selected;

    double totalDistance;

};

#endif // TRIP_H

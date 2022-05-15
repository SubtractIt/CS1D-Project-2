#ifndef TRIP_H
#define TRIP_H

#include "dbmanager.h"
#include "college.h"
#include "collegehashmap.h"
#include "purchaser.h"
#include "graph.h"
#include "trippopup.h"

#include <QDialog>
#include <queue>



namespace Ui {
class Trip;
}

///
/// @brief The Trip class -- Encapsulates all the logic of taking a trip
///
class Trip : public QDialog
{
    Q_OBJECT

public:
    ///
    /// @brief Default constructor
    ///
    explicit Trip(QWidget *parent = nullptr);


    ///
    /// @brief Populates the souvenir buying table for a specific college
    /// @param id of College we want to buy souvenirs from
    ///
    void populateTable(int id);

    ///
    /// @brief Moves the souvenir table to the next college in our trip queue
    ///
    void buyNext();

    ///
    /// @brief Empty destructor
    ///
    ~Trip();

private slots:
    ///
    /// @brief onAddItemClicked
    /// @details Called when an item in the souvenir table is clicked. Handles purchasing.
    ///
    void onAddItemClicked();

    ///
    /// @brief on_chooseStartTrip_clicked
    /// @details Handles starting a trip from a specific college
    ///
    void on_chooseStartTrip_clicked();

    ///
    /// @brief on_executeTrip_clicked
    /// @details Handles executing a trip once a user has added all colleges to visit
    ///
    void on_executeTrip_clicked();

    ///
    /// @brief onAddCollegeClicked
    /// @details Handles adding a college when they add it to their trip
    ///
    void onAddCollegeClicked();

    ///
    /// @brief on_specificOrderTrip_clicked
    /// @details Handles starting a trip in a specific order
    ///
    void on_specificOrderTrip_clicked();

    ///
    /// @brief on_fromSaddlebackTrip_clicked
    /// @details Starts a trip from Saddleback and visits every college + executes it automatically
    ///
    void on_fromSaddlebackTrip_clicked();

    ///
    /// @brief on_michiganTrip_clicked
    /// @details Starts a trip from Michigan. Colleges will be visited in most efficient order.
    ///
    void on_michiganTrip_clicked();

    ///
    /// @brief on_nextCollegeButton_clicked
    /// @details Slot for handling when the "next" button has been clicked for a trip. Calls buyNext().
    ///
    void on_nextCollegeButton_clicked();

    ///
    /// @brief on_addAllButton_clicked
    /// @details Adds all colleges except those already added to the current trip
    ///
    void on_addAllButton_clicked();

private:
    Ui::Trip *ui;

    DbManager*       db;              /// connection to database
    CollegeHashMap   currentColleges; /// Hashmap to hold all current college objects
    std::vector<int> currentIDs;

    std::vector<Purchaser*> purchasers;
    CollegeHashMap   selectedColleges;
    std::vector<int> selectedIDs;

    std::queue<College> route;
    std::queue<College> routeToPass;

    bool planning;
    bool buying;

    //type of college trip being done
    /*
     * 1 - Custom trip (choose initial)
     * 2 - Custom trip (specific order)
     * 3 - From Saddleback
     * 4 - From Michigan
     */
    int mode;

    College selected;

    double totalDistance;
    double totalSpent;

};

#endif // TRIP_H

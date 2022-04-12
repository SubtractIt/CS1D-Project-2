#ifndef TRIP_H
#define TRIP_H

#include "dbmanager.h"
#include "college.h"
#include "collegehashmap.h"
#include "purchaser.h"

#include <QDialog>

namespace Ui {
class Trip;
}

class Trip : public QDialog
{
    Q_OBJECT

public:
    explicit Trip(QWidget *parent = nullptr);

    void populateTable(int id);

    ~Trip();

private slots:
    void onAddItemClicked();

private:
    Ui::Trip *ui;

    DbManager*       db;              /// connection to database
    CollegeHashMap   currentColleges; /// Hashmap to hold all current college objects
    std::vector<int> currentIDs;

    std::vector<Purchaser*> purchaser;
};

#endif // TRIP_H

#ifndef TRIP_H
#define TRIP_H

#include "dbmanager.h"
#include "college.h"
#include "collegehashmap.h"

#include <QDialog>

namespace Ui {
class Trip;
}

class Trip : public QDialog
{
    Q_OBJECT

public:
    explicit Trip(QWidget *parent = nullptr);
    ~Trip();

private:
    Ui::Trip *ui;

    DbManager*       db;              /// connection to database
    CollegeHashMap   currentColleges; /// Hashmap to hold all current college objects
};

#endif // TRIP_H

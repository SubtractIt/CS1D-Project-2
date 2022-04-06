#ifndef TRIP_H
#define TRIP_H

#include "college.h"
#include "collegehashmap.h"

#include <QObject>
#include <QWidget>

class Trip
{
public:
    Trip(CollegeHashMap colleges);

    void startTrip(const int typeOfTrip);

    void fromSaddleback();

    void customTrip();

private:





};

#endif // TRIP_H

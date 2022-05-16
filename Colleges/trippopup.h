#ifndef TRIPPOPUP_H
#define TRIPPOPUP_H

#include "purchaser.h"
#include "college.h"
#include "trip.h"
#include "collegehashmap.h"

#include <QDialog>

namespace Ui {
class trippopup;
}

///
/// @brief The trippopup class
///
class trippopup : public QDialog
{
    Q_OBJECT

public:
    ///
    /// @brief Initialize the pop up with purchasers, college distance, total
    ///        spent, colleges, and trip route
    /// @param purchasers - purchasers
    /// @param totalDistance - totalDistance
    /// @param totalSpent - totalSpent
    /// @param colleges - colleges
    /// @param route - route
    /// @param parent - parent
    ///
    explicit trippopup(std::vector<Purchaser*> purchasers, double totalDistance, double totalSpent, CollegeHashMap colleges, std::queue<College> route, QWidget *parent = nullptr);
    ~trippopup();

private:
    Ui::trippopup *ui;
};

#endif // TRIPPOPUP_H

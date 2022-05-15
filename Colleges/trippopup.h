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
/// \brief The trippopup class - Displays all relevant information for a trip
///
class trippopup : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief Constructor for the popup
    /// \param purchasers - All purchasers for each college
    /// \param totalDistance - Total distance calculated
    /// \param totalSpent - Total spent calculated
    /// \param colleges - All colleges in the database
    /// \param route - Queue of the route we took in our trip
    /// \param parent
    ///
    explicit trippopup(std::vector<Purchaser*> purchasers, double totalDistance, double totalSpent, CollegeHashMap colleges, std::queue<College> route, QWidget *parent = nullptr);
    ~trippopup();

private:
    Ui::trippopup *ui;
};

#endif // TRIPPOPUP_H

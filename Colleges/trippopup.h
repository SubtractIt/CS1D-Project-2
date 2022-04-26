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

class trippopup : public QDialog
{
    Q_OBJECT

public:
    explicit trippopup(std::vector<Purchaser*> purchasers, double totalDistance, double totalSpent, CollegeHashMap colleges, std::queue<College> route, QWidget *parent = nullptr);
    ~trippopup();

private:
    Ui::trippopup *ui;
};

#endif // TRIPPOPUP_H

/********************************************************************************
** Form generated from reading UI file 'trip.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIP_H
#define UI_TRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Trip
{
public:

    void setupUi(QDialog *Trip)
    {
        if (Trip->objectName().isEmpty())
            Trip->setObjectName(QString::fromUtf8("Trip"));
        Trip->resize(400, 300);

        retranslateUi(Trip);

        QMetaObject::connectSlotsByName(Trip);
    } // setupUi

    void retranslateUi(QDialog *Trip)
    {
        Trip->setWindowTitle(QApplication::translate("Trip", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Trip: public Ui_Trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H

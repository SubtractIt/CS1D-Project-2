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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trip
{
public:
    QTabWidget *tabWidget;
    QWidget *michiganStart;
    QTableWidget *buyingTable;
    QLabel *purchaserCollegeLabel;
    QPushButton *michiganTrip;
    QPushButton *chooseStartTrip;
    QPushButton *specificOrderTrip;
    QPushButton *executeTrip;
    QListWidget *collegesList;
    QPushButton *fromSaddlebackTrip;
    QTableWidget *collegesTable;
    QLabel *purchaserLabel;
    QPushButton *nextCollegeButton;
    QLabel *adderLabel;
    QPushButton *addAllButton;

    void setupUi(QDialog *Trip)
    {
        if (Trip->objectName().isEmpty())
            Trip->setObjectName(QString::fromUtf8("Trip"));
        Trip->resize(1187, 740);
        tabWidget = new QTabWidget(Trip);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1201, 741));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        michiganStart = new QWidget();
        michiganStart->setObjectName(QString::fromUtf8("michiganStart"));
        buyingTable = new QTableWidget(michiganStart);
        if (buyingTable->columnCount() < 3)
            buyingTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        buyingTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        buyingTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        buyingTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        buyingTable->setObjectName(QString::fromUtf8("buyingTable"));
        buyingTable->setGeometry(QRect(670, 120, 471, 341));
        purchaserCollegeLabel = new QLabel(michiganStart);
        purchaserCollegeLabel->setObjectName(QString::fromUtf8("purchaserCollegeLabel"));
        purchaserCollegeLabel->setGeometry(QRect(670, 70, 351, 41));
        michiganTrip = new QPushButton(michiganStart);
        michiganTrip->setObjectName(QString::fromUtf8("michiganTrip"));
        michiganTrip->setGeometry(QRect(410, 590, 171, 31));
        chooseStartTrip = new QPushButton(michiganStart);
        chooseStartTrip->setObjectName(QString::fromUtf8("chooseStartTrip"));
        chooseStartTrip->setGeometry(QRect(410, 530, 171, 51));
        specificOrderTrip = new QPushButton(michiganStart);
        specificOrderTrip->setObjectName(QString::fromUtf8("specificOrderTrip"));
        specificOrderTrip->setGeometry(QRect(190, 530, 161, 51));
        executeTrip = new QPushButton(michiganStart);
        executeTrip->setObjectName(QString::fromUtf8("executeTrip"));
        executeTrip->setGeometry(QRect(10, 590, 100, 32));
        collegesList = new QListWidget(michiganStart);
        collegesList->setObjectName(QString::fromUtf8("collegesList"));
        collegesList->setGeometry(QRect(670, 480, 471, 181));
        fromSaddlebackTrip = new QPushButton(michiganStart);
        fromSaddlebackTrip->setObjectName(QString::fromUtf8("fromSaddlebackTrip"));
        fromSaddlebackTrip->setGeometry(QRect(190, 590, 161, 31));
        collegesTable = new QTableWidget(michiganStart);
        if (collegesTable->columnCount() < 1)
            collegesTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        collegesTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        collegesTable->setObjectName(QString::fromUtf8("collegesTable"));
        collegesTable->setGeometry(QRect(20, 120, 621, 391));
        collegesTable->horizontalHeader()->setStretchLastSection(true);
        purchaserLabel = new QLabel(michiganStart);
        purchaserLabel->setObjectName(QString::fromUtf8("purchaserLabel"));
        purchaserLabel->setGeometry(QRect(670, 40, 221, 41));
        QFont font;
        font.setPointSize(24);
        purchaserLabel->setFont(font);
        nextCollegeButton = new QPushButton(michiganStart);
        nextCollegeButton->setObjectName(QString::fromUtf8("nextCollegeButton"));
        nextCollegeButton->setGeometry(QRect(1030, 80, 100, 32));
        adderLabel = new QLabel(michiganStart);
        adderLabel->setObjectName(QString::fromUtf8("adderLabel"));
        adderLabel->setGeometry(QRect(20, 50, 281, 41));
        adderLabel->setFont(font);
        addAllButton = new QPushButton(michiganStart);
        addAllButton->setObjectName(QString::fromUtf8("addAllButton"));
        addAllButton->setGeometry(QRect(530, 80, 100, 32));
        tabWidget->addTab(michiganStart, QString());

        retranslateUi(Trip);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Trip);
    } // setupUi

    void retranslateUi(QDialog *Trip)
    {
        Trip->setWindowTitle(QApplication::translate("Trip", "Dialog", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("Trip", "<html><head/><body><p>Michigan Start</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        michiganStart->setWhatsThis(QApplication::translate("Trip", "Michigan First", nullptr));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = buyingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Trip", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = buyingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Trip", "Add", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = buyingTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Trip", "Count", nullptr));
        purchaserCollegeLabel->setText(QApplication::translate("Trip", "Current College:", nullptr));
        michiganTrip->setText(QApplication::translate("Trip", "Trip From Michigan", nullptr));
        chooseStartTrip->setText(QApplication::translate("Trip", "Custom Trip\n"
" (Choose Start)", nullptr));
        specificOrderTrip->setText(QApplication::translate("Trip", "Custom Trip \n"
"(Specific Order)", nullptr));
        executeTrip->setText(QApplication::translate("Trip", "Execute Trip", nullptr));
        fromSaddlebackTrip->setText(QApplication::translate("Trip", "Trip From Saddleback", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = collegesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Trip", "Add", nullptr));
        purchaserLabel->setText(QApplication::translate("Trip", "Purchaser", nullptr));
        nextCollegeButton->setText(QApplication::translate("Trip", "Next College", nullptr));
        adderLabel->setText(QApplication::translate("Trip", "College Adder", nullptr));
        addAllButton->setText(QApplication::translate("Trip", "Add All", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(michiganStart), QApplication::translate("Trip", "Trip Planner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Trip: public Ui_Trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H

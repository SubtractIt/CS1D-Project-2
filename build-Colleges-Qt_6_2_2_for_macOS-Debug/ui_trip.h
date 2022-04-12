/********************************************************************************
** Form generated from reading UI file 'trip.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIP_H
#define UI_TRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trip
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *michiganStart;
    QTableWidget *buyingTable;
    QComboBox *allColleges;
    QLabel *label_2;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;

    void setupUi(QDialog *Trip)
    {
        if (Trip->objectName().isEmpty())
            Trip->setObjectName(QString::fromUtf8("Trip"));
        Trip->resize(1061, 666);
        label = new QLabel(Trip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 20, 191, 41));
        tabWidget = new QTabWidget(Trip);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1061, 671));
        michiganStart = new QWidget();
        michiganStart->setObjectName(QString::fromUtf8("michiganStart"));
        buyingTable = new QTableWidget(michiganStart);
        if (buyingTable->columnCount() < 2)
            buyingTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        buyingTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        buyingTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        buyingTable->setObjectName(QString::fromUtf8("buyingTable"));
        buyingTable->setGeometry(QRect(570, 120, 471, 341));
        allColleges = new QComboBox(michiganStart);
        allColleges->setObjectName(QString::fromUtf8("allColleges"));
        allColleges->setGeometry(QRect(570, 60, 371, 81));
        label_2 = new QLabel(michiganStart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 40, 101, 41));
        tabWidget->addTab(michiganStart, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Trip);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Trip);
    } // setupUi

    void retranslateUi(QDialog *Trip)
    {
        Trip->setWindowTitle(QCoreApplication::translate("Trip", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Trip", "Select college to purchase from", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("Trip", "<html><head/><body><p>Michigan Start</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        michiganStart->setWhatsThis(QCoreApplication::translate("Trip", "Michigan First", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem = buyingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Trip", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = buyingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Trip", "Add", nullptr));
        label_2->setText(QCoreApplication::translate("Trip", "Purchaser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(michiganStart), QCoreApplication::translate("Trip", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Trip", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Trip", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Trip", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Trip: public Ui_Trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H

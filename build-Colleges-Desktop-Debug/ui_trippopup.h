/********************************************************************************
** Form generated from reading UI file 'trippopup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPOPUP_H
#define UI_TRIPPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_trippopup
{
public:
    QListWidget *spentList;
    QListWidget *routeList;
    QLabel *totalDistanceLabel;
    QLabel *totalSpentLabel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *trippopup)
    {
        if (trippopup->objectName().isEmpty())
            trippopup->setObjectName(QString::fromUtf8("trippopup"));
        trippopup->resize(674, 350);
        spentList = new QListWidget(trippopup);
        spentList->setObjectName(QString::fromUtf8("spentList"));
        spentList->setGeometry(QRect(20, 70, 291, 192));
        routeList = new QListWidget(trippopup);
        routeList->setObjectName(QString::fromUtf8("routeList"));
        routeList->setGeometry(QRect(340, 70, 311, 192));
        totalDistanceLabel = new QLabel(trippopup);
        totalDistanceLabel->setObjectName(QString::fromUtf8("totalDistanceLabel"));
        totalDistanceLabel->setGeometry(QRect(20, 320, 651, 16));
        totalSpentLabel = new QLabel(trippopup);
        totalSpentLabel->setObjectName(QString::fromUtf8("totalSpentLabel"));
        totalSpentLabel->setGeometry(QRect(20, 290, 641, 16));
        label = new QLabel(trippopup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 211, 16));
        label_2 = new QLabel(trippopup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 50, 58, 16));

        retranslateUi(trippopup);

        QMetaObject::connectSlotsByName(trippopup);
    } // setupUi

    void retranslateUi(QDialog *trippopup)
    {
        trippopup->setWindowTitle(QApplication::translate("trippopup", "Dialog", nullptr));
        totalDistanceLabel->setText(QApplication::translate("trippopup", "Total distance:", nullptr));
        totalSpentLabel->setText(QApplication::translate("trippopup", "Total spent:", nullptr));
        label->setText(QApplication::translate("trippopup", "Money spent per college", nullptr));
        label_2->setText(QApplication::translate("trippopup", "Route", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trippopup: public Ui_trippopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPOPUP_H

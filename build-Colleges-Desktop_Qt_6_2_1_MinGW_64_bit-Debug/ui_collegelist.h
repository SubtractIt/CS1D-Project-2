/********************************************************************************
** Form generated from reading UI file 'collegelist.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLEGELIST_H
#define UI_COLLEGELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollegeList
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *collegeList;
    QWidget *tab_2;
    QListWidget *californiaList;
    QWidget *tab_3;
    QWidget *tab_4;
    QListWidget *undergradList;
    QWidget *tab_5;
    QListWidget *saddlebackDistList;

    void setupUi(QDialog *CollegeList)
    {
        if (CollegeList->objectName().isEmpty())
            CollegeList->setObjectName(QString::fromUtf8("CollegeList"));
        CollegeList->resize(952, 505);
        tabWidget = new QTabWidget(CollegeList);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 921, 481));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        collegeList = new QListWidget(tab);
        collegeList->setObjectName(QString::fromUtf8("collegeList"));
        collegeList->setGeometry(QRect(30, 10, 871, 431));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        californiaList = new QListWidget(tab_2);
        californiaList->setObjectName(QString::fromUtf8("californiaList"));
        californiaList->setGeometry(QRect(10, 10, 891, 431));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        undergradList = new QListWidget(tab_4);
        undergradList->setObjectName(QString::fromUtf8("undergradList"));
        undergradList->setGeometry(QRect(10, 10, 901, 421));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        saddlebackDistList = new QListWidget(tab_5);
        saddlebackDistList->setObjectName(QString::fromUtf8("saddlebackDistList"));
        saddlebackDistList->setGeometry(QRect(10, 10, 891, 431));
        tabWidget->addTab(tab_5, QString());

        retranslateUi(CollegeList);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(CollegeList);
    } // setupUi

    void retranslateUi(QDialog *CollegeList)
    {
        CollegeList->setWindowTitle(QCoreApplication::translate("CollegeList", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CollegeList", "All Colleges by Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CollegeList", "California Colleges by Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CollegeList", "All Colleges by State and Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("CollegeList", "Undergraduate Population", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("CollegeList", "Distance from Saddleback College", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollegeList: public Ui_CollegeList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLEGELIST_H

/********************************************************************************
** Form generated from reading UI file 'collegelist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLEGELIST_H
#define UI_COLLEGELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QListWidget *statesWidget;
    QWidget *tab_4;
    QTableWidget *undergradTable;
    QWidget *tab_5;
    QTableWidget *saddlebackTable;
    QWidget *dfsTab;
    QListWidget *bfsList;
    QLabel *label;
    QLabel *milageLabel;
    QWidget *bfsTab;
    QListWidget *dfsList;
    QLabel *label_2;
    QLabel *milageLabel_2;
    QWidget *mstTab;
    QListWidget *mstWidget;
    QLabel *label_3;
    QLabel *milageLabel_3;

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
        statesWidget = new QListWidget(tab_3);
        statesWidget->setObjectName(QString::fromUtf8("statesWidget"));
        statesWidget->setGeometry(QRect(10, 10, 901, 441));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        undergradTable = new QTableWidget(tab_4);
        if (undergradTable->columnCount() < 2)
            undergradTable->setColumnCount(2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        undergradTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        undergradTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        undergradTable->setObjectName(QString::fromUtf8("undergradTable"));
        undergradTable->setGeometry(QRect(10, 10, 901, 431));
        undergradTable->setMinimumSize(QSize(901, 0));
        undergradTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        saddlebackTable = new QTableWidget(tab_5);
        if (saddlebackTable->columnCount() < 2)
            saddlebackTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        saddlebackTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        saddlebackTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        saddlebackTable->setObjectName(QString::fromUtf8("saddlebackTable"));
        saddlebackTable->setGeometry(QRect(10, 10, 891, 431));
        tabWidget->addTab(tab_5, QString());
        dfsTab = new QWidget();
        dfsTab->setObjectName(QString::fromUtf8("dfsTab"));
        bfsList = new QListWidget(dfsTab);
        bfsList->setObjectName(QString::fromUtf8("bfsList"));
        bfsList->setGeometry(QRect(10, 10, 901, 441));
        label = new QLabel(dfsTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 30, 111, 21));
        milageLabel = new QLabel(dfsTab);
        milageLabel->setObjectName(QString::fromUtf8("milageLabel"));
        milageLabel->setGeometry(QRect(800, 30, 101, 20));
        tabWidget->addTab(dfsTab, QString());
        bfsTab = new QWidget();
        bfsTab->setObjectName(QString::fromUtf8("bfsTab"));
        dfsList = new QListWidget(bfsTab);
        dfsList->setObjectName(QString::fromUtf8("dfsList"));
        dfsList->setGeometry(QRect(10, 10, 901, 441));
        label_2 = new QLabel(bfsTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(700, 20, 111, 21));
        milageLabel_2 = new QLabel(bfsTab);
        milageLabel_2->setObjectName(QString::fromUtf8("milageLabel_2"));
        milageLabel_2->setGeometry(QRect(810, 20, 101, 20));
        tabWidget->addTab(bfsTab, QString());
        mstTab = new QWidget();
        mstTab->setObjectName(QString::fromUtf8("mstTab"));
        mstWidget = new QListWidget(mstTab);
        mstWidget->setObjectName(QString::fromUtf8("mstWidget"));
        mstWidget->setGeometry(QRect(10, 10, 901, 441));
        label_3 = new QLabel(mstTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(690, 30, 111, 21));
        milageLabel_3 = new QLabel(mstTab);
        milageLabel_3->setObjectName(QString::fromUtf8("milageLabel_3"));
        milageLabel_3->setGeometry(QRect(800, 30, 101, 20));
        tabWidget->addTab(mstTab, QString());

        retranslateUi(CollegeList);

        tabWidget->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(CollegeList);
    } // setupUi

    void retranslateUi(QDialog *CollegeList)
    {
        CollegeList->setWindowTitle(QApplication::translate("CollegeList", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CollegeList", "All Colleges by Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CollegeList", "California Colleges by Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CollegeList", "All Colleges by State and Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem = undergradTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CollegeList", "College Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = undergradTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CollegeList", "Number of Undergraduates", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CollegeList", "Undergraduate Population", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = saddlebackTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("CollegeList", "College Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = saddlebackTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("CollegeList", "Saddleback Distance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("CollegeList", "Distance from Saddleback College", nullptr));
        label->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Total Milage:</span></p></body></html>", nullptr));
        milageLabel->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt;\">TextLabel</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dfsTab), QApplication::translate("CollegeList", "BFS", nullptr));
        label_2->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Total Milage:</span></p></body></html>", nullptr));
        milageLabel_2->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt;\">TextLabel</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bfsTab), QApplication::translate("CollegeList", "DFS", nullptr));
        label_3->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Total Milage:</span></p></body></html>", nullptr));
        milageLabel_3->setText(QApplication::translate("CollegeList", "<html><head/><body><p><span style=\" font-size:12pt;\">TextLabel</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mstTab), QApplication::translate("CollegeList", "MST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollegeList: public Ui_CollegeList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLEGELIST_H

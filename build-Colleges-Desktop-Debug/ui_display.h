/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QLabel *label;
    QComboBox *collegeListComboBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *viewAll;
    QLabel *label_4;
    QLabel *label_5;
    QTableWidget *souvenirTable;
    QLabel *numUndergradDisplay;

    void setupUi(QDialog *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QString::fromUtf8("Display"));
        Display->resize(969, 593);
        label = new QLabel(Display);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 260, 331, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        collegeListComboBox = new QComboBox(Display);
        collegeListComboBox->setObjectName(QString::fromUtf8("collegeListComboBox"));
        collegeListComboBox->setGeometry(QRect(40, 310, 331, 22));
        label_2 = new QLabel(Display);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 260, 341, 41));
        label_2->setFont(font);
        label_3 = new QLabel(Display);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 410, 101, 41));
        label_3->setFont(font);
        viewAll = new QPushButton(Display);
        viewAll->setObjectName(QString::fromUtf8("viewAll"));
        viewAll->setGeometry(QRect(60, 100, 221, 51));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        viewAll->setFont(font1);
        label_4 = new QLabel(Display);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 160, 341, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_5 = new QLabel(Display);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 30, 181, 41));
        label_5->setFont(font2);
        souvenirTable = new QTableWidget(Display);
        souvenirTable->setObjectName(QString::fromUtf8("souvenirTable"));
        souvenirTable->setGeometry(QRect(540, 370, 371, 192));
        QFont font3;
        font3.setPointSize(9);
        souvenirTable->setFont(font3);
        numUndergradDisplay = new QLabel(Display);
        numUndergradDisplay->setObjectName(QString::fromUtf8("numUndergradDisplay"));
        numUndergradDisplay->setGeometry(QRect(550, 310, 71, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font4.setPointSize(12);
        numUndergradDisplay->setFont(font4);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QDialog *Display)
    {
        Display->setWindowTitle(QApplication::translate("Display", "Dialog", nullptr));
        label->setText(QApplication::translate("Display", "Select College to View Information", nullptr));
        label_2->setText(QApplication::translate("Display", "Number of Undergraduate Students", nullptr));
        label_3->setText(QApplication::translate("Display", "Souvenirs:", nullptr));
        viewAll->setText(QApplication::translate("Display", "View all Colleges", nullptr));
        label_4->setText(QApplication::translate("Display", "College Specific Information", nullptr));
        label_5->setText(QApplication::translate("Display", "College Listing", nullptr));
        numUndergradDisplay->setText(QApplication::translate("Display", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H

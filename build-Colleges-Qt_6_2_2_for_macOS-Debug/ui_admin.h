/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QTabWidget *AdminFunctions;
    QWidget *modify;
    QTableWidget *souvTable;
    QPushButton *modifySouv;
    QLineEdit *addName;
    QDoubleSpinBox *addPrice;
    QPushButton *addSouv;
    QComboBox *deleteOptions;
    QPushButton *deleteSouv;
    QLabel *deleteLabel;
    QLabel *addLabel;
    QFrame *frame;
    QComboBox *collegeEdit;
    QLabel *collegeEditLabel;
    QFrame *frame_2;
    QWidget *add;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(717, 418);
        AdminFunctions = new QTabWidget(Admin);
        AdminFunctions->setObjectName(QString::fromUtf8("AdminFunctions"));
        AdminFunctions->setGeometry(QRect(10, 10, 701, 401));
        modify = new QWidget();
        modify->setObjectName(QString::fromUtf8("modify"));
        souvTable = new QTableWidget(modify);
        souvTable->setObjectName(QString::fromUtf8("souvTable"));
        souvTable->setGeometry(QRect(270, 90, 421, 221));
        QFont font;
        font.setPointSize(12);
        souvTable->setFont(font);
        modifySouv = new QPushButton(modify);
        modifySouv->setObjectName(QString::fromUtf8("modifySouv"));
        modifySouv->setGeometry(QRect(270, 324, 421, 41));
        modifySouv->setFont(font);
        addName = new QLineEdit(modify);
        addName->setObjectName(QString::fromUtf8("addName"));
        addName->setGeometry(QRect(20, 130, 141, 31));
        addName->setFont(font);
        addPrice = new QDoubleSpinBox(modify);
        addPrice->setObjectName(QString::fromUtf8("addPrice"));
        addPrice->setGeometry(QRect(170, 130, 81, 31));
        addPrice->setFont(font);
        addSouv = new QPushButton(modify);
        addSouv->setObjectName(QString::fromUtf8("addSouv"));
        addSouv->setGeometry(QRect(20, 170, 231, 31));
        addSouv->setFont(font);
        deleteOptions = new QComboBox(modify);
        deleteOptions->setObjectName(QString::fromUtf8("deleteOptions"));
        deleteOptions->setGeometry(QRect(20, 260, 231, 31));
        deleteOptions->setFont(font);
        deleteSouv = new QPushButton(modify);
        deleteSouv->setObjectName(QString::fromUtf8("deleteSouv"));
        deleteSouv->setGeometry(QRect(20, 300, 231, 31));
        deleteSouv->setFont(font);
        deleteLabel = new QLabel(modify);
        deleteLabel->setObjectName(QString::fromUtf8("deleteLabel"));
        deleteLabel->setGeometry(QRect(20, 230, 191, 21));
        deleteLabel->setFont(font);
        addLabel = new QLabel(modify);
        addLabel->setObjectName(QString::fromUtf8("addLabel"));
        addLabel->setGeometry(QRect(20, 100, 181, 21));
        addLabel->setFont(font);
        frame = new QFrame(modify);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 701, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        collegeEdit = new QComboBox(frame);
        collegeEdit->setObjectName(QString::fromUtf8("collegeEdit"));
        collegeEdit->setGeometry(QRect(250, 30, 421, 27));
        collegeEdit->setFont(font);
        collegeEditLabel = new QLabel(frame);
        collegeEditLabel->setObjectName(QString::fromUtf8("collegeEditLabel"));
        collegeEditLabel->setGeometry(QRect(30, 30, 211, 21));
        collegeEditLabel->setFont(font);
        frame_2 = new QFrame(modify);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 80, 261, 291));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        AdminFunctions->addTab(modify, QString());
        frame_2->raise();
        frame->raise();
        souvTable->raise();
        modifySouv->raise();
        addName->raise();
        addPrice->raise();
        addSouv->raise();
        deleteOptions->raise();
        deleteSouv->raise();
        deleteLabel->raise();
        addLabel->raise();
        add = new QWidget();
        add->setObjectName(QString::fromUtf8("add"));
        AdminFunctions->addTab(add, QString());

        retranslateUi(Admin);

        AdminFunctions->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        modifySouv->setText(QCoreApplication::translate("Admin", "Update", nullptr));
        addSouv->setText(QCoreApplication::translate("Admin", "Add", nullptr));
        deleteSouv->setText(QCoreApplication::translate("Admin", "Delete", nullptr));
        deleteLabel->setText(QCoreApplication::translate("Admin", "Delete a Souvenir", nullptr));
        addLabel->setText(QCoreApplication::translate("Admin", "Add a Souvenir", nullptr));
        collegeEditLabel->setText(QCoreApplication::translate("Admin", "Select the College to edit: ", nullptr));
        AdminFunctions->setTabText(AdminFunctions->indexOf(modify), QCoreApplication::translate("Admin", "Modify", nullptr));
        AdminFunctions->setTabText(AdminFunctions->indexOf(add), QCoreApplication::translate("Admin", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

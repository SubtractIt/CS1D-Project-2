#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "dbmanager.h"
#include "college.h"
#include "mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <vector>
#include <QStringList>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:

    void on_collegeEdit_currentIndexChanged(const QString &arg1);

    void on_addSouv_clicked();

    void on_deleteSouv_clicked();

    void on_modifySouv_clicked();

    void setCollegeEditOptions();

    void setSouvEditFields(int id);

private:

    Ui::Admin *ui;

    DbManager* db;
    CollegeHashMap currentColleges;
    std::vector<int> currentIds;
};

#endif // ADMIN_H

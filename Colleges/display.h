#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <QDialog>
#include <QFile>
#include <vector>
#include <sstream>
#include <string>
#include "college.h"
#include "collegelist.h"
#include "dbmanager.h"
#include "collegehashmap.h"


namespace Ui {
class Display;
}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    void fillComboBox();
    ~Display();

private slots:

    void on_viewAll_clicked();
    void on_collegeListComboBox_currentTextChanged(QString selectedSchool);

private:
    Ui::Display *ui;
    DbManager* db;
    std::vector<int> currentIDs;
    CollegeHashMap currentColleges;
    QString selectedSchool;

};

#endif // DISPLAY_H

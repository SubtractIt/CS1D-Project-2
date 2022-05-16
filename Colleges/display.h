///
/// @author Adit Mohindra
/// @file  display.h


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

///
/// @brief Class which holds the display UI elements
///
class Display : public QDialog
{
    Q_OBJECT

public:
    ///
    /// @brief Display constructor
    /// @param parent
    ///
    explicit Display(QWidget *parent = nullptr);

    ///
    /// @brief fills Combo Box with colleges and souvenirs
    ///
    void fillComboBox();

    ///
    /// @brief Destructor for Display class
    ///
    ~Display();

private slots:

    ///
    /// @brief slot for view all button clicked
    ///
    void on_viewAll_clicked();

    ///
    /// @brief Slot for testing whether the text is changed in the combo box to reflect college choice
    /// @param selectedSchool
    ///
    void on_collegeListComboBox_currentTextChanged(QString selectedSchool);

private:
    Ui::Display *ui;
    DbManager* db;
    std::vector<int> currentIDs;
    CollegeHashMap currentColleges;
    QString selectedSchool;

};

#endif // DISPLAY_H

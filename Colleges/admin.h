///
/// @author Juliette Raubolt
/// @file   admin.h
///

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

///
/// @brief   The Admin class, allows data manipulation
/// @details Implements functionality to uplaod more colleges
///          from a file, edit the prices of souvenirs, and
///          add and delete souvs
class Admin;
}

class Admin : public QDialog
{
   Q_OBJECT

public:

   ///
   /// @brief Admin constructor
   ///
   explicit Admin(QWidget *parent = nullptr);

   ///
   /// @brief Admin destructor
   ///
   ~Admin();

private slots:

   ///
   /// @brief   on_collegeEdit_currentIndexChanged
   /// @details When the index is changed the id is extracted from
   ///          the selection and used to populate editing fields
   /// @param   arg1 string of current selection in dropdown
   ///
   void on_collegeEdit_currentIndexChanged(const QString &arg1);

   ///
   /// @brief   on_addSouv_clicked
   /// @details When add button is clicked check for valid inputs
   ///          for both name and price and if valid adds to the
   ///          current colleges souvenirs
   ///
   void on_addSouv_clicked();

   ///
   /// @brief   on_deleteSouv_clicked
   /// @details When delete button is clicked as long as there is
   ///          a selection to delete then deletes the seleced souvenir
   ///          from the delete dropdown menu
   ///
   void on_deleteSouv_clicked();

   ///
   /// @brief   on_modifySouv_clicked
   /// @details When modify is selected goes through the edit table
   ///          to update the prices of the souvenirs as long as valid
   ///          prices are entered
   ///
   void on_modifySouv_clicked();

   ///
   /// @brief   on_upload_clicked
   /// @details When upload is clicked checks for valid file names and
   ///          then reads and adds new colleges and souvenirs to the
   ///          database as long as successfully read
   ///
   void on_upload_clicked();

private:

   ///
   /// @brief   setCollegeEditOptions
   /// @details Takes all colleges and creates a # - name message for each
   ///          one to add to the dropdown menu that selects which college
   ///          to edit
   void setCollegeEditOptions();

   ///
   /// @brief   setSouvEditFields
   /// @details Takes an id for a college and populates the editing fields
   ///          (delete dropdown menu and editing table) to the corresponding
   ///          college's souvenirs
   /// @param   id id of the college to be edited
   ///
   void setSouvEditFields(int id);

   Ui::Admin *ui;

   DbManager*       db;              /// connection to database
   CollegeHashMap   currentColleges; /// Hashmap to hold all current college objects
   std::vector<int> currentIds;      /// Vector to hold all ids of corresponding colleges
};

#endif // ADMIN_H

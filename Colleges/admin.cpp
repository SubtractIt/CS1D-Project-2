///
/// @author Juliette Raubolt
/// @file   admin.cpp
///

#include "admin.h"
#include "ui_admin.h"


/************************************************************
 * Constructor
 * ----------------------------------------------------------
 * Handles initalizations. Connects the database, sets the
 * college options dropdown menus and corresponding editing
 * fields, initializes file name fields for ease
 ***********************************************************/
Admin::Admin(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::Admin)
{
   ui->setupUi(this);

   QString path;

// Creating database connection
   #if __APPLE__ && TARGET_OS_MAC
         path = "../../../../Colleges/colleges.db";
   #elif __linux__
         path = "../Colleges/colleges.db";
   #else
         path = "D:/Qt/PROJECT 2 CS1D/CS1D-Project-2/Colleges/colleges.db";
   #endif

   db = new DbManager(path);

   // Immediately create dropdown menu with college options
   setCollegeEditOptions();

   // As long as there are colleges, then there is a college in the
   // edit options and can populate editing fields with that info
   if(db->getAllColleges().size() != 0) {
       // Get current selection, extract id, set edit fields for id
       QString selected = ui->collegeEdit->currentText();
       int id = selected.section(' ',0,0).toInt();
       setSouvEditFields(id);
   }

   // For the sake of ease have the upload fields already set
   ui->collegeUpload->setText("college2");
   ui->souvUpload->setText("souvenir2");
}

// Destructor
Admin::~Admin()
{
   delete db;
   delete ui;
}


/*******************************************************************
 * setCollegeEditOptions
 * -----------------------------------------------------------------
 * Takes all colleges and creates a # - name message for each
 * one to add to the dropdown menu that selects which college
 * to edit
 * -----------------------------------------------------------------
 * pre conditions:
 *  none
 * post conditions:
 *  Returns nothing and updates the dropdown menu with editing
 *  options
 ******************************************************************/
void Admin::setCollegeEditOptions() {
  // Get all colleges and corresponding ids to loop through
  currentColleges = db->getAllColleges();
  currentIds = db->getAllIds();

  // Make sure the drop down box is clear
  // prior to adding
  ui->collegeEdit->clear();

  // Helping variables to create the # - name format
  QString name;        // Name of college
  int     id;          // Id of college
  QString collegeInfo; // Name and Id in # - name format
  College current;     // Object of college to get name & id

  // Create a vector of ints that correspond to the id
  // to loop through after to set and add college options
  std::vector<int> ids;
  for (int id : currentIds) ids.push_back(id);

   // Loop through ids and get the current college's name
   // and id to create the display string and then add to the
   // dropdown menu
   for (int i : ids) {
      // Get current college
      current = currentColleges.find(i);
      // Get name and id
      name = current.getName();
      id = current.getID();

      // Set # - name display string and add to dropdown menu
      collegeInfo = QString::number(id) + " - " + name;
      ui->collegeEdit->addItem(collegeInfo);
  }
}

/*******************************************************************
 * setSouvEditFields
 * -----------------------------------------------------------------
 * Takes an id for a college and populates the editing fields
 * (delete dropdown menu and editing table) to the corresponding
 * college's souvenirs.
 * -----------------------------------------------------------------
 * pre conditions:
 *  id : id of college with info to populate editing fields with
 * post conditions:
 *  Returns nothing and updates the delete options and editing
 *  table to info that corresponds with id passed in
 ******************************************************************/
void Admin::setSouvEditFields(int id) {
   // Get all colleges and corresponding ids to loop through
   currentColleges = db->getAllColleges();
   currentIds = db->getAllIds();

   College current; // Object for corresponding id
                    // to set edit fields

   // Loop through colleges to find the corresponding college
   // for the passed in id
   for(int i : currentIds) {
       if(id == currentColleges.find(i).getID()) {
           current = currentColleges.find(i);
           break;
       }
   }

   // Now that college is found, get the souvenirs to load the
   // delete menu and editing table
   std::vector<Souvenir> currentSouvs = current.getSouvenirs();

   // Make sure the dropdown of delete options is clear
   // before adding to it
   ui->deleteOptions->clear();

   // Souvenirs is never empty so if there is a size of 1, then
   // may be empty or may have one souvenir so have to check if the
   // 1 souvenir has an empty name
   // If it is an empty name then is empty and need to set
   // everything to empty
   // If not then there is just one normal souvenir so go on as any
   // other case to populate the delete options and table
   if(currentSouvs.size() != 1 || currentSouvs[0].name != "") {
       // Set number of rows to size of the souvenirs
       ui->souvTable->setRowCount(currentSouvs.size());

       // Helper variables to set table and dropdown menu
       QStringList     tableRows;       // Row headers ro hold souv name
       QDoubleSpinBox* souvPrice;       // Spinbox to set price of souv
       QString         deleteSouvNames; // String to hold delete option mess.

       // Loop through every souvenir and set row label and price
       // adjuster for table and # - name $## for the delete options
       for(size_t i = 0; i < currentSouvs.size(); ++i) {
           // Create new spin box and assign to according cell in table
           souvPrice = new QDoubleSpinBox(ui->souvTable);
           souvPrice->setMaximum(1000);
           souvPrice->setValue(currentSouvs[i].price);
           ui->souvTable->setCellWidget(i,0,souvPrice);

           // Add souvenir name to row labels
           tableRows << currentSouvs[i].name;

           // Create delete option message with # - name $##
           // and add to the delete dropdown options
           deleteSouvNames = QString::number(i+1) + " - " + currentSouvs[i].name + " $" + QString::number(currentSouvs[i].price);
           ui->deleteOptions->addItem(deleteSouvNames);
       }

       // Take the row labels and set the table to them
       ui->souvTable->setVerticalHeaderLabels(tableRows);

   } else {
       // Means empty souvenirs so leave everything empty
       ui->souvTable->setRowCount(0);
   }
}

/*******************************************************************
 * on_collegeEdit_currentIndexChanged
 * -----------------------------------------------------------------
 * When the index is changed the id is extracted from
 * the selection and used to populate editing fields
 * -----------------------------------------------------------------
 * pre conditions:
 *  arg1 : string of selection in dropdown menu
 * post conditions:
 *  Returns nothing and updates editting fields to show the right
 *  college
 ******************************************************************/
void Admin::on_collegeEdit_currentIndexChanged(const QString &arg1)
{
    qInfo() << "test";
   // Get the id section from the dropdown selection
   QString selected = ui->collegeEdit->currentText();
   int id = selected.section(' ',0,0).toInt();

   // Set editing fields to that id
   setSouvEditFields(id);

   // Clear name and price fields now onto new college
   ui->addName->clear();
   ui->addPrice->clear();
}

/*******************************************************************
 * on_addSouv_clicked
 * -----------------------------------------------------------------
 * When add button is clicked check for valid inputs
 * for both name and price and if valid adds to the
 * current colleges souvenirs
 * -----------------------------------------------------------------
 * pre conditions:
 *  none
 * post conditions:
 *  Returns nothing, adds souvenir as long as valid
 ******************************************************************/
void Admin::on_addSouv_clicked()
{
   bool invalid = false; // Indicates if ready to be updated to database,
                         // means that all fields are entered and valid
                         // if false, and if true then will not update


   // Getting the id of the college being edited
   // and associating the current college to that id
   // and corresponding info
   QString selected = ui->collegeEdit->currentText();
   int id = selected.section(' ',0,0).toInt();

   // Get all colleges and correponding ids
   currentColleges = db->getAllColleges();
   currentIds = db->getAllIds();

   College current; // Object associated with current
                    // college selected

   // Loop through to find selected college
   for(int i : currentIds) {
       if(id == currentColleges.find(i).getID()) {
           current = currentColleges.find(i);
           break;
       }
   }

   // Checking for valid inputs
   // New name cannot be empty
   if(ui->addName->text() == "")
   {
       QMessageBox::critical(this,
                             "Editing Error",
                             "Please enter a valid name for new souvenir");
       invalid = true;
   }
   // New price cannot be 0
   else if(ui->addPrice->value() == 0)
   {
       QMessageBox::critical(this,
                             "Editing Error",
                             "Please enter a valid price for new souvenir");
       invalid = true;
   }
   // Means that both fields are valid and can be added
   else
   {
       // Souvs is never empty, will always have a min size of 1,
       // but if the first (and only) souvenir is invalid
       // (empty name and 0 price) then the souvs is empty and the
       // item to be added needs to replace that one, if this is
       // not the case then just have to add the souvenir
       // to the college like normal
       std::vector<Souvenir> currentSouvs = current.getSouvenirs();
       if(currentSouvs[0].name == "") {
            // Replacing first souvenir w/ new values and
            // resetting souvenirs of the restaurant
            currentSouvs[0].name  = ui->addName->text();
            currentSouvs[0].price = ui->addPrice->value();
            current.setSouvenirs(currentSouvs);
       } else {
           // Adding souv to college like normal
           // Create new souv object, set to new info and
           // add to souvenirs
           Souvenir newSouv;
           newSouv.name = ui->addName->text();
           newSouv.price = ui->addPrice->value();
           current.addSouvenir(newSouv);
         }
   }

   // Updating the college if all fields are valid
   if(!invalid) {
       if (db->updateCollege(id, current)) {
           QMessageBox::information(this, "Success", "Souvenir added!");

           // Now that college has changed need to update the editting fields
           setSouvEditFields(id);

           // Clearing add item fields if successfully updated
           ui->addName->clear();
           ui->addPrice->clear();
       } else {
           QMessageBox::critical(this, "Error", "An unkown error occured.");
       }
   }
}

/*******************************************************************
 * on_deleteSouv_clicked
 * -----------------------------------------------------------------
 * When delete button is clicked as long as there is
 * a selection to delete then deletes the seleced souvenir
 * from the delete dropdown menu
 * -----------------------------------------------------------------
 * pre conditions:
 *  none
 * post conditions:
 *  Returns nothing, deletes the selected souvenir
 ******************************************************************/
void Admin::on_deleteSouv_clicked()
{
   // If no msouvenirs then cannot delete anything
   if(ui->souvTable->rowCount() == 0) {
       QMessageBox::critical(this, "Error", "Cannot delete from an empty souvenirs.");
       return;
   }

   // Getting id of college being edited and associating
   // current college wiith the corresponding information
   QString text = ui->collegeEdit->currentText();
   int id = text.section(' ', 0, 0).toInt();

   // Get all colleges and corresponding ids
   currentColleges = db->getAllColleges();
   currentIds = db->getAllIds();

   College current; // Object associated with current
                    // college selected

   // Loop through to find selected college
   for(int i : currentIds) {
       if(id == currentColleges.find(i).getID()) {
           current = currentColleges.find(i);
           break;
       }
   }

   // Getting the souvenirs of the current college
   std::vector<Souvenir> currentSouvs = current.getSouvenirs();

   // Using an iterator to remove the selected item to delete
   // from the souv vector
   std::vector<Souvenir>::iterator souvIterator;
   QString deleteIdString = ui->deleteOptions->currentText();

   // subtracting 1 because did +1 so that count starts at 1 not 0 in dropdown menu
   int deleteId = deleteIdString.section(' ', 0, 0).toInt() - 1;
   souvIterator = currentSouvs.begin() + deleteId;

   // Erasing indicated souvs and resetting the souvs with the
   // updated values
   currentSouvs.erase(souvIterator);
   current.setSouvenirs(currentSouvs);

   // Updating the college to the database
   if (db->updateCollege(id, current)) {
       QMessageBox::information(this, "Success", "Souvenir deleted!");

       // Now that college has been updated need to update the editing fields
       setSouvEditFields(id);
   } else {
       QMessageBox::critical(this, "Error", "An unkown error occured.");
   }
}

/*******************************************************************
 * on_modifySouv_clicked
 * -----------------------------------------------------------------
 * When modify is selected goes through the edit table
 * to update the prices of the souvenirs as long as valid
 * prices are entered
 * -----------------------------------------------------------------
 * pre conditions:
 *  none
 * post conditions:
 *  Returns nothing, updates souvenir prices
 ******************************************************************/
void Admin::on_modifySouv_clicked()
{
   // If there are no rows in the table (empty souvs)
   // then there are no items to update so cannot continue
   if(ui->souvTable->rowCount() == 0)
   {
       QMessageBox::critical(this, "Error", "No souvenirs to update.");
       return;
   }

   // If at this point then there is at least 1 menu item
   // and can update it

   bool invalid = false; // indicates if ready to be updated to database,
                         // means that all fields are entered and valid
                         // if false, and if true then will not update

   // Getting the current id selected and associating
   // the current college with the proper id
   // to update souv information to
   QString text = ui->collegeEdit->currentText();
   int id = text.section(' ', 0, 0).toInt();

   // Get all colleges and corresponding ids
   currentColleges = db->getAllColleges();
   currentIds = db->getAllIds();

   College current; // Object associated with current
                    // college selected

   // Loop through to find selected college
   for(int i : currentIds) {
       if(id == currentColleges.find(i).getID()) {
           current = currentColleges.find(i);
           break;
       }
   }

   // For loop going through entire table and validating the input
   // and if valid then updating the current college
   for(int i = 0; i < ui->souvTable->rowCount(); ++i) {
       // Getting price information from the cell:
       // Getting widget from cell
       QWidget* souvTableCell = ui->souvTable->cellWidget(i,0);
       // cast widget to double spin box
       QDoubleSpinBox* tablePrices = static_cast<QDoubleSpinBox*>(souvTableCell);
       // get value of price from the table
       double newPrice = tablePrices->value();

       // need to include valid prices for all items
       if(newPrice == 0) {
           QMessageBox::critical(this,
                                 "Editing Error",
                                 "Please enter valid prices for all souvenirs");
           // If price is 0 then not ready to update
           invalid = true;
       } else {
           // Means that prices are valid so updating the
           // price of the corrsponding souv
           current.setSouvenirPrice(i, newPrice);
       }
   }

   // Taking the updated college object and updating the corresponding
   // college into the database
   if (!invalid) {
       // If valid updating college and checking for success
       if (db->updateCollege(id, current)) {
           QMessageBox::information(this, "Success", "Souvenirs updated!");

           // Update the editting fields now that college has been altered
           setSouvEditFields(id);
       } else {
           QMessageBox::critical(this, "Error", "An unkown error occured.");
       }
   }
}

/*******************************************************************
 * on_upload_clicked
 * -----------------------------------------------------------------
 * When upload is clicked checks for valid file names and
 * then reads and adds new colleges and souvenirs to the
 * database as long as successfully read
 * -----------------------------------------------------------------
 * pre conditions:
 *  none
 * post conditions:
 *  Returns nothing, adds additional colleges via file
 ******************************************************************/
void Admin::on_upload_clicked()
{
    // Need to have valid file names to uplaod
    if(ui->collegeUpload->text() == "" || ui->souvUpload->text() == "") {
        QMessageBox::critical(this, "Error", "Please enter both file names.");
        return;
    }

    CollegeHashMap newColleges; // Hashmap to hold the new colleges
    Parser         fileParser;  // Parser object to read the files

    // Get the names of the files (college and souvenir info) to be read
    std::string collegeFile = ui->collegeUpload->text().toStdString();
    std::string souvFile = ui->souvUpload->text().toStdString();

    // Get the existing ids and create a vector for the new ids used
    // for parser read call
    std::vector<int> newId;
    std::vector<int> existingId = db->getAllIds();

    // Read the files and check if success or not
    if(fileParser.read(newColleges, existingId, newId, collegeFile, souvFile)) {
        // Successfully read so need to loop through the new colleges
        // and update database
        for (int i : newId) {
            if(db->addCollege(newColleges.find(i))) {
                QMessageBox::information(this, "Success", newColleges.find(i).getName() + " added!");
                // Now that new colleges added need to update the dropdown college edit options
                setCollegeEditOptions();
            } else {
                QMessageBox::critical(this, "Error", "Unable to add.");
            }

            // If successful then clearing file name input
            ui->collegeUpload->clear();
            ui->souvUpload->clear();
        }
    }else {
        QMessageBox::critical(this, "Error", "Could not open the file");
    }
}

void Admin::on_collegeEdit_currentTextChanged(const QString &arg1)
{
   qInfo() << "test";
   // Get the id section from the dropdown selection
   QString selected = ui->collegeEdit->currentText();
   int id = selected.section(' ',0,0).toInt();

   // Set editing fields to that id
   setSouvEditFields(id);

   // Clear name and price fields now onto new college
   ui->addName->clear();
   ui->addPrice->clear();
}


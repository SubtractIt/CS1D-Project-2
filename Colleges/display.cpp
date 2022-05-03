#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    QString path;

    // Creating database connection
       #if __APPLE__ && TARGET_OS_MAC
             path = "../../../../Colleges/colleges.db";
       #elif __linux__
             path = "../Colleges/colleges.db";
       #else
             path = "..\Colleges\colleges.db";
       #endif

    //initializes database
    db = new DbManager(path);

    //populates college map with database helper function
    this->currentColleges = db->getAllColleges();
    this->currentIDs = db->getAllIds();
    ui->setupUi(this);

    //calling functions to populate combobox with all colleges and tracking
    fillComboBox();
    on_collegeListComboBox_currentTextChanged(selectedSchool);
}

Display::~Display()
{
    delete ui;
}

//opens new dialog modally when 'View All' button is clicked - fulfills requirement of listing out all colleges
void Display::on_viewAll_clicked()
{
    CollegeList list;
    list.setModal(true);
    list.exec();
}

//populates QComboBox for user to select which college they want to view specific information about
void Display::fillComboBox()
{

    //for each ID in the list of current ID's in the database...
    for (int i : currentIDs)
    {
        //finds the current iteration of ID and sets that to the current college
        College curr = currentColleges.find(i);

        //converts ID to a string and then QString so it can be modified
        std::string s_collegeID = std::to_string(curr.getID());
        QString collegeID = QString::fromStdString(s_collegeID);

        //receives name from college and combines it with ID to populate QComboBox with college name and ID
        QString collegeName = curr.getName();
        QString collegeInfo = collegeName + " ID: " + collegeID;
        ui->collegeListComboBox->addItem(collegeInfo);
    }

}

/*Displays undergraduate population and souvenirs for the respective college through
a QComboBox updater slot*/
void Display::on_collegeListComboBox_currentTextChanged(QString selectedSchool)
{

    //sets private member 'selectedSchool' to the current text in comboBox (QString)
    selectedSchool = ui->collegeListComboBox->currentText();
    qInfo() << selectedSchool;

    //converts to string, then parses string to find ID of the respective college
    std::string currSchool = selectedSchool.toStdString();
    std::size_t pos = currSchool.rfind(":");
    std::string substr = std::string(currSchool.begin() + pos + 1, currSchool.end());

    std::cout << "hello " << substr << std::endl;

    int currID = std::stoi(substr);

    qInfo() << currID;

    //uses find method in map to match up which college is being selected and places that in a new College object
    College currCollege = currentColleges.find(currID);

    //size = num of undergraduate students, s = that number but in QString format so it can be outputted and replace label text
    int size = currCollege.size();
    QString s = QString::number(size);
    qInfo() << s;

    //sets label to the number of undergraduate students
    ui->numUndergradDisplay->setText(s);

    //fills a vector of souvenirs
    std::vector<Souvenir> souvenirs = currCollege.getSouvenirs();



    //loops through and gets every souvenir each college provides
    for (int i = 0; i < souvenirs.size(); i++)
    {
        //tracks souvenir name and price, as well as the total number of souvenirs for the respective college selected
        QString currSouvName = souvenirs.at(i).name;
        float currSouvPrice = souvenirs.at(i).price;

            //converts price to QString in order to be placed in widget
            QString price_s = QString::number(currSouvPrice);

        int numSouvs = souvenirs.size();

        //sets rowCount to the number of souvenirs and column count to 2 (name & price)
        ui->souvenirTable->setRowCount(numSouvs);
        ui->souvenirTable->setColumnCount(2);

        //sets headers for table
        QStringList headers;
        QStringList null;
        null << " " << " " << " " << " " << " " << " ";
        headers << "Souvenir Name" << "Souvenir Price";
        ui->souvenirTable->setHorizontalHeaderLabels(headers);
        ui->souvenirTable->setVerticalHeaderLabels(null);
        ui->souvenirTable->horizontalHeader()->setStretchLastSection(true);

        //creates new QTableWidgetItems dynamically and sets their respective texts to the current souvenirs name and price
        QTableWidgetItem* souvName = new QTableWidgetItem;
        QTableWidgetItem* souvPrice = new QTableWidgetItem;
        souvName->setText(currSouvName);
        souvPrice->setText(price_s);


        //updates table with souvenir names
        ui->souvenirTable->setItem(i, 0, souvName);

        //updates table with souvenir prices
        ui->souvenirTable->setItem(i, 1, souvPrice);



        //for testing
        QString souvPrice_s = "";
        qInfo() << "Name: " + currSouvName + " Price: " + souvPrice_s.setNum(currSouvPrice);
    }
}


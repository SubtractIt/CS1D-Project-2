#include "collegelist.h"
#include "ui_collegelist.h"


CollegeList::CollegeList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CollegeList)
{
    QString path;

    #if APPLE && TARGET_OS_MAC
          path = "../../../../Colleges/colleges.db";
    #elif linux
          path = "../Colleges/colleges.db";
    #else
          path = "D:/Qt/PROJECT 2 CS1D/CS1D-Project-2/Colleges/colleges.db";
    #endif

    //initializes database
    db = new DbManager(path);

    //populates college map with database helper function
    this->currentColleges = db->getAllColleges();
    this->currentIDs = db->getAllIds();
    ui->setupUi(this);

    //calls functions
    fillListView();
    fillCaliforniaList();
    fillUndergradList();
    fillListStateName();

}


//fills list of colleges (displays all colleges)
void CollegeList::fillListView()
{
    //currentColleges.print();
    std::vector<QString> collegeListNormal;

    for (int i : currentIDs)
    {
        //finds the current iteration of ID and sets that to the current college
        College curr = currentColleges.find(i);

        //converts ID to a string and then QString so it can be modified
        std::string s_collegeID = std::to_string(curr.getID());
        QString collegeID = QString::fromStdString(s_collegeID);

        //receives name from college and combines it with ID to populate QComboBox with college name and ID
        QString collegeName = curr.getName();
        QString collegeInfo = collegeName;

        //adds college name and ID into vector
        collegeListNormal.push_back(collegeInfo);
    }

    std::sort(collegeListNormal.begin(), collegeListNormal.end());

    for (int i = 0; i < collegeListNormal.size(); i++)
    {
        ui->collegeList->addItem(collegeListNormal.at(i));
    }
}

//fills list of California colleges
void CollegeList::fillCaliforniaList()
{
    //vector of only California colleges
    std::vector<QString> californiaColleges;

    for (int i : currentIDs)
    {
        //finds current iteration of ID and sets that to the current college
        College curr = currentColleges.find(i);

        //converts ID to a string and then QString so it can be modified
        std::string s_collegeID = std::to_string(curr.getID());
        QString collegeID = QString::fromStdString(s_collegeID);

        //recieves name from colleges and combines with ID to populate QListWidget contexts with college name and ID
        QString collegeName = curr.getName();
        QString collegeInfo = collegeName;

       // qInfo() << "TESTING STATE OF COLLEGE CUZ IDK THE NAMING CONVENTIONS" << curr.getState();

        //checks if current college's state is California, and only then pushes it back into the vector
        //or statement used because some colleges have their state as "California" and others as " California"
        if(curr.getState() == "California" || curr.getState() == " California")
        {
            californiaColleges.push_back(collegeInfo);
        }
        else
        {
            qInfo() << "College is not in California. Not added to QListWidget";
        }

    }

    std::sort(californiaColleges.begin(), californiaColleges.end());

    //adds every element of the vector into the QListWidget
    for (int i = 0; i < californiaColleges.size(); i++)
    {
        qInfo() << californiaColleges.at(i);
        ui->californiaList->addItem(californiaColleges.at(i));
    }
}

void CollegeList::fillUndergradList()
{
    //vector of colleges
    std::vector<QString> undergradColleges;

    ui->undergradTable->setRowCount(12);
    ui->undergradTable->setColumnCount(2);
    QStringList headers;
    QStringList null;
    null << " " << " " << " " << " " << " " << " ";
    headers << "College Name" << "Undergraduate Population";
    ui->undergradTable->setHorizontalHeaderLabels(headers);
    ui->undergradTable->setVerticalHeaderLabels(null);
    ui->undergradTable->horizontalHeader()->setStretchLastSection(true);

    for (int i : currentIDs)
    {
        //finds current iteration of ID and sets that to the current college
        College curr = currentColleges.find(i);

        //converts ID to a string and then QString so it can be modified
        std::string s_collegeID = std::to_string(curr.getID());
        QString collegeID = QString::fromStdString(s_collegeID);
        int undergraduatePopulation = curr.size();
        QString undergradNum_s = QString::number(undergraduatePopulation);

        //recieves name from colleges and combines with ID to populate QListWidget contexts with college name and ID
        QString collegeName = curr.getName();
        QString collegeInfo = collegeName + " ID: " + collegeID + "\t\tUndergraduate Population: " + undergradNum_s;

        //populates QTable with college names and undergraduate populations
        QTableWidgetItem* collegeNameTable = new QTableWidgetItem;
        QTableWidgetItem* undergradPopulation = new QTableWidgetItem;

        collegeNameTable->setText(collegeName);
        undergradPopulation->setText(undergradNum_s);

        ui->undergradTable->setItem(i, 0, collegeNameTable);
        ui->undergradTable->setItem(i, 1, undergradPopulation);


        undergradColleges.push_back(collegeInfo);

    }
}

//fills college list sorted by state and then college name
void CollegeList::fillListStateName()
{
    std::unordered_map<QString, std::vector<QString>> collegesByState;
    std::vector<QString> allStates;

    for (int id : currentIDs)
    {
        College curr = currentColleges.find(id);

        if(std::find(allStates.begin(), allStates.end(), curr.getName()) != allStates.end())
        {
            allStates.push_back(curr.getState());

            std::vector<QString> states;

            collegesByState.insert(std::pair<QString, std::vector<QString>>(curr.getState(), states));
        }

        collegesByState[curr.getState()].push_back(curr.getName());

    }

    for (QString state : allStates)
    {
        qInfo() << "STATE : " << state;

        std::vector<QString> names = collegesByState[state];
        std::sort(names.begin(), names.end());

        for (QString college : names)
        {
            ui->statesWidget->addItem(college);
        }
    }
}



CollegeList::~CollegeList()
{
    delete ui;
}

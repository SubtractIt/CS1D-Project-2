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



}

bool compareHelper(std::string a, std::string b)
{
    return a < b;
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
        QString collegeInfo = collegeName + " ID: " + collegeID;

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
        QString collegeInfo = collegeName + " ID: " + collegeID;

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
    //vector of only California colleges
    std::vector<QString> undergradColleges;

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
        QString collegeInfo = collegeName + " ID: " + collegeID + " Undergraduate Population: " + undergradNum_s;


        undergradColleges.push_back(collegeInfo);

    }

    std::sort(undergradColleges.begin(), undergradColleges.end());

    //adds every element of the vector into the QListWidget
    for (int i = 0; i < undergradColleges.size(); i++)
    {
        qInfo() << undergradColleges.at(i);
        ui->undergradList->addItem(undergradColleges.at(i));
    }
}



















CollegeList::~CollegeList()
{
    delete ui;
}

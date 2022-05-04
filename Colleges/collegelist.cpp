#include "collegelist.h"
#include "ui_collegelist.h"


CollegeList::CollegeList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CollegeList)
{
    QString path;

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

    //init graph
    graph.addColleges(currentColleges, currentIDs);

    //calls functions
    fillListView();
    fillCaliforniaList();
    fillUndergradList();
    fillListStateName();
    fillSaddlebackDistanceList();
    printBFS();
    printDFS();
    printMST();

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
    null << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " ";
    headers << "College Name" << "Undergraduate Population";
    ui->undergradTable->setHorizontalHeaderLabels(headers);
    ui->undergradTable->setVerticalHeaderLabels(null);
    ui->undergradTable->horizontalHeader()->setStretchLastSection(true);

    ui->undergradTable->setColumnWidth(0, 400);
    ui->undergradTable->setColumnWidth(1, 400);

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
    std::unordered_map<std::string, std::vector<QString>> collegesByState;
    std::vector<QString> allStates;

    for (int id : currentIDs)
    {
        qInfo() << "Id : " << id;

        College curr = currentColleges.find(id);

        if(std::find(allStates.begin(), allStates.end(), curr.getState()) == allStates.end())
        {
            allStates.push_back(curr.getState());

            std::vector<QString> states;

            collegesByState.insert(std::pair<std::string, std::vector<QString>>(curr.getState().toStdString(), states));
        }

        collegesByState[curr.getState().toStdString()].push_back(curr.getName());

    }

    qInfo() << "hi" << allStates.size();

    std::sort(allStates.begin(), allStates.end());

    for (QString state : allStates)
    {
        qInfo() << "STATE : " << state;

        std::vector<QString> names = collegesByState[state.toStdString()];
        std::sort(names.begin(), names.end());

        ui->statesWidget->addItem(state + " Colleges:");

        for (QString college : names)
        {
            ui->statesWidget->addItem("\t" + college);
        }
    }
}

void CollegeList::fillSaddlebackDistanceList(){

    QTableWidget* table = this->ui->saddlebackTable;
    table->setRowCount(currentColleges.size());
    table->setColumnCount(2);

    table->setColumnWidth(0, 400);
    table->setColumnWidth(1, 400);

    QStringList headers;
    QStringList null;
    null << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " ";
    headers << "College Name" << "Undergraduate Population";
    ui->undergradTable->setHorizontalHeaderLabels(headers);
    ui->undergradTable->setVerticalHeaderLabels(null);


    for (int i : currentIDs)
    {
        College curr = currentColleges.find(i);

         QTableWidgetItem* collegeNameTable = new QTableWidgetItem;
         QTableWidgetItem* saddlebackDist = new QTableWidgetItem;

         collegeNameTable->setText(curr.getName());
         saddlebackDist->setText(QString::number(curr.getDistances()[5]));


        ui->saddlebackTable->setItem(i - 1, 0, collegeNameTable);
        ui->saddlebackTable->setItem(i - 1, 1, saddlebackDist);

    }

}

void CollegeList::printBFS() {

    std::vector<int> path;
    std::vector<float> distances;

    graph.bfs(1, path, distances);

    float sum = 0;

    for(int i = 0; i < distances.size(); i++){
        sum += distances[i];
    }

    QString distance = QString::number(sum);
    ui->milageLabel->setText(distance);

    std::vector<QString> colleges;

    for (int id : path)
    {
        College curr = currentColleges.find(id);
        QString name = curr.getName();
        ui->bfsList->addItem(name);
    }
}

void CollegeList::printDFS() {

    int id = 7;
    float sum = 0;

    std::vector<int> path;
    std::vector<float> distances;

    graph.dfs(id, path, distances);

    for(int i = 0; i < distances.size(); i++){
        sum += distances[i];
    }

    QString distance = QString::number(sum);
    ui->milageLabel_2->setText(distance);

    std::vector<QString> colleges;

    for (int id : path)
    {
        College curr = currentColleges.find(id);
        QString name = curr.getName();
        ui->dfsList->addItem(name);
    }
}

void CollegeList::printMST(){
    std::unordered_map<int, int> map;
    float totalDist;
    graph.mst(map, totalDist);



    for (const auto& i : map){
        College start = currentColleges.find(i.first);
        College end = currentColleges.find(i.second);


        QString first = start.getName();
        QString second = end.getName();

        QString add = first + " - " + second;
        ui->mstWidget->addItem(add);
    }

    QString totalDistance = QString::number(totalDist);
    ui->milageLabel_3->setText(totalDistance);


}



CollegeList::~CollegeList()
{
    delete ui;
}

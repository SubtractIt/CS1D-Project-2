#ifndef COLLEGELIST_H
#define COLLEGELIST_H

#include <iostream>
#include <QDialog>
#include <QFile>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "college.h"
#include "dbmanager.h"
#include "collegehashmap.h"
#include "graph.h"

namespace Ui {
class CollegeList;
}

class CollegeList : public QDialog
{
    Q_OBJECT

public:
    explicit CollegeList(QWidget *parent = nullptr);
    void fillListView();
    void fillCaliforniaList();
    void fillUndergradList();
    void fillListStateName(); // just lovely naming conventions here
    void fillSaddlebackDistanceList();
    void printDFS();
    void printBFS();
    void printMST();
    ~CollegeList();

private:
    Ui::CollegeList *ui;
    DbManager* db;
    std::vector<int> currentIDs;
    CollegeHashMap currentColleges;
    WeightedGraph graph;
};

#endif // COLLEGELIST_H

///
/// @author Adit Mohindra
/// @file   collegelist.h

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

/// @brief CollegeList class - class to display all college listings sorted
///
class CollegeList : public QDialog
{
    Q_OBJECT

public:

    ///
    /// @brief CollegeList constructor - initializes list of colleges
    /// @param QWidget parent
    ///
    explicit CollegeList(QWidget *parent = nullptr);

    ///
    /// @brief Fills the normal list view of the college
    ///
    void fillListView();

    ///
    /// @brief Fills the list view with California colleges
    ///
    void fillCaliforniaList();

    ///
    /// @brief Fills the list view with the colleges and undergraduate students
    ///
    void fillUndergradList();

    ///
    /// @brief Fills the list view with colleges sorted by state and name
    ///
    void fillListStateName();

    ///
    /// @brief Fills the list view with colleges and their distance to Saddleback College
    ///
    void fillSaddlebackDistanceList();

    ///
    /// @brief Prints the results of a Depth First Search conducted on the colleges graph
    ///
    void printDFS();

    ///
    /// @brief Prints the results of a Breadth First Search conducted on the colleges graph
    ///
    void printBFS();

    ///
    /// @brief Prints the results of the Minimum Spanning Tree of the colleges graph
    ///
    void printMST();

    ///
    /// @brief Destructor of CollegeList class
    ///
    ~CollegeList();

private:
    Ui::CollegeList *ui;
    DbManager* db;
    std::vector<int> currentIDs;
    CollegeHashMap currentColleges;
    WeightedGraph graph;
};

#endif // COLLEGELIST_H

///
/// @author Juliette Raubolt
/// @file  parser.h
///
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <exception>
#include <QString>
#include <QFile>
#include <QStringList>
#include <QDebug>

// Dummy structs
struct souvenir {
    QString name;
    float price;
};
struct placeHold {
    placeHold() {reinitialize();}
    QString name;
    QString state;
    int underGrads;
    std::unordered_map<std::string, float> distances;
    std::vector<souvenir> souvenirs;

    void print() {
        qDebug() << "College Info: \n";
        qDebug() << "Name: " << name  << "\n";
        qDebug() << "State: " << state << "\n";
        qDebug() << "Undergrads: " << underGrads << "\n";

//        for(int i = 1; i <= distances.size(); ++i) {
//            qDebug() << distances[i] << "miles \n";
//        }
        for (auto i : distances)
              qDebug() << QString::fromStdString(i.first) << ": " << i.second << "miles \n";

        for(size_t i = 0; i < souvenirs.size(); ++i) {
            qDebug() << souvenirs[i].name << ": $" << souvenirs[i].price << "\n";
        }

    }
    void reinitialize () {
        name = "";
        state = "";
        underGrads = 0;
        distances.clear();
        souvenirs.clear();
    }
};



///
/// @brief   The Parser class, parses csv to college objects
/// @details Used to parse csv files about colleges and souvenirs
///          into objects with default being the initial
///
class Parser
{
public:

    ///
    /// @brief  Empty parser constructor
    ///
    Parser();

    ///
    /// @brief Empty parser destructor
    ///
    ~Parser();

    ///
    /// @brief   College and souvenir parser
    /// @details Takes in two files of colleges and souvenirs which have default
    ///          values to the names of the initial value files. The method reads
    ///          the college and souvenir by college meaning the inital college
    ///          info is read, then the program loops to read all distance info
    ///          for that school. The souvenirs for that specific restaurant
    ///          will then be read until the next college is reached. The method
    ///          will return false if a file cannot be opened and true if the
    ///          entire file is read.
    /// @returns bool indicating success of parsing
    /// @param   colleges file name to parse for college info, default = "college"
    /// @param   souvs    file name to parse for souvenir info, default = "souvenir"
    ///
    bool read(std::string colleges = "college", std::string souvs = "souvenir");

};

#endif // PARSER_H

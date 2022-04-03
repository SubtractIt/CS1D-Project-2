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
#include "collegehashmap.h"
#include "college.h"
#include "dbmanager.h"

///
/// @brief   The Parser class, parses csv to college objects
/// @details Used to parse csv files about colleges and souvenirs
///          into objects with default being the initial
///
class Parser
{
public:

    ///
    /// @brief  Parser constructor initializes db pointer
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
    bool read(CollegeHashMap& collegeTrain, std::string colleges = "college", std::string souvs = "souvenir");

private:
    DbManager* db;

    ///
    /// @brief   Gets the proper Id for the college
    /// @details Starts at 1 over the size of the map passed passed in
    ///          checks if it is unused, increments if used, returns if not
    /// @param   CollegeHashMap to be added to
    /// @return  an unused id
    ///
    int getId(CollegeHashMap& collegeTrain);
};

#endif // PARSER_H

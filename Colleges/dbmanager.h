#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlQuery>
#include <QString>
#include <QtSql>
#include "collegehashmap.h"

// colleges table schema
//  id INTEGER NOT NULL
//  name TEXT NOT NULL
//  state TEXT NOT NULL
//  souvenirs TEXT NOT NULL
//  distances TEXT NOT NULL
//  num_students INTEGER NOT NULL

#define NUM_COLUMNS 6

class DbManager {
private:
    QSqlDatabase dataBase;

    College getCollegeFromRecord(const QSqlRecord &rec) const;
    QString getSouvenirsString(const std::vector<Souvenir>& souvenirs) const;
    QString getDistancesString(const float distanceFromSaddleback,
                               const std::unordered_map<int, float>&
                               distances) const;

public:
    ///
    /// @brief constructor - opens a connection to the database specified by the
    /// path
    /// @param path path to the database file
    ///
    DbManager(const QString &path);
    ///
    /// @brief destructor - closes the connection to the database
    ///
    ~DbManager();

    ///
    /// @brief Updates the college with the specified id in the database with
    /// the passed college
    /// @param id int
    /// @param college college
    /// @return true if college was succesfully updated, false otherwise
    ///
    bool updateCollege(const int id, const College& college);

    ///
    /// @brief Adds a new College to the database
    /// @param college the new college
    /// @return true if college was successfully added, false otherwise
    ///
    bool addCollege(const College &college);

    ///
    /// @brief Deletes the college with the given id from the database
    /// @param id the college's id
    /// @return true if deleted, false if college didn't exist
    ///
    bool deleteCollegeById(const int id);

    ///
    /// @brief Deletes all colleges from the database
    ///
    void deleteAllColleges();

    ///
    /// @brief Returns a CollegeHashMap of all colleges in the database
    /// @return CollegeHashMap of all colleges
    ///
    CollegeHashMap getAllColleges() const;

    ///
    /// @brief Returns all ids in use in the databse for indexing into the hash
    /// table
    /// @return a vector of all ids (int)
    ///
    std::vector<int> getAllIds() const;

    ///
    /// @brief Checks if the specified id is already in use in the database
    /// @param id
    /// @return true if id is not use, false otherwise
    ///
    bool isUnusedId(const int id) const;

    ///
    /// @brief Prints all Colleges in the database (as database stores info)
    ///
    void print() const;
};

#endif // DBMANAGER_H

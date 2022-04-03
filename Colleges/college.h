#ifndef COLLEGE_H
#define COLLEGE_H

#include <QObject>
#include <iostream>

#define MAX_SOUVENIR_ITEMS 7

struct Souvenir {
    QString name;
    float price;
};

///
/// @brief The College class -- Encapsulates all the data of a college, with various helper methods.
///
class College
{
public:

    ///
    /// @brief constructor
    ///
    College();

    //Accesors

    ///
    /// @brief Finds the distance to a college specified
    /// @param id of College we are trying to find the distance to
    /// @return a double representing the distance from the calling college to the college passed in
    /// ///
    std::map<int, float> getDistances() const { return distances; }

    ///
    /// @brief getName()
    /// @return QString name of the college
    ///
    QString getName() const { return name; }

    ///
    /// @brief getState()
    /// @return QString name of the state the college is in
    ///
    QString getState() const { return state; }

    ///
    /// @brief getID()
    /// @return int of the college ID
    ///
    int getID() const { return id; }

    ///
    /// @brief size()
    /// @return int of the number of undergraduates in the college
    ///
    int size() const { return numUndergraduates; }

    //Mutators
    ///
    /// @brief Reinitializes the restaurant to an empty state
    ///
    void reInitialize();

    ///
    /// @brief Adds a new souvenir to the college
    /// @param New souvenir object to add
    ///
    void addSouvenir(const Souvenir &souvenir);

    ///
    /// @brief Redefines the name of the college
    /// @param QString of the new name
    ///
    void setName(const QString &name);

    ///
    /// @brief Redefines the college ID
    /// @param int of the new ID
    ///
    void setID(int id);

    ///
    /// @brief Redefines the college state
    /// @param QString of the new state name
    ///
    void setState(const QString &state);

    ///
    /// @brief Adds or changes a distance to a college into the distances map
    /// @param College we are trying to add a distance to
    /// @param distance of the current college to the new college
    ///
    void setDistance(int id, float distance);


private:
    QString name;
    int id;
    QString state;
    int numUndergraduates;
    std::map<int, float> distances;
    std::vector<Souvenir> souvenirs;
};

#endif // COLLEGE_H

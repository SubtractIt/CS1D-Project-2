///
/// @author Christopher Schrader, Ethan Safai
/// @file   college.h
///
#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>
#include <QString>
#include <unordered_map>
#include <vector>

#define MAX_SOUVENIR_ITEMS 7

// Represents a souvenir from the college with a name and price
struct Souvenir {
    QString name;
    float price;
};

///
/// @brief The College class -- Encapsulates all the data of a college, with
///        various helper methods.
///
class College {
public:
    ///
    /// @brief empty constructor
    ///
    College() {}
    ///
    /// @brief empty destructor
    ///
    ~College() {}

    //Accesors

    ///
    /// @brief  Finds the distance to a college specified
    /// @param  id of College we are trying to find the distance to
    /// @return a double representing the distance from the calling college to
    ///         the college passed in
    ///
    std::unordered_map<int, float> getDistances() const { return distances; }

    ///
    /// @brief  Returns vector of college's souvenirs
    /// @return college's souvenirs
    ///
    std::vector<Souvenir> getSouvenirs() const { return souvenirs; }

    ///
    /// @brief  Returns the college's name
    /// @return QString name of the college
    ///
    QString getName() const { return name; }

    ///
    /// @brief  Returns the college's state
    /// @return QString name of the state the college is in
    ///
    QString getState() const { return state; }

    ///
    /// @brief  Returns the college's id
    /// @return int of the college ID
    ///
    int getID() const { return id; }

    ///
    /// @brief  size()
    /// @return int of the number of undergraduates in the college
    ///
    int size() const { return numUndergraduates; }

    // Mutators

    ///
    /// @brief Reinitializes the restaurant to an empty state
    ///
    void reInitialize();

    ///
    /// \brief Renitilizes the souvenirs vector to the vector passed in
    /// \param Updated vector of souvenirs
    ///
    void setSouvenirs(std::vector<Souvenir> updatedSouvenirs);

    ///
    /// \brief Sets a new souvenir price for the souvenir at the passed in index
    /// \param Index of the souvenir in our souvenirs vector
    /// \param The new price of the souvenir we're updating
    ///
    void setSouvenirPrice(const int index, int newPrice);

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

    ///
    /// @brief Removes distance from college with given id
    /// @param other college's id
    ///
    void removeDistance(int id);

    ///
    /// @brief Sets the number of undergraduates at the college
    /// @param number of undergrads
    ///
    void setSize(int numUndergraduates);

    ///
    /// @brief Prints the details of this college
    ///
    void print() const;


private:
    QString name;
    int id;
    QString state;
    int numUndergraduates;
    std::unordered_map<int, float> distances;
    std::vector<Souvenir> souvenirs;
};

#endif // COLLEGE_H

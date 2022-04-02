#ifndef COLLEGEMAP_H
#define COLLEGEMAP_H

#include <iostream>
#include <list>
#include <QString>
#include <vector>
#include <unordered_map>

#define NUM_BUCKETS 20

// example souvenir item
struct SouvenirItem {
    QString name;
    float price;
};

// example of college object properties
struct College {
    int id;
    QString name;
    QString state;
    std::vector<SouvenirItem> souvenirs;
    std::unordered_map<int, float> distances;
    float distanceFromSaddleback;
    int numStudents;

    void print() const {
        std::cout << "id " << id << '\n';
        std::cout << "name " << name.toStdString() << '\n';
        std::cout << "state " << state.toStdString() << '\n';
        std::cout << "souvenirs:\n";
        for (const auto& s : souvenirs) {
            std::cout << s.name.toStdString() << ", $" << s.price << ' ';
        }
        std::cout << '\n';
        std::cout << "distances:\n";
        for (const auto& d : distances) {
            std::cout << "distance from restaurant " << d.first << ": "
                      << d.second << '\n';
        }
        std::cout << "distance from Saddleback: " << distanceFromSaddleback
                  << '\n';
        std::cout << "number of students: " << numStudents << '\n';
    }
};

struct CollegeWrapper {
    int id;
    College college;

    CollegeWrapper(int id, const College &college) : id(id), college(college) {}
};

///
/// @brief The CollegeHashMap class - uses a hash table to store College objects
///
class CollegeHashMap {
private:
    int count;
    std::list<CollegeWrapper> *table;

    int hash(const int key) const;

public:
    ///
    /// @brief Constructor
    /// Initializes the table array
    ///
    CollegeHashMap();
    ///
    /// @brief Destructor
    /// Deallocates space used by the table array
    ///
    ~CollegeHashMap();

    ///
    /// @brief Inserts a new College into the table so long as the id is unique
    /// @param key college's unique identifier
    /// @param college the College object
    ///
    void insert(const int key, const College &college);

    ///
    /// @brief Erases a College from the hash table if its key is found
    /// @param key college's unique identifier
    ///
    void erase(const int key);

    ///
    /// @brief Finds a College in the hash table given its key
    /// @param key college's unique identifier
    /// @return an iterator pointing to the College with the given key, the
    /// iterator will point to a College with a key of -1 if the key is not
    /// found
    ///
    std::list<CollegeWrapper>::iterator find(const int key) const;

    ///
    /// @brief Returns the number of Colleges in the hash table
    /// @return hash table's size
    ///
    int size() const;

    ///
    /// @brief Returns whether or not the hash table contains any Colleges
    /// @return true if empty
    ///
    bool isEmpty() const;

    ///
    /// @brief Prints all existing elements in the hash table
    ///
    void print() const;
};

#endif // COLLEGEMAP_H

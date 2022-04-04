///
/// @author Ethan Safai
/// @file   collegehashmap.h
#ifndef COLLEGEMAP_H
#define COLLEGEMAP_H

#include <list>
#include "college.h"

#define NUM_BUCKETS 20

// Wraps the College class so we can store the insert key along with the object
// in the hash table
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
    std::list<CollegeWrapper> table[NUM_BUCKETS];

    int hash(const int key) const;

    std::list<CollegeWrapper>::iterator findIter(int id);

public:
    ///
    /// @brief Constructor - initializes the table array
    ///
    CollegeHashMap();
    ///
    /// @brief Destructor - deallocates space used by the table array
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
    /// @brief  Finds a College in the hash table given its key
    /// @param  key college's unique identifier
    /// @return the college found, will have id -1 if not found
    ///
    College find(const int key) const;

    ///
    /// @brief  Returns the number of Colleges in the hash table
    /// @return hash table's size
    ///
    int size() const;

    ///
    /// @brief  Returns whether or not the hash table contains any Colleges
    /// @return true if empty
    ///
    bool isEmpty() const;

    ///
    /// @brief Prints all existing elements in the hash table
    ///
    void print() const;
};

#endif // COLLEGEMAP_H

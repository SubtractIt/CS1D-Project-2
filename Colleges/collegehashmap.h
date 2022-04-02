#ifndef COLLEGEMAP_H
#define COLLEGEMAP_H

#include <iostream>
#include <list>
#include <string>

struct CollegeWrapper {
    int key; // need to store the key with the object

    // A college object would go here in this struct's constructor:
    /*
     * College college;
     *
     * CollegeWrapper(const College& college)
     *  college(college) {
     * }
    */

    // These fields will go away once the College class is done, this is just
    // for testing purposes for now
    std::string name;
    std::string state;
    int numStudents;
};

#define NUM_BUCKETS 20

///
/// \brief The CollegeHashMap class - uses a hash table to store College objects
///
class CollegeHashMap {
private:
    int count;
    std::list<CollegeWrapper> *table;

    int hash(const int key) const;

public:
    ///
    /// \brief Constructor
    /// Initializes the table array
    ///
    CollegeHashMap();
    ///
    /// \brief Destructor
    /// Deallocates space used by the table array
    ///
    ~CollegeHashMap();

    ///
    /// \brief Inserts a new College into the table so long as the key is unique
    /// \param key college's unique identifier
    /// \param college the College object
    ///
    void insert(const int key, const CollegeWrapper &college);
    // NOTE: CollegeWrapper will become College once that class is done, i.e.
    // CollegeWrapper(key, college) will be inserted

    ///
    /// \brief Erases a College from the hash table if its key is found
    /// \param key college's unique identifier
    ///
    void erase(const int key);

    ///
    /// \brief Finds a College in the hash table given its key
    /// \param key college's unique identifier
    /// \return an iterator pointing to the College with the given key, the
    /// iterator will point to a College with a key of -1 if the key is not
    /// found
    ///
    std::list<CollegeWrapper>::iterator find(const int key) const;

    ///
    /// \brief Returns the number of Colleges in the hash table
    /// \return hash table's size
    ///
    int size() const;

    ///
    /// \brief Returns whether or not the hash table contains any Colleges
    /// \return true if empty
    ///
    bool isEmpty() const;

    ///
    /// \brief Prints all existing elements in the hash table
    ///
    void print() const;
};

#endif // COLLEGEMAP_H

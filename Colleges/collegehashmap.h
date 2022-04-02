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

class CollegeHashMap {
private:
    int count;
    std::list<CollegeWrapper> *table;

    int hash(const int key) const;

public:
    CollegeHashMap();
    ~CollegeHashMap();

    void insert(const int key, const CollegeWrapper &college);
    void erase(const int key);

    std::list<CollegeWrapper>::iterator find(const int key) const;
    int size() const;
    bool isEmpty() const;
    void print() const;
};

#endif // COLLEGEMAP_H

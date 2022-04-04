///
/// @author Ethan Safai
/// @file   collegehashmap.cpp
///
#include "collegehashmap.h"

CollegeHashMap::CollegeHashMap() : count(0) {}

CollegeHashMap::~CollegeHashMap() {}

void CollegeHashMap::insert(const int key, const College &college) {
  int index = hash(key);

  // no duplicates in a map, make sure key was not found
  if (find(key).getID() == -1) {
    table[index].push_back(CollegeWrapper(key, college));
    ++count;
  }
}

void CollegeHashMap::erase(const int key) {
  int index = hash(key);
  auto it = findIter(key);

  if (it->college.getID() != -1) {
      table[index].erase(it);
      --count;
  }
}

College CollegeHashMap::find(const int key) const {
    int index = hash(key);
    auto iter = table[index].begin();

    for (; iter != table[index].end(); ++iter) {
        if (iter->id == key) {
            break;
        }
    } 

    if (iter != table[index].end()) {
        return iter->college;
    }
    College empty;
    empty.setID(-1);
    return empty;
}

// private method
std::list<CollegeWrapper>::iterator CollegeHashMap::findIter(int id) {
    int index = hash(id);
    std::list<CollegeWrapper>::iterator iter = table[index].begin();

    for (; iter != table[index].end(); ++iter) {
        if (iter->id == id) {
            break;
        }
    }

    if (iter != table[index].end()) {
        return iter;
    }

    College empty;
    empty.setID(-1);
    table[index].push_back(CollegeWrapper(-1, empty));
    return iter;
}

int CollegeHashMap::size() const {
    return count;
}

bool CollegeHashMap::isEmpty() const {
    return count == 0;
}

void CollegeHashMap::print() const {
  for (int i = 0; i < NUM_BUCKETS; ++i) {
    std::cout << "Bucket " << i << ": ";
    for (auto it = table[i].begin(); it != table[i].end(); ++it) {
        std::cout << it->id << " " << it->college.getName().toStdString() << " ";
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

// PRIVATE MEMBER FUNCTION

int CollegeHashMap::hash(const int key) const {
  return (key % NUM_BUCKETS);
}

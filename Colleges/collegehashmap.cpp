#include "collegehashmap.h"

CollegeHashMap::CollegeHashMap()
    : count(0)
    , table(new std::list<CollegeWrapper>[NUM_BUCKETS]) {
}

CollegeHashMap::~CollegeHashMap() {
    delete[] table;
}

void CollegeHashMap::insert(const int key, const College &college) {
  int index = hash(key);

  // no duplicates in a map, make sure key was not found
  if (find(key) == table[index].end()) {
    table[index].push_back(CollegeWrapper(key, college));
    ++count;
  }
}

void CollegeHashMap::erase(const int key) {
  int index = hash(key);
  std::list<CollegeWrapper>::iterator it = find(key);

  if (it != table[index].end()) {
      table[index].erase(it);
      --count;
  }
}

std::list<CollegeWrapper>::iterator CollegeHashMap::find(const int key) const {
    int index = hash(key);

    std::list<CollegeWrapper>::iterator it;

    for (it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->id == key) {
            break;
        }
    }

    return it;
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

#include "college.h"

College::College() {
    //Not sure if we need this default constructor, we might be able to remove it

}

College::College(QString name, int id, QString state, int numUndergraduates, std::map<int, double> distances, std::vector<Souvenir> souvenirs) :
    name{name}, id{id}, state{state}, numUndergraduates{numUndergraduates}, distances{distances}, souvenirs{souvenirs} {

};

double College::distanceTo(College otherCollege){
    return this->distances[otherCollege.getID()];
}


//Mutators
void College::addSouvenir(Souvenir souvenir){
    bool found = false;
    for (auto i = souvenirs.begin(); i != souvenirs.end(); i++){
        if (i->name == souvenir.name){
            found = true;
        }
    }

    //Inserts new souvenir into the souvenirs vector if the name is not already found
    if (found == false){
      this->souvenirs.push_back(souvenir);
    }
}

void College::setName(QString name){
    this->name = name;
}

void College::setID(int id){
    this->id = id;
}

void College::setState(QString state){
    this->state = state;
}

void College::addDistance(College college, double distance){
    int id = college.getID();
    if (this->distances.find(id) == this->distances.end()){
        //College isn't already in the map, we can add it
        this->distances.insert(std::pair<int, double>(id, distance));
    }
}

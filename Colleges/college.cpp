#include "college.h"

void College::reInitialize() {
    this->id = -1;
    this->name = "";
    this->state = "";
    souvenirs.clear();
    distances.clear();
    this->numUndergraduates = -1;
}

//Mutators
void College::addSouvenir(const Souvenir &souvenir){
    bool found = false;
    for (auto i = souvenirs.begin(); i != souvenirs.end(); i++){
        if (i->name == souvenir.name){
            std::cout << "Souvenir already exists.\n";
            found = true;
        }
    }

    //Inserts new souvenir into the souvenirs vector if the name is not already found
    if (found == false){
        if (souvenirs.size() < MAX_SOUVENIR_ITEMS) {
            this->souvenirs.push_back(souvenir);
        } else {
            std::cout << "Max number of souvenirs already reached.\n";
        }
    }
}

void College::setName(const QString &name){
    this->name = name;
}

void College::setID(int id){
    this->id = id;
}

void College::setState(const QString &state){
    this->state = state;
}

void College::setDistance(int id, float distance){
   distances[id] = distance;
}

void College::setDistanceFromSaddleback(int distance) {
    this->distanceFromSaddleback = distance;
}

void College::setSize(int numUndergraduates) {
    this->numUndergraduates = numUndergraduates;
}

void College::print() const {
    // id, name, state, souvenirs, distances, numUndergrads
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name.toStdString() << '\n';
    std::cout << "Souvenirs:\n";
    for (size_t i = 0; i < souvenirs.size(); ++i) {
        std::cout << souvenirs[i].name.toStdString() << ": $" << souvenirs[i].price << ' ';
    }
    std::cout << '\n';
    std::cout << "Distance from Saddleback: " << this->distanceFromSaddleback << '\n';
    for (const auto& d : distances) {
        std::cout << "Distance from college " << d.first << ": " << d.second << '\n';
    }
    std::cout << "Number of undergrads: " << this->numUndergraduates << '\n';
}

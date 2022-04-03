#include "dbmanager.h"

DbManager::DbManager(const QString &path) {
    parser = new Parser;

    // Give the database object a name and a path to the .db file
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(path);

    // Check that the database connection was succesfully opened
    if (!dataBase.open()) {
      std::cerr << "Error: connection with database failed\n";
    } else {
      std::cout << "Database: connection ok\n";
    }
}

DbManager::~DbManager() {
    delete parser;
    dataBase.close();
    std::cout << "Database: connection closed\n";
}

bool DbManager::updateCollege(const int id, const College& college) {
    // Make sure ID is in database
    if (isUnusedId(id)) {
        std::cerr << "No college with id " << id << ", update failed.\n";
        return false;
    }

    QString name = college.getName();
    QString state = college.getState();
    QString souvenirs = getSouvenirsString(college.getSouvenirs());
    QString distances = getDistancesString(college.getDistances());
    int numStudents = college.size();

    // Construct the UPDATE query with the appropriate parameters
    QSqlQuery query;
    query.prepare("UPDATE colleges SET name = :NAME, state = :STATE, "
                  "souvenirs = :SOUVENIRS, distances = :DISTANCES, "
                  "num_students = :NUM_STUDENTS WHERE id = :ID");
    query.bindValue(":NAME", name);
    query.bindValue(":STATE", state);
    query.bindValue(":SOUVENIRS", souvenirs);
    query.bindValue(":DISTANCES", distances);
    query.bindValue(":NUM_STUDENTS", numStudents);
    query.bindValue(":ID", id);

    // Check that the query was successful
    if (query.exec()) {
        return true;
    }
    std::cerr << "Could not update college.\n";
    return false;
}

bool DbManager::addCollege(const College &college) {
    int id = college.getID();

    if (!isUnusedId(id)) {
        std::cerr << "Can't add college, id " << id << " already in use.\n";
        return false;
    }

    QString name = college.getName();
    QString state = college.getState();
    QString souvenirs = getSouvenirsString(college.getSouvenirs());
    QString distances = getDistancesString(college.getDistances());
    int numStudents = college.size();

    // Construct the INSERT query with the appropriate parameters
    QSqlQuery query;
    query.prepare(
       "INSERT INTO colleges VALUES (:ID, :NAME, :STATE, :SOUVENIRS, :DISTANCES, :NUM_STUDENTS)"
    );
    query.bindValue(":ID", id);
    query.bindValue(":NAME", name);
    query.bindValue(":STATE", state);
    query.bindValue(":SOUVENIRS", souvenirs);
    query.bindValue(":DISTANCES", distances);
    query.bindValue(":NUM_STUDENTS", numStudents);

    // Check that the query was successful
    if (query.exec()) {
       // NEED TO UPDATE OTHER COLLEGES WITH THE NEW COLLEGES'S DISTANCE
       auto distances = college.getDistances();
       auto colleges = getAllColleges();
       auto ids = getAllIds();
       for (const int i : ids) {
           // find existing college
           auto c = colleges.find(i);
           // update existing college with its distance to this new college
           c->college.setDistance(id, distances[i]);
           // update the existing college's record in the database
           updateCollege(c->id, c->college);
       }
       return true;
    }
    std::cerr << "Could not add restaurant.\n";
    return false;
}

bool DbManager::deleteCollegeById(const int id)
{
    if (isUnusedId(id)) {
        std::cerr << "Can't delete, id " << id << " doesn't exist.\n";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM colleges WHERE ID = ?");
    query.addBindValue(id);

    // Now have to update all other colleges to remove their distance from
    // the deleted college since it no longer exits
    if (query.exec()) {
        auto colleges = getAllColleges();
        auto ids = getAllIds();
        deleteAllColleges();

        for (int i : ids) {
            College c = colleges.find(i)->college;
            c.removeDistance(id);
            addCollege(c);
        }
        return true;
    }
    std::cerr << "Could not delete college.\n";
    return false;
}

void DbManager::deleteAllColleges() {
    QSqlQuery query("DELETE FROM colleges");
}

void DbManager::addFromTextFile(bool reset) {
    if (reset) {
        // Clear the database
        deleteAllColleges();
    }

    // Parse CSV file and add its colleges
    CollegeHashMap data;
    std::vector<int> ids;
    auto existingIds = getAllIds();
    parser->read(data, existingIds, ids);

    for (int id : ids) {
        College c = data.find(id)->college;
        if (!addCollege(c)) {
            std::cout << "Error occurred when resetting db with CSV file.\n";
        }
    }
}

CollegeHashMap DbManager::getAllColleges() const {
    College currentCollege;
    CollegeHashMap colleges;

    QSqlQuery query("SELECT * FROM colleges");

    while (query.next()) {
        currentCollege = getCollegeFromRecord(query.record());
        colleges.insert(currentCollege.getID(), currentCollege);
    }

    return colleges;
}

std::vector<int> DbManager::getAllIds() const {
    std::vector<int> ids;
    QSqlQuery query("SELECT id FROM colleges");

    while (query.next()) {
        // Check for a match, if there's a match then the ID is in use!
        ids.push_back(query.record().value("id").toInt());
    }

    return ids;
}

bool DbManager::isUnusedId(const int id) const {
    QSqlQuery query("SELECT id FROM colleges");

    // Loop through all ID's
    while (query.next()) {
        // Check for a match, if there's a match then the ID is in use!
        if (id == query.value("id").toInt()) {
            return false;
        }
    }

    return true;
}

void DbManager::print() const {
    QSqlQuery query("SELECT * FROM colleges");

    while (query.next()) {
        std::cout << "College:\n";
        for (int i = 0; i < NUM_COLUMNS; ++i) {
           std::cout << '\t' << query.value(i).toString().toStdString() << '\n';
        }
        std::cout << '\n';
    }
}

/****************** PRIVATE MEMBER FUNCTIONS **********************************/

College DbManager::getCollegeFromRecord(const QSqlRecord &rec) const {
    College college;

    // set id, name, state, and numStudents
    college.setID(rec.value("id").toInt());
    college.setName(rec.value("name").toString());
    college.setState(rec.value("state").toString());
    college.setSize(rec.value("num_students").toInt());

    QString souvenirs = rec.value("souvenirs").toString();
    // (split db's souvenirs string by comma and space into an array)
    // Format: "Item $priceInDollars"
    auto items = souvenirs.split(", ");
    for (const QString& i : items) {
        int index = i.indexOf('$');
        // Get item's name (text before '$' discarding space
        QString itemName = i.mid(0, index - 1);
        // Get item's price (text after '$' and convert to float
        float itemPrice = i.mid(index + 1).toFloat();
        // Add the souvenir item using the name and price
        college.addSouvenir({itemName, itemPrice});
    }

    // Set distances
    // (split db's distances string by comma and space into an array then
    //  convert type)
    auto distancesStrings = rec.value("DISTANCES").toString().split(", ");
    // Setting the rest of the distances
    // Format: "IntId FloatDistance" (separated by commas)
    for (unsigned i = 0, n = distancesStrings.size(); i < n; ++i) {
        QString pair = distancesStrings[i];
        int spaceIndex = pair.indexOf(' ');
        // Extract id before space char
        int key = pair.mid(0, spaceIndex).toInt();
        // Extract distance after space char
        float distance = pair.mid(spaceIndex + 1).toFloat();
        // Add distance using id as key and distance as value
        college.setDistance(key, distance);
    }

    return college;
}

QString DbManager::getSouvenirsString(const std::vector<Souvenir>& souvenirs) const {
    // Database wants to see the souvenirs as text
    // Fromat: "Item1 $priceFloat, Item2 $priceFloat, .., ItemN $priceFloat"
    QString souvenirsString = "";

    for (size_t i = 0; i < souvenirs.size(); ++i) {
        souvenirsString += souvenirs[i].name + " ";
        souvenirsString += "$" + QString::number(souvenirs[i].price);

        if (i != souvenirs.size() - 1) {
            souvenirsString += ", ";
        }
    }

    return souvenirsString;
}

QString DbManager::getDistancesString(const std::unordered_map<int, float>
                                      &distances) const {
    // Database wants to see distances as text
    // Format: "Id1 Distance1, Id2 Distance2, ..."
    QString distancesString = "";
    size_t i = 0;
    for (const auto& d : distances) {
        distancesString += QString::number(d.first) + " " +
                           QString::number(d.second);

        // Don't add a comma after the last distance
        if (i != distances.size() - 1) {
            distancesString += ", ";
        }
        i++;
    }

    return distancesString;
}

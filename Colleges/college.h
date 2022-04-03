#ifndef COLLEGE_H
#define COLLEGE_H

#include <QObject>

struct Souvenir {
    QString name;
    double price;
};

///
/// \brief The College class -- Encapsulates all the data of a college, with various helper methods.
///
class College
{
public:

    //Default constructor, initializes an empty College - do we need this? delete maybe
    College();

    ///
    /// \brief Alt Constructor
    /// Initializes a College with all data initialized
    ///
    College(QString name, int id, QString state, int numUndergraduates, std::map<int, double> distances, std::vector<Souvenir> souvenirs);

    ///
    /// \brief Finds the distance to a college specified
    /// \param College we are trying to find the distance to
    /// \return a double representing the distance from the calling college to the college passed in
    /// ///
    double distanceTo(College otherCollege);


    //Accesors
    ///
    /// \brief getName()
    /// \return QString name of the college
    ///
    QString getName() { return name; }

    ///
    /// \brief getState()
    /// \return QString name of the state the college is in
    ///
    QString getState() { return state; }

    ///
    /// \brief getID()
    /// \return int of the college ID
    ///
    int getID() { return id; }

    ///
    /// \brief size()
    /// \return int of the number of undergraduates in the college
    ///
    int size() { return numUndergraduates; }

    //Mutators
    ///
    /// \brief Adds a new souvenir to the college
    /// \param New souvenir object to add
    ///
    void addSouvenir(Souvenir souvenir);

    ///
    /// \brief Redefines the name of the college
    /// \param QString of the new name
    ///
    void setName(QString name);

    ///
    /// \brief Redefines the college ID
    /// \param int of the new ID
    ///
    void setID(int id);

    ///
    /// \brief Redefines the college state
    /// \param QString of the new state name
    ///
    void setState(QString state);

    ///
    /// \brief Adds a new distance to a college into the distances map
    /// \param College we are trying to add a distance to
    /// \param distance of the current college to the new college
    ///
    void addDistance(College college, double distance);


private:
    QString name;
    int id;
    QString state;
    int numUndergraduates;
    std::map<int, double> distances;
    std::vector<Souvenir> souvenirs;
};

#endif // COLLEGE_H

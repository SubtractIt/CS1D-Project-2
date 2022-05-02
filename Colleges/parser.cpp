///
/// @author Juliette Raubolt
/// @file   parser.cpp
///
#include "parser.h"

// Constrcutor
Parser::Parser() {}

// Destructor
Parser::~Parser() {}

/*******************************************************************
 * read
 * -----------------------------------------------------------------
 * Takes in two files of colleges and souvenirs which have default
 * values to the names of the initial value files. The method reads
 * the college and souvenir by college meaning the inital college
 * info is read, then the program loops to read all distance info
 * for that school. The souvenirs for that specific restaurant
 * will then be read until the next college is reached. The method
 * will return false if a file cannot be opened and true if the
 * entire file is read.
 * -----------------------------------------------------------------
 * pre conditions:
 *  colleges : csv file name for the colleges, default: "college"
 *  souvs    : csv file name for the souvenirs, default: "souvenir"
 * post conditions:
 *  Returns true or false depending on the success of opening and
 *  looping through file. Puts file contents into objects
 ******************************************************************/
bool Parser::read(CollegeHashMap& collegeTrain,
                  const std::vector<int>& existingIds, std::vector<int>& newIds,
                  std::string colleges, std::string souvs) {

    College newCollege; // Object to place new college in
    Souvenir newSouv;   // Object to place new souvenir in

#if __APPLE__ && TARGET_OS_MAC
        colleges = "../../../../Colleges/" + colleges + ".csv";
        souvs = "../../../../Colleges/" + souvs + ".csv";
#elif __linux__
        colleges = "../Colleges/" + colleges + ".csv";
        souvs = "../Colleges/" + souvs + ".csv";
#else
        colleges = "..\\Colleges\\" + colleges + ".csv";
        souvs = "..\\Colleges\\" + souvs + ".csv";
#endif

    // QFile to read the csv files for colleges and souvenirs
    QFile inCollege(colleges.c_str()); // CALC & CALC - input stream variable for college info
    QFile inSouvenir(souvs.c_str());   // CALC & CALC - input stream variable for souvenirs

    // Checking that college file opens
    if(!inCollege.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open college csv \n";
        return false;
    }
    // Checking that souvenir file opens
    if(!inSouvenir.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open college csv \n";
        return false;
    }

    QString line;             // used to read in each line of college
    QStringList lineContent;  // used to split line by cell of college
    QString sLine;            // used to read in each line of souvenir
    QStringList sLineContent; // used to split line by cell of souvenir
    QStringList priceSlice;   // handle the $ sign with prices

    // As long as college & souvenir is open, can delete first
    // line which just includes titles
    line = inCollege.readLine();
    sLine = inSouvenir.readLine();

    // As long as not at end of file read 1st line of data
    if(!inCollege.atEnd()) {
        line = inCollege.readLine();
        lineContent = line.split(',');
    } else {
//        qDebug() << "End of college";
    }

    // As long as not at end of file read 1st line of data
    if(!inSouvenir.atEnd()) {
        sLine = inSouvenir.readLine();
        sLineContent = sLine.split(',');
    } else {
//        qDebug() << "End of souvenir";
    }

    // If database is empty, we will start the ids at 1. Otherwise, we will
    // start the ids at the number of colleges in the database plus one as they
    // start from one and increment by one each time
    bool dbEmpty = existingIds.empty();
    int id;
    if (dbEmpty) {
        id = 0;
    } else {
        id = existingIds.size();
    }
    // Loop through college and souvenir files
    while(!inCollege.atEnd()) {

        // Assign line data to college object which includes
        // name, state, # undergrads, and initial dist
        newCollege.setName(lineContent[0]);

        newIds.push_back(++id);
        newCollege.setID(id);
        int index = 1; // This index is used for sequential distance
                       // id component
        // Doesn't read it's own index so need to skip over the
        // index that corresponds with the id
        if(index == id)
            ++index;
        // Set initial distance that is in the inital college row
        // and increment the index now that the distance is set
        newCollege.setDistance(index, lineContent[2].toFloat());
        ++index;
        // Set new colleges state and undergrad size
        newCollege.setState(lineContent[3]);
        newCollege.setSize(lineContent[4].toInt());

        // Read next line of college file which
        // should be distances
        if(!inCollege.atEnd()) {
            line = inCollege.readLine();
            lineContent = line.split(',');
        } else {
            qDebug() << "Error, should have distances";
            break;
        }

        // Continue loping to handle distances until
        // reach a new college
        while(lineContent[0] == newCollege.getName()) {

            // Set next distance and increment the index
            // now that the distance is set
            if(index == id)
                ++index;
            newCollege.setDistance(index, lineContent[2].toFloat());
            ++index;

            // Get next line which may be a distance or may
            // be a new school
            if(!inCollege.atEnd()) {
                line = inCollege.readLine();
                lineContent = line.split(',');
            } else {
//                qDebug() << "End of college";
                break;
            }
        }

        // Make sure the souvenir corresponds to correct school
        if(sLineContent[0] == newCollege.getName()) {

            // If so then ready to move to next line with souvenir
            // and continue looping
            if(!inSouvenir.atEnd()) {
                sLine = inSouvenir.readLine();
                sLineContent = sLine.split(',');

                // Loop until reach souvenirs of next college
                // and store the name & price of each souvenir
                while(sLineContent[0] == "") {
                    newSouv.name = sLineContent[1];
                    // Removing the $ from the price prior to assigning
                    priceSlice = sLineContent[2].split('$');
                    newSouv.price = priceSlice[1].toFloat();
                    // Add souvenir object to the college's souvenir
                    newCollege.addSouvenir(newSouv);

                    // As long as not at end of file then read
                    // the next line of souvenirs which may be a
                    // souvenir or new college
                    if(!inSouvenir.atEnd()) {
                        sLine = inSouvenir.readLine();
                        sLineContent = sLine.split(',');
                    } else {
//                        qDebug() << "End of souvenir";
                        break;
                    }
                }
            }
        } else {
            qDebug() << "No souvenirs";
            //done = true;
            break;
        }

/*** The following is for testing and can be removed ***/
//        newCollege.print();

        // Add the college object to the vector of
        // objects and reinitialize the college
        // object to reset the menu and distances
        collegeTrain.insert(id, newCollege);
        newCollege.reInitialize();
    }

    // Close both files
    inCollege.close();
    inSouvenir.close();


/*** The following is for testing and can be removed ***/
//    collegeTrain.print();

    // Successfully read files so return true
    return true;
}

///
/// @author Juliette Raubolt
/// @file   parser.cpp
///
#include "parser.h"

// Constrcutor
Parser::Parser(){}

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
bool Parser::read(std::string colleges, std::string souvs) {

    // Temporary variables for testing
    std::vector<placeHold> temps;
    placeHold temp;
    souvenir tempSouv;

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
        qDebug() << "End of college";
    }

    // As long as not at end of file read 1st line of data
    if(!inSouvenir.atEnd()) {
        sLine = inSouvenir.readLine();
        sLineContent = sLine.split(',');
    } else {
        qDebug() << "End of souvenir";
    }

    // Loop through college and souvenir files
    while(!inCollege.atEnd()) {

        // Assign line data to college object which includes
        // name, state, # undergrads, and initial dist
        temp.name = lineContent[0];
        int index = 1;
        temp.distances[lineContent[1].toStdString()] = lineContent[2].toFloat();
        ++index;
        temp.state = lineContent[3];
        temp.underGrads = lineContent[4].toInt();

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
        while(lineContent[0] == temp.name) {

            // Assign distances to a map
            temp.distances[lineContent[1].toStdString()] = lineContent[2].toFloat();
            ++index;

            // Get next line which may be a distance or may
            // be a new school
            if(!inCollege.atEnd()) {
                line = inCollege.readLine();
                lineContent = line.split(',');
            } else {
                qDebug() << "End of college";
                break;
            }
        }

        // Make sure the souvenir corresponds to correct school
        if(sLineContent[0] == temp.name) {

            // If so then ready to move to next line with souvenir
            // and continue looping
            if(!inSouvenir.atEnd()) {
                sLine = inSouvenir.readLine();
                sLineContent = sLine.split(',');

                // Loop until reach souvenirs of next college
                // and store the name & price of each souvenir
                while(sLineContent[0] == "") {
                    tempSouv.name = sLineContent[1];
                    // Removing the $ from the price prior to assigning
                    priceSlice = sLineContent[2].split('$');
                    tempSouv.price = priceSlice[1].toFloat();
                    // Add souvenir object to the college's souvenir
                    temp.souvenirs.push_back(tempSouv);

                    // As long as not at end of file then read
                    // the next line of souvenirs which may be a
                    // souvenir or new college
                    if(!inSouvenir.atEnd()) {
                        sLine = inSouvenir.readLine();
                        sLineContent = sLine.split(',');
                    } else {
                        qDebug() << "End of souvenir";
                        break;
                    }
                }
            }
        } else {
            qDebug() << "No souvenirs";
            //done = true;
            break;
        }

        // Add the college object to the vector of
        // objects and reinitialize the college
        // object to reset the menu and distances
        temps.push_back(temp);
        temp.reinitialize();
    }

    // Close both files
    inCollege.close();
    inSouvenir.close();

/** The following loop is for testing and can be removed **/
    for(size_t i = 0; i < temps.size(); ++i)
       temps[i].print();

    // Successfully read files so return true
    return true;
}

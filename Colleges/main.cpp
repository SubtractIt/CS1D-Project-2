#include "mainwindow.h"
#include <QApplication>

#include "dbmanager.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DbManager *db = new DbManager("../Colleges/colleges.db");
    db->addFromTextFile(true);
    db->addFromTextFile(false);

    auto colleges = db->getAllColleges();
    auto ids = db->getAllIds();

    for (int id : ids) {
        colleges.find(id)->college.print();
    }

    return a.exec();
}

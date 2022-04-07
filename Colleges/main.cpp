#include "mainwindow.h"
#include <QApplication>

#include "dbmanager.h"
#include "purchaser.h"

int main(int argc, char *argv[])
{
    QString path;

#if __APPLE__ && TARGET_OS_MAC
    path = "../../../../Colleges/colleges.db";
#elif __linux__
    path = "../Colleges/colleges.db";
#else
    path = "..\\Colleges\\colleges.db";
#endif

    DbManager db(path);

    db.addFromTextFile(true);

    auto colleges = db.getAllColleges();
    auto ids = db.getAllIds();

//    for (int id : ids) {
//        colleges.find(id)->college.print();
//        std::cout << '\n';
//    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

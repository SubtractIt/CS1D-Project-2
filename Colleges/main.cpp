#include "mainwindow.h"
#include <QApplication>

#include "dbmanager.h"
#include "purchaser.h"

#include "graph.h"

int main(int argc, char *argv[])
{
    QString path;

#if __APPLE__ && TARGET_OS_MAC
    path = "../../../../Colleges/colleges.db";
#elif __linux__
    path = "../Colleges/colleges.db";
#else
    path = "D:/Qt/PROJECT 2 CS1D/CS1D-Project-2/Colleges/colleges.db";
#endif

    DbManager db(path);

    db.addFromTextFile(true);

    auto colleges = db.getAllColleges();
    auto ids = db.getAllIds();

    std::cout << "Colleges:\n";
    for (int id : ids) {
        colleges.find(id).print();
    }
    std::cout << '\n';

    std::cout << "Graph:\n";
    WeightedGraph g;
    g.addColleges(colleges, ids);
    g.printGraph();
    std::cout << '\n';

    std::cout << "DFS starting from UCI:\n";
    std::vector<int> tripPath;
    std::vector<float> tripDistances;
    g.dfs(7, tripPath, tripDistances);
    float sum = 0;
    for (int i = 0; i < tripPath.size(); i++) {
        if (i > 0) {
            std::cout << tripDistances[i - 1] << " miles to -> \n";
            sum += tripDistances[i - 1];
        }
        std::cout << colleges.find(tripPath[i]).getName().toStdString()
                  << " (id " << tripPath[i] << ')';
        if (i < tripPath.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << '\n';
    std::cout << "Total mileage: " << sum << " miles\n";
    std::cout << "\n";

    std::cout << "BFS starting from Arizona State University:\n";
    g.bfs(1, tripPath, tripDistances);
    sum = 0;
    for (int i = 0; i < tripPath.size(); i++) {
        if (i > 0) {
            std::cout << tripDistances[i - 1] << " miles to -> \n";
            sum += tripDistances[i - 1];
        }
        std::cout << colleges.find(tripPath[i]).getName().toStdString()
                  << " (id " << tripPath[i] << ')';
        if (i < tripPath.size() - 1) {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
    std::cout << "Total mileage: " << sum << " miles\n";
    std::cout << "\n";


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

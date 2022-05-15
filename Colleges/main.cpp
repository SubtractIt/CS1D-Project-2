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
    path = "..\\Colleges\\colleges.db";
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

    std::unordered_map<int, float> costs;
    std::unordered_map<int, std::vector<int>> shortestPaths;
    g.dijkstra(6, shortestPaths, costs);

    std::cout << "Shortest paths from University of Michigan:\n"
              << "----------\n";
    for (int id : ids) {
        if (id == 6) {
            continue;
        }

        std::cout << colleges.find(id).getName().toStdString() << " (" << id << "):\n\t";
        if (costs[id] == INF) {
            std::cout << "no path\n";
            continue;
        }

        for (auto it = shortestPaths[id].begin(); it != shortestPaths[id].end();
             ++it) {
            std::cout << colleges.find(*it).getName().toStdString() << " (" << *it << ")";

            if (it != shortestPaths[id].end() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << "\n\t" << costs[id] << " miles\n\n";
    }

    // MST Testing
    float dist;
    std::unordered_map<int, int> mstEdges;
    g.mst(mstEdges, dist);


    QApplication a(argc, argv);

    QString stylePath;
#if __APPLE__ && TARGET_OS_MAC
    stylePath = "../../../../Colleges/styles.qss";
#elif __linux__
    stylePath = "../Colleges/styles.qss";
#else
    stylePath = "..\\Colleges\\styles.qss";
#endif

    QFile qss(stylePath);
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();

    MainWindow w;
    w.show();

    return a.exec();
}

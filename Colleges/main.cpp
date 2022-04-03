#include "mainwindow.h"
#include "parser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CollegeHashMap data;
    Parser* parse;
    parse->read(data);

    parse->read(data, "college2", "souvenir2");
    return a.exec();
}

#include "mainwindow.h"

#include <QApplication>
#include "parser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Parser* parse;
    parse->read();

    parse->read("colleges2", "souvenirs2");


    return a.exec();
}

#include "mainwindow.h"
#include "connector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Attempt to open connection to music database
    if (!createConnection())
        return 1;

    // Show mainwindow
    MainWindow w;
    w.show();

    return a.exec();
}

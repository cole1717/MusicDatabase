#include "mainwindow.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost:3306");
    db.setDatabaseName("music");
    db.setUserName("root");
    db.setPassword("Dodgerthedog12");
    bool ok = db.open();

    if (ok)
        return 0;*/

    QApplication a(argc, argv);
    if (!createConnection())
        return 1;

    MainWindow w;
    w.show();

    return a.exec();
}

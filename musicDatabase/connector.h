#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost:3306");
    db.setDatabaseName("starwarsfinal");
    db.setUserName("root");
    db.setPassword("Dodgerthedog12");
    if (!db.open())
    {
        QMessageBox::warning(0, "Error", "Unable to connect to the database");
        return false;
    }
    return true;
}

#endif // CONNECTOR_H

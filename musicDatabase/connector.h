#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <iostream>

using namespace std;

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("music");
    db.setUserName("root");
    db.setPassword("password");
    if (!db.open())
    {
        QMessageBox::warning(0, "Error", db.lastError().text());
        return false;
    }
    return true;
}

#endif // CONNECTOR_H

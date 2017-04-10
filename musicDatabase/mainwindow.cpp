#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //search = new QLineEdit;
    //search->setPlaceholderText("Search...");
    //search->setFocus();

    ui->searchBox->setPlaceholderText("Search...");
    ui->searchBox->setFocus();

    results = new QSqlTableModel(this);
    results->setTable("person");
    results->setEditStrategy(QSqlTableModel::OnManualSubmit);
    results->setHeaderData(0, Qt::Horizontal, tr("ID"));
    results->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    results->setHeaderData(2, Qt::Horizontal, tr("Album"));
    //results->select();

    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));

    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);

    ui->resultsView->setModel(results);
    ui->resultsView->setSortingEnabled(true);

    setWindowTitle(tr("Music Player"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::submit()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Music Player"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}

void MainWindow::on_searchButton_clicked()
{
    QString search_value = ui->searchBox->text();
    QString search_statement;
    if (ui->artistRadioButton->isChecked()) {
        search_statement = "select * from person where firstname = '" +
                search_value + "'";
    } else if (ui->albumRadioButton->isChecked()) {
        search_statement = "select * from person where lastname = '" +
                search_value + "'";
    }

    QSqlQuery query;
    query.exec(search_statement);
    QSqlRecord null = query.record();
    for (int i = 0; i < 5; i++) {
        results->setRecord(i, null);
    }
    query.next();
    QSqlRecord record = query.record();
    results->setRecord(0, record);
}

void MainWindow::deleteRow(int index)
{
    //void *res = results;
    //res->deleteRowFromTable(index);
}

void MainWindow::on_actionCreate_Playlist_triggered()
{
    QSqlQuery query;
    query.exec("select COUNT(*) from person");

    while(query.next()) {
    QMessageBox::warning(this, tr("music player"),
                         query.value(0).toString());
    }
}

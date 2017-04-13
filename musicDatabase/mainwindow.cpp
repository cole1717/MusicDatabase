#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up search box
    ui->searchBox->setPlaceholderText("Search...");
    ui->searchBox->setFocus();

    // Set up results table model after table_view view
    results = new QSqlTableModel(this);
    results->setTable("table_view");
    results->setEditStrategy(QSqlTableModel::OnManualSubmit);

    results->setHeaderData(0, Qt::Horizontal, tr("Title"));
    results->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    results->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Set up model table model after table_view view
    model = new QSqlTableModel(this);
    model->setTable("table_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setSort(1, Qt::DescendingOrder);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Set up playlists table model after playlists table
    playlists = new QSqlTableModel(this);
    playlists->setTable("playlists");
    playlists->setEditStrategy(QSqlTableModel::OnRowChange);
    playlists->select();

    playlists->setHeaderData(0, Qt::Horizontal, tr("Index"));
    playlists->setHeaderData(1, Qt::Horizontal, tr("Playlist Name"));

    // Attach table models to table views
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->resultsView->setModel(results);
    ui->resultsView->setSortingEnabled(true);
    ui->resultsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->resultsView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->playlistTableView->setModel(playlists);
    ui->playlistTableView->setSortingEnabled(true);
    ui->playlistTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Set title of window
    setWindowTitle(tr("MyMusic Player"));
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
    QSqlQuery query;
    QString search_value = ui->searchBox->text();
    QString search_string;
    if (ui->artistRadioButton->isChecked()) {
        search_string = "Select * from table_view where artist like concat ('%', '"
                + search_value + "', '%')";
        query.prepare(search_string);

        //query.prepare("CALL artist_search('AC/DC')");
        //query.bindValue(":value", search_value);
    } else if (ui->albumRadioButton->isChecked()) {
        search_string = "Select * from table_view where album like concat ('%', '"
                + search_value + "', '%')";
        query.prepare(search_string);

        //query.prepare("CALL search_album(:value)");
        //query.bindValue(":value", search_value);
    } else if (ui->songRadioButton->isChecked()) {
        search_string = "Select * from table_view where title like concat ('%', '"
                + search_value + "', '%')";
        query.prepare(search_string);

        //query.prepare("CALL search_song(:value)");
        //query.bindValue(":value", search_value);
    } else if (ui->genreRadioButton->isChecked()) {
        query.prepare("CALL search('AC/DC')");

        //query.prepare("CALL search_genre(:value)");
        //query.bindValue(":value", search_value);
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("Please select a "
                                                     "field to search in!"));
        return;
    }

    // Execute query prepared earlier
    if (!query.exec())
        QMessageBox::warning(this, tr("warning"), query.lastError().text());
    //qDebug() << query.first();
    //qDebug() << query.next();

    // Clear table view with blank entries
    QSqlRecord null = query.record();
    for (int i = 0; i < results->rowCount(); i++) {
        results->setRecord(i, null);
    }

    // While there are results, fill table view
    QSqlRecord record = query.record();
    int index = 0;
    while (query.next())
    {
        record = query.record();
        results->setRecord(index, record);
        index++;
    }
}

// Add a playlist
void MainWindow::on_playlistAddButton_clicked()
{
    bool ok;
    QString playlist_name = QInputDialog::getText(this, tr("New Playlist"),
                                                  tr("Playlist name:"), QLineEdit::Normal,
                                                  QDir::home().dirName(), &ok);
    if (ok && !playlist_name.isEmpty())
        create_playlist(playlist_name);

    playlists->select();
}

void MainWindow::create_playlist(QString playlist_name)
{
    QSqlQuery query;
    QString exec_string;
    exec_string = "INSERT INTO playlists VALUES(DEFAULT, '" + playlist_name + "')";
    query.exec(exec_string);
}

// Edit a playlist
void MainWindow::on_playlistEditButton_clicked()
{

}

void MainWindow::edit_playlist(QString playlist_name)
{

}

// Delete a playlist
void MainWindow::on_playlistDeleteButton_clicked()
{
    QItemSelectionModel *select = ui->playlistTableView->selectionModel();
    if (select->hasSelection()) {
        QString index = select->selectedRows().at(0).data().toString();
        delete_playlist(index);
    }

    playlists->select();
}

void MainWindow::delete_playlist(QString playlist_name)
{
    QSqlQuery query;
    QString exec_string;
    exec_string = "DELETE FROM playlists WHERE playlistId = " + playlist_name;
    query.exec(exec_string);
}



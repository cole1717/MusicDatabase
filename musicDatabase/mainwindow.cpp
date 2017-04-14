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
    results->select();

    results->setHeaderData(0, Qt::Horizontal, tr("Title"));
    results->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    results->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Set up model table model after table_view view
    model = new QSqlTableModel(this);
    model->setTable("table_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Set up playlists table model after playlists table
    playlists = new QSqlTableModel(this);
    playlists->setTable("playlists");
    playlists->setEditStrategy(QSqlTableModel::OnRowChange);
    playlists->setSort(0, Qt::AscendingOrder);
    playlists->select();

    playlists->setHeaderData(0, Qt::Horizontal, tr("Index"));
    playlists->setHeaderData(1, Qt::Horizontal, tr("Playlist Name"));

    // Attach table models to table views
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->resultsView->setModel(results);
    ui->resultsView->setSortingEnabled(false);
    ui->resultsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->resultsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->resultsView->setSelectionMode(QAbstractItemView::ExtendedSelection);

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
    if (ui->artistRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM table_view "
                      "WHERE artist LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY album ASC");
        query.bindValue(":value", search_value);

    } else if (ui->albumRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM table_view "
                      "WHERE album LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY album ASC, artist ASC");
        query.bindValue(":value", search_value);

    } else if (ui->songRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM table_view "
                      "WHERE title LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY title ASC");
        query.bindValue(":value", search_value);

    } else if (ui->genreRadioButton->isChecked()) {
        query.prepare("SELECT title, artist, album "
                      "FROM table_view, albums, genres "
                      "WHERE album = albums.name "
                      "AND albums.genreId = genres.genreId "
                      "AND genres.name LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY artist ASC, album ASC");
        query.bindValue(":value", search_value);

    } else {
        QMessageBox::warning(this, tr("Warning"), tr("Please select a "
                                                     "field to search in!"));
        return;
    }

    // Execute query prepared earlier
    if (!query.exec())
        QMessageBox::warning(this, tr("Warning"), query.lastError().text());

    // Clear table view with blank entries
    QSqlRecord null = query.record();
    for (int i = 0; i < results->rowCount(); i++) {
        results->setRecord(i, null);
    }

    // While there are results, fill table view
    QSqlRecord record = query.record();
    int index = 0;
    while (query.next()) {
        record = query.record();
        results->setRecord(index, record);
        index++;
    }
}

// Add a playlist
void MainWindow::create_playlist(QString playlist_name)
{
    QSqlQuery query;
    // Call prepared statement `create_playlist`
    query.prepare("CALL create_playlist(:playlist)");
    query.bindValue(":playlist", playlist_name);
    query.exec();
}

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

// Edit a playlist
void MainWindow::edit_playlist(QString playlist_name)
{

}

void MainWindow::on_playlistEditButton_clicked()
{

}

// Delete a playlist
void MainWindow::delete_playlist(QString playlist_index)
{
    QSqlQuery query;
    // Call prepared statement `delete_playlist`
    query.prepare("CALL delete_playlist(:index)");
    query.bindValue(":index", playlist_index);
    query.exec();
}

void MainWindow::on_playlistDeleteButton_clicked()
{
    QItemSelectionModel *select = ui->playlistTableView->selectionModel();
    if (select->hasSelection()) {
        QString index = select->selectedRows().at(0).data().toString();
        delete_playlist(index);
    }

    playlists->select();
}

<<<<<<< HEAD
void MainWindow::delete_playlist(QString playlist_index)
{
    QSqlQuery query;
    QString exec_string;
    exec_string = "DELETE FROM playlists WHERE playlistId = " + playlist_index;
    query.exec(exec_string);
}
=======

>>>>>>> tyler

void MainWindow::on_addToPlaylistButton_clicked()
{
    // TODO: need to add 'trackId' to table_view in MySQL as well as MainWindow constructor
    // track_id currently thinks the index is actually the song title
    QItemSelectionModel *select = ui->resultsView->selectionModel();
    if (select->hasSelection()) {
        for(int i = 0; i< select->selectedRows().count(); i++) {
            QString playlist_id = "1";   // Need to get input from user somehow for what playlist to add to
            QString track_id = select->selectedRows(0).at(i).data().toString();
            // qDebug() << track_id;
            add_to_playlist(playlist_id, track_id);
        }
    }
}

void MainWindow::add_to_playlist(QString playlist_index, QString track_index)
{
    // TODO: use MySQL procedure instead

    QSqlQuery query;
    QString exec_string;
    exec_string = "INSERT INTO `music`.`playlists_has_tracks` (`playlistId`, `trackId`) VALUES ('"
             + playlist_index + "', '" + track_index + "')";
    query.exec(exec_string);
}

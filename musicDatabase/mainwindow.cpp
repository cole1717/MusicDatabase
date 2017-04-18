#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectplaylist.h"

#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect(ui->, SIGNAL(click()), this, SLOT(openNewWindow()));
    // selWin = new selectPlaylist(this);
    selWin = new selectPlaylist();
    selWin->setWindowModality(Qt::ApplicationModal);
    selWin->raise();

    // Set up search box
    ui->searchBox->setPlaceholderText("Search...");
    ui->searchBox->setFocus();

    // Set up results table model after table_view view
    results = new QSqlTableModel(this);
    results->setTable("playlist_view");
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

    // Set up playlist_results table model after playlists table
    playlist_results = new QSqlTableModel(this);
    playlist_results->setTable("playlist_view");
    playlist_results->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //playlist_results->select();

    playlist_results->setHeaderData(0, Qt::Horizontal, tr("Title"));
    playlist_results->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    playlist_results->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Attach table models to table views
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 125);
    ui->tableView->setColumnWidth(2, 150);

    ui->resultsView->setModel(results);
    ui->resultsView->setSortingEnabled(false);
    ui->resultsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->resultsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->resultsView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->resultsView->setColumnHidden(3, true);
    ui->resultsView->setColumnWidth(0, 250);
    ui->resultsView->setColumnWidth(1, 125);
    ui->resultsView->setColumnWidth(2, 150);

    ui->playlistTableView->setModel(playlists);
    ui->playlistTableView->setSortingEnabled(true);
    //ui->playlistTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistTableView->setColumnWidth(0, 100);
    ui->playlistTableView->setColumnWidth(1, 250);

    ui->playlistResultTableView->setModel(playlist_results);
    ui->playlistResultTableView->setSortingEnabled(false);
    ui->playlistResultTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistResultTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistResultTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->playlistResultTableView->setColumnHidden(3, true);
    ui->playlistResultTableView->setColumnWidth(0, 250);
    ui->playlistResultTableView->setColumnWidth(1, 125);
    ui->playlistResultTableView->setColumnWidth(2, 150);

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
    // Check to make sure search_value is not empty
    if (search_value.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please enter a search value!"));
        return;
    }
    // If not empty, search for value
    if (ui->artistRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM playlist_view "
                      "WHERE artist LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY album ASC");
        query.bindValue(":value", search_value);

    } else if (ui->albumRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM playlist_view "
                      "WHERE album LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY album ASC, artist ASC");
        query.bindValue(":value", search_value);

    } else if (ui->songRadioButton->isChecked()) {
        query.prepare("SELECT * "
                      "FROM playlist_view "
                      "WHERE title LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY title ASC");
        query.bindValue(":value", search_value);

    } else if (ui->genreRadioButton->isChecked()) {
        query.prepare("SELECT title, artist, album, track_id "
                      "FROM playlist_view, albums, genres "
                      "WHERE album = albums.name "
                      "AND albums.genreId = genres.genreId "
                      "AND genres.name LIKE CONCAT ('%', :value, '%') "
                      "ORDER BY artist ASC, album ASC");
        query.bindValue(":value", search_value);

    } else {
        // If no radio button has been selected
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
                                                  tr("New Playlist"), &ok);
    if (ok && !playlist_name.isEmpty())
        create_playlist(playlist_name);

    playlists->select();
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

    // Refresh playlists table view
    playlists->select();

    // Refresh playlists results table view
    select = ui->playlistTableView->selectionModel();
    if (select->hasSelection()) {
        // Get index from selection
        int playlist_index = select->selectedRows(0).at(0).data().toInt();
        // qDebug() << playlist_index;
        load_playlist(playlist_index);
    } else {
        // Fill empty table view
        load_playlist(0);
    }
}

void MainWindow::on_addToPlaylistButton_clicked()
{
    selWin->playlists->select();
    if (playlists->rowCount() < 1) {
        QMessageBox::warning(this, tr("Warning"), tr("No playlists available!"));
        return;
    }

    QItemSelectionModel *select = ui->resultsView->selectionModel();
    if (select->hasSelection()) {
        // get user input
        selWin->show();

        /* TODO:
         * Wait for selWin->'Confirm Selection' to be clicked
         * selWin inherit from QDialog? dialog.exec();?
         */

        QString playlist_id = selWin->getIndex();

        // selWin->hide();

        // add tracks to playlist
        for(int i = 0; i< select->selectedRows().count(); i++) {
            QString track_id = select->selectedRows(3).at(i).data().toString();
            // qDebug() << track_id;
            add_to_playlist(playlist_id, track_id);
        }
    } else {
            // No selection made
            QMessageBox::warning(this, tr("Warning"), tr("No selection made!"));
    }
}

void MainWindow::add_to_playlist(QString playlist_index, QString track_index)
{
    QSqlQuery query;
    query.prepare("CALL insert_into_playlist(:playlist, :track)");
    query.bindValue(":playlist", playlist_index);
    query.bindValue(":track", track_index);
    query.exec();
}

void MainWindow::load_playlist(int playlist_index)
{
    // Populate tableview
    playlist_results->select();

    QSqlQuery query;
    query.prepare("SELECT title, artist, album, track_id "
                  "FROM playlist_view, playlists_has_tracks "
                  "WHERE playlists_has_tracks.playlistId = :playlist_index "
                  "AND playlists_has_tracks.trackId = track_id");
    query.bindValue(":playlist_index", playlist_index);

    // Execute query prepared earlier
    if (!query.exec())
        QMessageBox::warning(this, tr("Warning"), query.lastError().text());

    // Clear table view with blank entries
    QSqlRecord null = query.record();
    for (int i = 0; i < playlist_results->rowCount(); i++) {
        playlist_results->setRecord(i, null);
    }

    // While there are results, fill table view
    QSqlRecord record = query.record();
    int index = 0;
    while (query.next()) {
        record = query.record();
        playlist_results->setRecord(index, record);
        index++;
    }
}

void MainWindow::on_loadButton_clicked()
{
    // First, get index of playlist to be loaded
    // Then, display all songs in that playlist
    QItemSelectionModel *select = ui->playlistTableView->selectionModel();
    if (select->hasSelection()) {
        // Get index from selection
        int playlist_index = select->selectedRows(0).at(0).data().toInt();
        curr_playlist = playlist_index;
        // qDebug() << playlist_index;
        load_playlist(playlist_index);
    } else {
        // No selection made
        QMessageBox::warning(this, tr("Warning"), tr("No selection made!"));
    }
}

void MainWindow::on_actionAbout_triggered()
{
    // Open help file
    QString filename = "README.txt";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString about = file.readAll();

    file.close();

    QMessageBox::information(this, tr("About"), about);
}

void MainWindow::delete_track_from_playlist(int track_index, int playlist_index)
{
    // Call delete_track procedure
    QSqlQuery query;
    query.prepare("CALL delete_track(:playlist, :track)");
    query.bindValue(":playlist", playlist_index);
    query.bindValue(":track", track_index);
    query.exec();
}

void MainWindow::on_deleteTrackButton_clicked()
{
    // Get selected tracks to delete
    QItemSelectionModel *select = ui->playlistResultTableView->selectionModel();
    if (select->hasSelection()) {
        for (int i = 0; i < select->selectedRows().count(); i++) {
            int track_index = select->selectedRows(3).at(i).data().toInt();
            delete_track_from_playlist(track_index, curr_playlist);
        }
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("No songs selected!"));
    }

    // Refresh playlists results table view
    load_playlist(curr_playlist);
}

/* TODO:
 *
 * Functionality:
 *  -delete tracks from playlist functionality
 *  -get user input for what playlist to add to -- working on it
 *  -add 'About' section?
 *
 */

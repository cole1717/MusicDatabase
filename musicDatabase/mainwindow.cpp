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
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, tr("Artist"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));

    // Attach table models to table views
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);

    ui->resultsView->setModel(results);
    ui->resultsView->setSortingEnabled(true);

    // Set title of window
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
    QSqlQuery query;
    QString search_value = ui->searchBox->text();
    QString search_string;
    if (ui->artistRadioButton->isChecked()) {
        search_string = "Select * from table_view where artist = '" + search_value
                + "'";
        query.prepare(search_string);

        //query.prepare("CALL artist_search(':value')");
        //query.bindValue(":value", search_value);
    } else if (ui->albumRadioButton->isChecked()) {
        query.prepare("CALL search_album(:value)");
        query.bindValue(":value", search_value);
    } else if (ui->songRadioButton->isChecked()) {
        query.prepare("CALL search_song(:value)");
        query.bindValue(":value", search_value);
    } else if (ui->genreRadioButton->isChecked()) {
        query.prepare("CALL search_genre(:value)");
        query.bindValue(":value", search_value);
    }

    query.exec();
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

void MainWindow::deleteRow(int index)
{

}

void MainWindow::on_actionCreate_Playlist_triggered()
{
    bool ok;
    QString playlist_name = QInputDialog::getText(this, tr("New Playlist"),
                                                  tr("Playlist name:"), QLineEdit::Normal,
                                                  QDir::home().dirName(), &ok);
    if (ok && !playlist_name.isEmpty())
        create_playlist(playlist_name);
}

void MainWindow::create_playlist(QString playlist_name)
{
    QSqlQuery query;
    QString exec_string;
    exec_string = "INSERT INTO playlists VALUES(DEFAULT, '" + playlist_name + "')";
    query.exec(exec_string);
}

void MainWindow::on_actionNew_playlist_triggered()
{
    bool ok;
    QString playlist_name = QInputDialog::getText(this, tr("New Playlist"),
                                                  tr("Playlist name:"), QLineEdit::Normal,
                                                  QDir::home().dirName(), &ok);
    if (ok && !playlist_name.isEmpty())
        create_playlist(playlist_name);
}

void MainWindow::edit_playlist(QString playlist_name)
{

}

void MainWindow::on_actionEdit_playlist_triggered()
{
    bool ok;
    QString playlist_name = QInputDialog::getText(this, tr("Edit Playlist"),
                                                  tr("Playlist name:"), QLineEdit::Normal,
                                                  QDir::home().dirName(), &ok);
    if (ok && !playlist_name.isEmpty())
        edit_playlist(playlist_name);
}

void MainWindow::delete_playlist(QString playlist_name)
{

}

void MainWindow::on_actionDelete_playlist_triggered()
{
    bool ok;
    QString playlist_name = QInputDialog::getText(this, tr("Delete Playlist"),
                                                  tr("Playlist name:"), QLineEdit::Normal,
                                                  QDir::home().dirName(), &ok);
    if (ok && !playlist_name.isEmpty())
        delete_playlist(playlist_name);
}

#include "selectplaylist.h"
#include "ui_selectplaylist.h"

#include <QDebug>
#include <QMessageBox>

selectPlaylist::selectPlaylist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectPlaylist),
    playlistIndex("")
{
    ui->setupUi(this);

    playlists = new QSqlTableModel(this);
    playlists->setTable("playlists");
    playlists->setEditStrategy(QSqlTableModel::OnRowChange);
    playlists->setSort(0, Qt::AscendingOrder);
    playlists->select();

    playlists->setHeaderData(0, Qt::Horizontal, tr("Index"));
    playlists->setHeaderData(1, Qt::Horizontal, tr("Playlist Name"));

    ui->tableView->setModel(playlists);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Set title of window
    setWindowTitle(tr("Add to Playlist"));
}

selectPlaylist::~selectPlaylist()
{
    delete ui;
}

void selectPlaylist::on_confirmSelectionButton_clicked()
{
    // playlists->select();
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if (select->hasSelection()) {
        playlistIndex = select->selectedRows(0).at(0).data().toString();
        // qDebug() << playlistIndex;
    } else {
            // No selection made
            QMessageBox::warning(this, tr("Warning"), tr("No selection made!"));
    }
}

#include "selectplaylistdialog.h"
#include "ui_selectplaylistdialog.h"

#include <QMessageBox>

selectPlaylistDialog::selectPlaylistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectPlaylistDialog),
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

selectPlaylistDialog::~selectPlaylistDialog()
{
    delete ui;
}

void selectPlaylistDialog::on_confirmSelectionButton_clicked()
{
    // playlists->select();
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if (select->hasSelection()) {
        playlistIndex = select->selectedRows(0).at(0).data().toString();
        // qDebug() << playlistIndex;
        done(1);
    } else {
            // No selection made
        QMessageBox::warning(this, tr("Warning"), tr("No selection made!"));
    }
}

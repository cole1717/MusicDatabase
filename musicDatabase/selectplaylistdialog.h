#ifndef SELECTPLAYLISTDIALOG_H
#define SELECTPLAYLISTDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class selectPlaylistDialog;
}

class selectPlaylistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit selectPlaylistDialog(QWidget *parent = 0);
    ~selectPlaylistDialog();

    QString getIndex() { return playlistIndex; }

    QSqlTableModel *playlists; // need access from MainWindow

private slots:
    void on_confirmSelectionButton_clicked();

private:
    Ui::selectPlaylistDialog *ui;
    QString playlistIndex;
};

#endif // SELECTPLAYLISTDIALOG_H

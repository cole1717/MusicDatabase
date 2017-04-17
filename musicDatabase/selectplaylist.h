#ifndef SELECTPLAYLIST_H
#define SELECTPLAYLIST_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class selectPlaylist;
}

class selectPlaylist : public QMainWindow
{
    Q_OBJECT

public:
    explicit selectPlaylist(QWidget *parent = 0);
    ~selectPlaylist();

    QString getIndex() { return playlistIndex; }

    QSqlTableModel *playlists; // need access from MainWindow

private slots:
    void on_confirmSelectionButton_clicked();

private:
    Ui::selectPlaylist *ui;
    QString playlistIndex;
};

#endif // SELECTPLAYLIST_H

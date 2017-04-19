#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "selectplaylistdialog.h"

#include <QMainWindow>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QHeaderView>
#include <QLineEdit>
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void submit();

    void create_playlist(QString playlist_name);
    void delete_playlist(QString playlist_index);
    void load_playlist(int playlist_index);
    void delete_track_from_playlist(int track_index, int playlist_index);

    void on_searchButton_clicked();

    void add_to_playlist(QString playlist_index, QString track_id);

    void on_playlistAddButton_clicked();

    void on_playlistDeleteButton_clicked();

    void on_addToPlaylistButton_clicked();

    void on_loadButton_clicked();

    void on_actionAbout_triggered();

    void on_deleteTrackButton_clicked();

private:
    Ui::MainWindow *ui;
    selectPlaylistDialog *selWin;
    QSqlTableModel *model;
    QSqlTableModel *results;
    QSqlTableModel *playlists;
    QSqlTableModel *playlist_results;
    QLineEdit *search;
    int curr_playlist;
};

#endif // MAINWINDOW_H

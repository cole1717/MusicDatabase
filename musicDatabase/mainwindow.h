#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_searchButton_clicked();

    void on_actionCreate_Playlist_triggered();

    void on_actionNew_playlist_triggered();

    void on_actionEdit_playlist_triggered();

    void on_actionDelete_playlist_triggered();

    void create_playlist(QString playlist_name);
    void edit_playlist(QString playlist_name);
    void delete_playlist(QString playlist_name);

    void on_playlistAddButton_clicked();

    void on_playlistDeleteButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlTableModel *results;
    QSqlTableModel *playlists;
    QLineEdit *search;
};

#endif // MAINWINDOW_H

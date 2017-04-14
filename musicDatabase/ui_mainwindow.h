/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_playlist;
    QAction *actionEdit_playlist;
    QAction *actionDelete_playlist;
    QAction *actionExit;
    QAction *actionPlay;
    QAction *actionReverse;
    QAction *actionForward;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionCreate_Playlist;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Search;
    QPushButton *searchButton;
    QTableView *resultsView;
    QRadioButton *songRadioButton;
    QRadioButton *albumRadioButton;
    QTableView *tableView;
    QRadioButton *artistRadioButton;
    QRadioButton *genreRadioButton;
    QLineEdit *searchBox;
    QPushButton *addToPlaylistButton;
    QWidget *Playlists;
    QTableView *playlistTableView;
    QPushButton *playlistAddButton;
    QPushButton *playlistDeleteButton;
    QPushButton *playlistEditButton;
    QLabel *label;
    QPushButton *loadButton;
    QTableView *playlistResultTableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 631);
        actionNew_playlist = new QAction(MainWindow);
        actionNew_playlist->setObjectName(QStringLiteral("actionNew_playlist"));
        actionEdit_playlist = new QAction(MainWindow);
        actionEdit_playlist->setObjectName(QStringLiteral("actionEdit_playlist"));
        actionDelete_playlist = new QAction(MainWindow);
        actionDelete_playlist->setObjectName(QStringLiteral("actionDelete_playlist"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon;
        icon.addFile(QStringLiteral("play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral("pause.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPlay->setIcon(icon);
        actionReverse = new QAction(MainWindow);
        actionReverse->setObjectName(QStringLiteral("actionReverse"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("rewind.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReverse->setIcon(icon1);
        actionForward = new QAction(MainWindow);
        actionForward->setObjectName(QStringLiteral("actionForward"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("fast_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForward->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCreate_Playlist = new QAction(MainWindow);
        actionCreate_Playlist->setObjectName(QStringLiteral("actionCreate_Playlist"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -2, 531, 561));
        Search = new QWidget();
        Search->setObjectName(QStringLiteral("Search"));
        searchButton = new QPushButton(Search);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(380, 0, 93, 28));
        resultsView = new QTableView(Search);
        resultsView->setObjectName(QStringLiteral("resultsView"));
        resultsView->setGeometry(QRect(0, 225, 501, 261));
        songRadioButton = new QRadioButton(Search);
        songRadioButton->setObjectName(QStringLiteral("songRadioButton"));
        songRadioButton->setGeometry(QRect(250, 2, 61, 20));
        albumRadioButton = new QRadioButton(Search);
        albumRadioButton->setObjectName(QStringLiteral("albumRadioButton"));
        albumRadioButton->setGeometry(QRect(180, 2, 71, 20));
        tableView = new QTableView(Search);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 30, 501, 191));
        artistRadioButton = new QRadioButton(Search);
        artistRadioButton->setObjectName(QStringLiteral("artistRadioButton"));
        artistRadioButton->setGeometry(QRect(120, 2, 61, 20));
        artistRadioButton->setChecked(true);
        genreRadioButton = new QRadioButton(Search);
        genreRadioButton->setObjectName(QStringLiteral("genreRadioButton"));
        genreRadioButton->setGeometry(QRect(310, 2, 71, 20));
        searchBox = new QLineEdit(Search);
        searchBox->setObjectName(QStringLiteral("searchBox"));
        searchBox->setGeometry(QRect(0, 2, 113, 22));
        addToPlaylistButton = new QPushButton(Search);
        addToPlaylistButton->setObjectName(QStringLiteral("addToPlaylistButton"));
        addToPlaylistButton->setGeometry(QRect(0, 487, 121, 28));
        tabWidget->addTab(Search, QString());
        Playlists = new QWidget();
        Playlists->setObjectName(QStringLiteral("Playlists"));
        playlistTableView = new QTableView(Playlists);
        playlistTableView->setObjectName(QStringLiteral("playlistTableView"));
        playlistTableView->setGeometry(QRect(10, 20, 481, 201));
        playlistAddButton = new QPushButton(Playlists);
        playlistAddButton->setObjectName(QStringLiteral("playlistAddButton"));
        playlistAddButton->setGeometry(QRect(10, 230, 111, 28));
        playlistDeleteButton = new QPushButton(Playlists);
        playlistDeleteButton->setObjectName(QStringLiteral("playlistDeleteButton"));
        playlistDeleteButton->setGeometry(QRect(256, 230, 111, 28));
        playlistEditButton = new QPushButton(Playlists);
        playlistEditButton->setObjectName(QStringLiteral("playlistEditButton"));
        playlistEditButton->setGeometry(QRect(134, 230, 111, 28));
        label = new QLabel(Playlists);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 2, 131, 16));
        loadButton = new QPushButton(Playlists);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(380, 230, 111, 28));
        playlistResultTableView = new QTableView(Playlists);
        playlistResultTableView->setObjectName(QStringLiteral("playlistResultTableView"));
        playlistResultTableView->setGeometry(QRect(10, 270, 481, 241));
        tabWidget->addTab(Playlists, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionReverse);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionForward);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew_playlist->setText(QApplication::translate("MainWindow", "New playlist", 0));
        actionEdit_playlist->setText(QApplication::translate("MainWindow", "Edit playlist", 0));
        actionDelete_playlist->setText(QApplication::translate("MainWindow", "Delete playlist", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0));
        actionReverse->setText(QApplication::translate("MainWindow", "Reverse", 0));
        actionForward->setText(QApplication::translate("MainWindow", "Forward", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "View help", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionCreate_Playlist->setText(QApplication::translate("MainWindow", "Create Playlist", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        songRadioButton->setText(QApplication::translate("MainWindow", "Song", 0));
        albumRadioButton->setText(QApplication::translate("MainWindow", "Album", 0));
        artistRadioButton->setText(QApplication::translate("MainWindow", "Artist", 0));
        genreRadioButton->setText(QApplication::translate("MainWindow", "Genre", 0));
        searchBox->setText(QString());
        addToPlaylistButton->setText(QApplication::translate("MainWindow", "Add to Playlist...", 0));
        tabWidget->setTabText(tabWidget->indexOf(Search), QApplication::translate("MainWindow", "Search", 0));
        playlistAddButton->setText(QApplication::translate("MainWindow", "Add", 0));
        playlistDeleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        playlistEditButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        label->setText(QApplication::translate("MainWindow", "Playlists", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        tabWidget->setTabText(tabWidget->indexOf(Playlists), QApplication::translate("MainWindow", "Playlists", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

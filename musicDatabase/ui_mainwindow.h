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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Search;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QTableView *resultsView;
    QRadioButton *artistRadioButton;
    QLineEdit *searchBox;
    QRadioButton *genreRadioButton;
    QRadioButton *songRadioButton;
    QRadioButton *albumRadioButton;
    QTableView *tableView;
    QPushButton *searchButton;
    QPushButton *addToPlaylistButton;
    QWidget *Playlists;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *playlistAddButton;
    QPushButton *loadButton;
    QPushButton *playlistDeleteButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *deleteTrackButton;
    QTableView *playlistTableView;
    QLabel *label;
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
        MainWindow->resize(668, 772);
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
        icon.addFile(QStringLiteral("images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral("images/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPlay->setIcon(icon);
        actionReverse = new QAction(MainWindow);
        actionReverse->setObjectName(QStringLiteral("actionReverse"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/rewind.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReverse->setIcon(icon1);
        actionForward = new QAction(MainWindow);
        actionForward->setObjectName(QStringLiteral("actionForward"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/fast_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForward->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCreate_Playlist = new QAction(MainWindow);
        actionCreate_Playlist->setObjectName(QStringLiteral("actionCreate_Playlist"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Search = new QWidget();
        Search->setObjectName(QStringLiteral("Search"));
        verticalLayout = new QVBoxLayout(Search);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(Search);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        resultsView = new QTableView(Search);
        resultsView->setObjectName(QStringLiteral("resultsView"));

        gridLayout->addWidget(resultsView, 3, 0, 1, 6);

        artistRadioButton = new QRadioButton(Search);
        artistRadioButton->setObjectName(QStringLiteral("artistRadioButton"));
        artistRadioButton->setChecked(true);

        gridLayout->addWidget(artistRadioButton, 0, 1, 1, 1);

        searchBox = new QLineEdit(Search);
        searchBox->setObjectName(QStringLiteral("searchBox"));

        gridLayout->addWidget(searchBox, 0, 0, 1, 1);

        genreRadioButton = new QRadioButton(Search);
        genreRadioButton->setObjectName(QStringLiteral("genreRadioButton"));

        gridLayout->addWidget(genreRadioButton, 0, 4, 1, 1);

        songRadioButton = new QRadioButton(Search);
        songRadioButton->setObjectName(QStringLiteral("songRadioButton"));

        gridLayout->addWidget(songRadioButton, 0, 2, 1, 1);

        albumRadioButton = new QRadioButton(Search);
        albumRadioButton->setObjectName(QStringLiteral("albumRadioButton"));

        gridLayout->addWidget(albumRadioButton, 0, 3, 1, 1);

        tableView = new QTableView(Search);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 6);

        searchButton = new QPushButton(Search);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        gridLayout->addWidget(searchButton, 0, 5, 1, 1);

        addToPlaylistButton = new QPushButton(Search);
        addToPlaylistButton->setObjectName(QStringLiteral("addToPlaylistButton"));

        gridLayout->addWidget(addToPlaylistButton, 4, 4, 1, 2);


        verticalLayout->addLayout(gridLayout);

        tabWidget->addTab(Search, QString());
        Playlists = new QWidget();
        Playlists->setObjectName(QStringLiteral("Playlists"));
        verticalLayout_3 = new QVBoxLayout(Playlists);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        playlistAddButton = new QPushButton(Playlists);
        playlistAddButton->setObjectName(QStringLiteral("playlistAddButton"));

        gridLayout_2->addWidget(playlistAddButton, 2, 1, 1, 1);

        loadButton = new QPushButton(Playlists);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        gridLayout_2->addWidget(loadButton, 2, 3, 1, 1);

        playlistDeleteButton = new QPushButton(Playlists);
        playlistDeleteButton->setObjectName(QStringLiteral("playlistDeleteButton"));

        gridLayout_2->addWidget(playlistDeleteButton, 2, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 6, 1, 1);

        deleteTrackButton = new QPushButton(Playlists);
        deleteTrackButton->setObjectName(QStringLiteral("deleteTrackButton"));

        gridLayout_2->addWidget(deleteTrackButton, 4, 5, 1, 2);

        playlistTableView = new QTableView(Playlists);
        playlistTableView->setObjectName(QStringLiteral("playlistTableView"));

        gridLayout_2->addWidget(playlistTableView, 1, 0, 1, 7);

        label = new QLabel(Playlists);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        playlistResultTableView = new QTableView(Playlists);
        playlistResultTableView->setObjectName(QStringLiteral("playlistResultTableView"));

        gridLayout_2->addWidget(playlistResultTableView, 3, 0, 1, 7);


        verticalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(Playlists, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 668, 26));
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
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionReverse);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionForward);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
        label_2->setText(QApplication::translate("MainWindow", "Search Results", 0));
        artistRadioButton->setText(QApplication::translate("MainWindow", "Artist", 0));
        searchBox->setText(QString());
        genreRadioButton->setText(QApplication::translate("MainWindow", "Genre", 0));
        songRadioButton->setText(QApplication::translate("MainWindow", "Song", 0));
        albumRadioButton->setText(QApplication::translate("MainWindow", "Album", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        addToPlaylistButton->setText(QApplication::translate("MainWindow", "Add to Playlist...", 0));
        tabWidget->setTabText(tabWidget->indexOf(Search), QApplication::translate("MainWindow", "Search", 0));
        playlistAddButton->setText(QApplication::translate("MainWindow", "Add", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        playlistDeleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        deleteTrackButton->setText(QApplication::translate("MainWindow", "Delete from Playlist...", 0));
        label->setText(QApplication::translate("MainWindow", "Playlists", 0));
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

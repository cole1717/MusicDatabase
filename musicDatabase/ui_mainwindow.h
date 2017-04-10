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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
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
    QLineEdit *searchBox;
    QRadioButton *artistRadioButton;
    QRadioButton *albumRadioButton;
    QRadioButton *songRadioButton;
    QRadioButton *genreRadioButton;
    QPushButton *searchButton;
    QTableView *tableView;
    QTableView *resultsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(524, 620);
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
        icon.addFile(QStringLiteral("../play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral("../pause.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPlay->setIcon(icon);
        actionReverse = new QAction(MainWindow);
        actionReverse->setObjectName(QStringLiteral("actionReverse"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../rewind.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReverse->setIcon(icon1);
        actionForward = new QAction(MainWindow);
        actionForward->setObjectName(QStringLiteral("actionForward"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../fast_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForward->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCreate_Playlist = new QAction(MainWindow);
        actionCreate_Playlist->setObjectName(QStringLiteral("actionCreate_Playlist"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        searchBox = new QLineEdit(centralWidget);
        searchBox->setObjectName(QStringLiteral("searchBox"));
        searchBox->setGeometry(QRect(10, 10, 113, 22));
        artistRadioButton = new QRadioButton(centralWidget);
        artistRadioButton->setObjectName(QStringLiteral("artistRadioButton"));
        artistRadioButton->setGeometry(QRect(130, 10, 61, 20));
        albumRadioButton = new QRadioButton(centralWidget);
        albumRadioButton->setObjectName(QStringLiteral("albumRadioButton"));
        albumRadioButton->setGeometry(QRect(190, 10, 71, 20));
        songRadioButton = new QRadioButton(centralWidget);
        songRadioButton->setObjectName(QStringLiteral("songRadioButton"));
        songRadioButton->setGeometry(QRect(260, 10, 61, 20));
        genreRadioButton = new QRadioButton(centralWidget);
        genreRadioButton->setObjectName(QStringLiteral("genreRadioButton"));
        genreRadioButton->setGeometry(QRect(320, 10, 71, 20));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(390, 10, 93, 28));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 40, 501, 231));
        resultsView = new QTableView(centralWidget);
        resultsView->setObjectName(QStringLiteral("resultsView"));
        resultsView->setGeometry(QRect(10, 280, 501, 241));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 524, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_playlist);
        menuFile->addAction(actionEdit_playlist);
        menuFile->addAction(actionDelete_playlist);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionReverse);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionForward);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCreate_Playlist);

        retranslateUi(MainWindow);

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
        searchBox->setText(QString());
        artistRadioButton->setText(QApplication::translate("MainWindow", "Artist", 0));
        albumRadioButton->setText(QApplication::translate("MainWindow", "Album", 0));
        songRadioButton->setText(QApplication::translate("MainWindow", "Song", 0));
        genreRadioButton->setText(QApplication::translate("MainWindow", "Genre", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
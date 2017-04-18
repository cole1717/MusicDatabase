/********************************************************************************
** Form generated from reading UI file 'selectplaylist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYLIST_H
#define UI_SELECTPLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectPlaylist
{
public:
    QWidget *centralwidget;
    QPushButton *confirmSelectionButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *selectPlaylist)
    {
        if (selectPlaylist->objectName().isEmpty())
            selectPlaylist->setObjectName(QStringLiteral("selectPlaylist"));
        selectPlaylist->resize(330, 349);
        centralwidget = new QWidget(selectPlaylist);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        confirmSelectionButton = new QPushButton(centralwidget);
        confirmSelectionButton->setObjectName(QStringLiteral("confirmSelectionButton"));
        confirmSelectionButton->setGeometry(QRect(205, 268, 121, 28));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(4, 4, 321, 261));
        selectPlaylist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(selectPlaylist);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 330, 26));
        selectPlaylist->setMenuBar(menubar);
        statusbar = new QStatusBar(selectPlaylist);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        selectPlaylist->setStatusBar(statusbar);

        retranslateUi(selectPlaylist);

        QMetaObject::connectSlotsByName(selectPlaylist);
    } // setupUi

    void retranslateUi(QMainWindow *selectPlaylist)
    {
        selectPlaylist->setWindowTitle(QApplication::translate("selectPlaylist", "MainWindow", 0));
        confirmSelectionButton->setText(QApplication::translate("selectPlaylist", "Confirm Selection", 0));
    } // retranslateUi

};

namespace Ui {
    class selectPlaylist: public Ui_selectPlaylist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYLIST_H

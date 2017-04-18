/********************************************************************************
** Form generated from reading UI file 'selectplaylistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYLISTDIALOG_H
#define UI_SELECTPLAYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_selectPlaylistDialog
{
public:
    QTableView *tableView;
    QPushButton *confirmSelectionButton;

    void setupUi(QDialog *selectPlaylistDialog)
    {
        if (selectPlaylistDialog->objectName().isEmpty())
            selectPlaylistDialog->setObjectName(QStringLiteral("selectPlaylistDialog"));
        selectPlaylistDialog->resize(281, 267);
        tableView = new QTableView(selectPlaylistDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(6, 10, 271, 221));
        confirmSelectionButton = new QPushButton(selectPlaylistDialog);
        confirmSelectionButton->setObjectName(QStringLiteral("confirmSelectionButton"));
        confirmSelectionButton->setGeometry(QRect(147, 235, 131, 28));

        retranslateUi(selectPlaylistDialog);

        QMetaObject::connectSlotsByName(selectPlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *selectPlaylistDialog)
    {
        selectPlaylistDialog->setWindowTitle(QApplication::translate("selectPlaylistDialog", "Dialog", Q_NULLPTR));
        confirmSelectionButton->setText(QApplication::translate("selectPlaylistDialog", "Confirm Selection", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectPlaylistDialog: public Ui_selectPlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYLISTDIALOG_H

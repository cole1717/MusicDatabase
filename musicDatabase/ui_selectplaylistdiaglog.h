/********************************************************************************
** Form generated from reading UI file 'selectplaylistdiaglog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYLISTDIAGLOG_H
#define UI_SELECTPLAYLISTDIAGLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_selectPlaylistDiaglog
{
public:
    QTableView *tableView;
    QPushButton *confirmSelectionButton;

    void setupUi(QDialog *selectPlaylistDiaglog)
    {
        if (selectPlaylistDiaglog->objectName().isEmpty())
            selectPlaylistDiaglog->setObjectName(QStringLiteral("selectPlaylistDiaglog"));
        selectPlaylistDiaglog->resize(289, 254);
        tableView = new QTableView(selectPlaylistDiaglog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(4, 10, 281, 211));
        confirmSelectionButton = new QPushButton(selectPlaylistDiaglog);
        confirmSelectionButton->setObjectName(QStringLiteral("confirmSelectionButton"));
        confirmSelectionButton->setGeometry(QRect(155, 224, 131, 28));

        retranslateUi(selectPlaylistDiaglog);

        QMetaObject::connectSlotsByName(selectPlaylistDiaglog);
    } // setupUi

    void retranslateUi(QDialog *selectPlaylistDiaglog)
    {
        selectPlaylistDiaglog->setWindowTitle(QApplication::translate("selectPlaylistDiaglog", "Dialog", Q_NULLPTR));
        confirmSelectionButton->setText(QApplication::translate("selectPlaylistDiaglog", "Confirm Selection", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectPlaylistDiaglog: public Ui_selectPlaylistDiaglog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYLISTDIAGLOG_H

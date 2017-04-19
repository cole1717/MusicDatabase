/********************************************************************************
** Form generated from reading UI file 'selectplaylistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_selectPlaylistDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QTableView *tableView;
    QPushButton *confirmSelectionButton;

    void setupUi(QDialog *selectPlaylistDialog)
    {
        if (selectPlaylistDialog->objectName().isEmpty())
            selectPlaylistDialog->setObjectName(QStringLiteral("selectPlaylistDialog"));
        selectPlaylistDialog->resize(322, 263);
        verticalLayout = new QVBoxLayout(selectPlaylistDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        tableView = new QTableView(selectPlaylistDialog);
        tableView->setObjectName(QStringLiteral("tableView"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, tableView);

        confirmSelectionButton = new QPushButton(selectPlaylistDialog);
        confirmSelectionButton->setObjectName(QStringLiteral("confirmSelectionButton"));
        confirmSelectionButton->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(1, QFormLayout::LabelRole, confirmSelectionButton);


        verticalLayout->addLayout(formLayout);


        retranslateUi(selectPlaylistDialog);

        QMetaObject::connectSlotsByName(selectPlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *selectPlaylistDialog)
    {
        selectPlaylistDialog->setWindowTitle(QApplication::translate("selectPlaylistDialog", "Dialog", 0));
        confirmSelectionButton->setText(QApplication::translate("selectPlaylistDialog", "Confirm Selection", 0));
    } // retranslateUi

};

namespace Ui {
    class selectPlaylistDialog: public Ui_selectPlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYLISTDIALOG_H

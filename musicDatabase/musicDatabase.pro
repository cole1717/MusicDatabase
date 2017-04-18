#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T16:46:21
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musicDatabase
TEMPLATE = app

QTPLUGIN += QSQLMYSQL

SOURCES += main.cpp\
        mainwindow.cpp \
    selectplaylistdialog.cpp

HEADERS  += mainwindow.h \
    connection.h \
    connector.h \
    ui_mainwindow.h \
    selectplaylistdialog.h

FORMS    += mainwindow.ui \
    selectplaylistdialog.ui

DISTFILES += \
    PlaylistwindowForm.ui.qml \
    Playlistwindow.qml

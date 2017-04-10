#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T16:46:21
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musicDatabase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    connection.h \
    connector.h

FORMS    += mainwindow.ui

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "submit"
QT_MOC_LITERAL(4, 43, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(5, 67, 15), // "create_playlist"
QT_MOC_LITERAL(6, 83, 13), // "playlist_name"
QT_MOC_LITERAL(7, 97, 15), // "delete_playlist"
QT_MOC_LITERAL(8, 113, 14), // "playlist_index"
QT_MOC_LITERAL(9, 128, 13), // "load_playlist"
QT_MOC_LITERAL(10, 142, 15), // "add_to_playlist"
QT_MOC_LITERAL(11, 158, 8), // "track_id"
QT_MOC_LITERAL(12, 167, 28), // "on_playlistAddButton_clicked"
QT_MOC_LITERAL(13, 196, 31), // "on_playlistDeleteButton_clicked"
QT_MOC_LITERAL(14, 228, 30), // "on_addToPlaylistButton_clicked"
QT_MOC_LITERAL(15, 259, 21), // "on_loadButton_clicked"
QT_MOC_LITERAL(16, 281, 24) // "on_actionAbout_triggered"

    },
    "MainWindow\0on_actionExit_triggered\0\0"
    "submit\0on_searchButton_clicked\0"
    "create_playlist\0playlist_name\0"
    "delete_playlist\0playlist_index\0"
    "load_playlist\0add_to_playlist\0track_id\0"
    "on_playlistAddButton_clicked\0"
    "on_playlistDeleteButton_clicked\0"
    "on_addToPlaylistButton_clicked\0"
    "on_loadButton_clicked\0on_actionAbout_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       9,    1,   83,    2, 0x08 /* Private */,
      10,    2,   86,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->submit(); break;
        case 2: _t->on_searchButton_clicked(); break;
        case 3: _t->create_playlist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->delete_playlist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->load_playlist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->add_to_playlist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->on_playlistAddButton_clicked(); break;
        case 8: _t->on_playlistDeleteButton_clicked(); break;
        case 9: _t->on_addToPlaylistButton_clicked(); break;
        case 10: _t->on_loadButton_clicked(); break;
        case 11: _t->on_actionAbout_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

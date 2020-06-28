/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ASSN5/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "event_clock"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "event_stopwatch"
QT_MOC_LITERAL(4, 40, 30), // "on_stopwatch_btn_start_clicked"
QT_MOC_LITERAL(5, 71, 29), // "on_stopwatch_btn_stop_clicked"
QT_MOC_LITERAL(6, 101, 30), // "on_stopwatch_btn_reset_clicked"
QT_MOC_LITERAL(7, 132, 11), // "event_timer"
QT_MOC_LITERAL(8, 144, 28), // "on_timer_btn_hour_up_clicked"
QT_MOC_LITERAL(9, 173, 30), // "on_timer_btn_minute_up_clicked"
QT_MOC_LITERAL(10, 204, 27), // "on_timer_btn_sec_up_clicked"
QT_MOC_LITERAL(11, 232, 30), // "on_timer_btn_hour_down_clicked"
QT_MOC_LITERAL(12, 263, 32), // "on_timer_btn_minute_down_clicked"
QT_MOC_LITERAL(13, 296, 29), // "on_timer_btn_sec_down_clicked"
QT_MOC_LITERAL(14, 326, 22), // "on_timer_start_clicked"
QT_MOC_LITERAL(15, 349, 21), // "on_timer_stop_clicked"
QT_MOC_LITERAL(16, 371, 22) // "on_timer_reset_clicked"

    },
    "MainWindow\0event_clock\0\0event_stopwatch\0"
    "on_stopwatch_btn_start_clicked\0"
    "on_stopwatch_btn_stop_clicked\0"
    "on_stopwatch_btn_reset_clicked\0"
    "event_timer\0on_timer_btn_hour_up_clicked\0"
    "on_timer_btn_minute_up_clicked\0"
    "on_timer_btn_sec_up_clicked\0"
    "on_timer_btn_hour_down_clicked\0"
    "on_timer_btn_minute_down_clicked\0"
    "on_timer_btn_sec_down_clicked\0"
    "on_timer_start_clicked\0on_timer_stop_clicked\0"
    "on_timer_reset_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->event_clock(); break;
        case 1: _t->event_stopwatch(); break;
        case 2: _t->on_stopwatch_btn_start_clicked(); break;
        case 3: _t->on_stopwatch_btn_stop_clicked(); break;
        case 4: _t->on_stopwatch_btn_reset_clicked(); break;
        case 5: _t->event_timer(); break;
        case 6: _t->on_timer_btn_hour_up_clicked(); break;
        case 7: _t->on_timer_btn_minute_up_clicked(); break;
        case 8: _t->on_timer_btn_sec_up_clicked(); break;
        case 9: _t->on_timer_btn_hour_down_clicked(); break;
        case 10: _t->on_timer_btn_minute_down_clicked(); break;
        case 11: _t->on_timer_btn_sec_down_clicked(); break;
        case 12: _t->on_timer_start_clicked(); break;
        case 13: _t->on_timer_stop_clicked(); break;
        case 14: _t->on_timer_reset_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

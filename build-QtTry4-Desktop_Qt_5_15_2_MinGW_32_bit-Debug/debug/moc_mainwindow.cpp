/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtTry4/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[31];
    char stringdata0[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "RevDBConnect"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "conect"
QT_MOC_LITERAL(4, 32, 8), // "RevDBLog"
QT_MOC_LITERAL(5, 41, 5), // "logIn"
QT_MOC_LITERAL(6, 47, 21), // "on_act_home_triggered"
QT_MOC_LITERAL(7, 69, 23), // "on_act_orders_triggered"
QT_MOC_LITERAL(8, 93, 27), // "on_act_create_ord_triggered"
QT_MOC_LITERAL(9, 121, 12), // "SigDBConnect"
QT_MOC_LITERAL(10, 134, 4), // "name"
QT_MOC_LITERAL(11, 139, 4), // "type"
QT_MOC_LITERAL(12, 144, 8), // "SigDBLog"
QT_MOC_LITERAL(13, 153, 3), // "log"
QT_MOC_LITERAL(14, 157, 4), // "pass"
QT_MOC_LITERAL(15, 162, 12), // "reciveSignal"
QT_MOC_LITERAL(16, 175, 8), // "UpdateDB"
QT_MOC_LITERAL(17, 184, 21), // "on_PB_wOpened_clicked"
QT_MOC_LITERAL(18, 206, 18), // "on_PB_wNew_clicked"
QT_MOC_LITERAL(19, 225, 5), // "print"
QT_MOC_LITERAL(20, 231, 9), // "QPrinter*"
QT_MOC_LITERAL(21, 241, 7), // "printer"
QT_MOC_LITERAL(22, 249, 19), // "onTableView_clicked"
QT_MOC_LITERAL(23, 269, 11), // "QModelIndex"
QT_MOC_LITERAL(24, 281, 12), // "ClearFocusLE"
QT_MOC_LITERAL(25, 294, 11), // "FocusDateOp"
QT_MOC_LITERAL(26, 306, 11), // "FocusDateCl"
QT_MOC_LITERAL(27, 318, 11), // "FocusDateDi"
QT_MOC_LITERAL(28, 330, 12), // "FocusToolBtn"
QT_MOC_LITERAL(29, 343, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(30, 365, 20) // "on_btn_print_clicked"

    },
    "MainWindow\0RevDBConnect\0\0conect\0"
    "RevDBLog\0logIn\0on_act_home_triggered\0"
    "on_act_orders_triggered\0"
    "on_act_create_ord_triggered\0SigDBConnect\0"
    "name\0type\0SigDBLog\0log\0pass\0reciveSignal\0"
    "UpdateDB\0on_PB_wOpened_clicked\0"
    "on_PB_wNew_clicked\0print\0QPrinter*\0"
    "printer\0onTableView_clicked\0QModelIndex\0"
    "ClearFocusLE\0FocusDateOp\0FocusDateCl\0"
    "FocusDateDi\0FocusToolBtn\0on_pushButton_clicked\0"
    "on_btn_print_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  120,    2, 0x08 /* Private */,
       7,    0,  121,    2, 0x08 /* Private */,
       8,    0,  122,    2, 0x08 /* Private */,
       9,    2,  123,    2, 0x08 /* Private */,
      12,    2,  128,    2, 0x08 /* Private */,
      15,    0,  133,    2, 0x08 /* Private */,
      16,    0,  134,    2, 0x08 /* Private */,
      17,    0,  135,    2, 0x08 /* Private */,
      18,    0,  136,    2, 0x08 /* Private */,
      19,    1,  137,    2, 0x08 /* Private */,
      22,    1,  140,    2, 0x08 /* Private */,
      24,    0,  143,    2, 0x08 /* Private */,
      25,    0,  144,    2, 0x08 /* Private */,
      26,    0,  145,    2, 0x08 /* Private */,
      27,    0,  146,    2, 0x08 /* Private */,
      28,    0,  147,    2, 0x08 /* Private */,
      29,    0,  148,    2, 0x08 /* Private */,
      30,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,    2,
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
        case 0: _t->RevDBConnect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->RevDBLog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_act_home_triggered(); break;
        case 3: _t->on_act_orders_triggered(); break;
        case 4: _t->on_act_create_ord_triggered(); break;
        case 5: _t->SigDBConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->SigDBLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->reciveSignal(); break;
        case 8: _t->UpdateDB(); break;
        case 9: _t->on_PB_wOpened_clicked(); break;
        case 10: _t->on_PB_wNew_clicked(); break;
        case 11: _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 12: _t->onTableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->ClearFocusLE(); break;
        case 14: _t->FocusDateOp(); break;
        case 15: _t->FocusDateCl(); break;
        case 16: _t->FocusDateDi(); break;
        case 17: _t->FocusToolBtn(); break;
        case 18: _t->on_pushButton_clicked(); break;
        case 19: _t->on_btn_print_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RevDBConnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RevDBLog)) {
                *result = 1;
                return;
            }
        }
    }
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::RevDBConnect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::RevDBLog(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'register1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "register1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_register1_t {
    QByteArrayData data[9];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_register1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_register1_t qt_meta_stringdata_register1 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "register1"
QT_MOC_LITERAL(1, 10, 11), // "timerupdate"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "timerupdate2"
QT_MOC_LITERAL(4, 36, 23), // "on_boy_button_1_clicked"
QT_MOC_LITERAL(5, 60, 25), // "on_employee_check_clicked"
QT_MOC_LITERAL(6, 86, 24), // "on_girl_button_1_clicked"
QT_MOC_LITERAL(7, 111, 22), // "on_cancel_bt_2_clicked"
QT_MOC_LITERAL(8, 134, 11) // "hide_widget"

    },
    "register1\0timerupdate\0\0timerupdate2\0"
    "on_boy_button_1_clicked\0"
    "on_employee_check_clicked\0"
    "on_girl_button_1_clicked\0"
    "on_cancel_bt_2_clicked\0hide_widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_register1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void register1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        register1 *_t = static_cast<register1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timerupdate(); break;
        case 1: _t->timerupdate2(); break;
        case 2: _t->on_boy_button_1_clicked(); break;
        case 3: _t->on_employee_check_clicked(); break;
        case 4: _t->on_girl_button_1_clicked(); break;
        case 5: _t->on_cancel_bt_2_clicked(); break;
        case 6: _t->hide_widget(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject register1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_register1.data,
      qt_meta_data_register1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *register1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *register1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_register1.stringdata0))
        return static_cast<void*>(const_cast< register1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int register1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

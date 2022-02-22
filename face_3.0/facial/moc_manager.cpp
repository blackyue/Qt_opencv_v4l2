/****************************************************************************
** Meta object code from reading C++ file 'manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_manager_t {
    QByteArrayData data[7];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_manager_t qt_meta_stringdata_manager = {
    {
QT_MOC_LITERAL(0, 0, 7), // "manager"
QT_MOC_LITERAL(1, 8, 26), // "on_return_button_1_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_return_button_2_clicked"
QT_MOC_LITERAL(4, 63, 26), // "on_return_button_3_clicked"
QT_MOC_LITERAL(5, 90, 19), // "on_check_bt_clicked"
QT_MOC_LITERAL(6, 110, 17) // "on_all_bt_clicked"

    },
    "manager\0on_return_button_1_clicked\0\0"
    "on_return_button_2_clicked\0"
    "on_return_button_3_clicked\0"
    "on_check_bt_clicked\0on_all_bt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_manager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        manager *_t = static_cast<manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_return_button_1_clicked(); break;
        case 1: _t->on_return_button_2_clicked(); break;
        case 2: _t->on_return_button_3_clicked(); break;
        case 3: _t->on_check_bt_clicked(); break;
        case 4: _t->on_all_bt_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject manager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_manager.data,
      qt_meta_data_manager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *manager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_manager.stringdata0))
        return static_cast<void*>(const_cast< manager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

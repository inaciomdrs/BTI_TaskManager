/****************************************************************************
** Meta object code from reading C++ file 'tabthree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tabthree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabthree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabThree_t {
    QByteArrayData data[13];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabThree_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabThree_t qt_meta_stringdata_TabThree = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TabThree"
QT_MOC_LITERAL(1, 9, 14), // "updateGUITable"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "timerEvent"
QT_MOC_LITERAL(4, 36, 12), // "QTimerEvent*"
QT_MOC_LITERAL(5, 49, 5), // "event"
QT_MOC_LITERAL(6, 55, 11), // "changeTimer"
QT_MOC_LITERAL(7, 67, 5), // "value"
QT_MOC_LITERAL(8, 73, 5), // "getNC"
QT_MOC_LITERAL(9, 79, 11), // "const char*"
QT_MOC_LITERAL(10, 91, 7), // "getMemo"
QT_MOC_LITERAL(11, 99, 9), // "getModelo"
QT_MOC_LITERAL(12, 109, 9) // "getNomeSO"

    },
    "TabThree\0updateGUITable\0\0timerEvent\0"
    "QTimerEvent*\0event\0changeTimer\0value\0"
    "getNC\0const char*\0getMemo\0getModelo\0"
    "getNomeSO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabThree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,
      11,    0,   58,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    0x80000000 | 9,
    0x80000000 | 9,
    0x80000000 | 9,
    0x80000000 | 9,

       0        // eod
};

void TabThree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabThree *_t = static_cast<TabThree *>(_o);
        switch (_id) {
        case 0: _t->updateGUITable(); break;
        case 1: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 2: _t->changeTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { const char* _r = _t->getNC();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 4: { const char* _r = _t->getMemo();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 5: { const char* _r = _t->getModelo();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        case 6: { const char* _r = _t->getNomeSO();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TabThree::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabThree::updateGUITable)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TabThree::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TabThree.data,
      qt_meta_data_TabThree,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabThree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabThree::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabThree.stringdata))
        return static_cast<void*>(const_cast< TabThree*>(this));
    if (!strcmp(_clname, "Thread"))
        return static_cast< Thread*>(const_cast< TabThree*>(this));
    return QObject::qt_metacast(_clname);
}

int TabThree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TabThree::updateGUITable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

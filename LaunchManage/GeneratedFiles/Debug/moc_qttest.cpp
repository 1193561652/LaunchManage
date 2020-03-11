/****************************************************************************
** Meta object code from reading C++ file 'qttest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qttest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qttest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtTest_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtTest_t qt_meta_stringdata_QtTest = {
    {
QT_MOC_LITERAL(0, 0, 6), // "QtTest"
QT_MOC_LITERAL(1, 7, 7), // "signal1"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "btnClick"
QT_MOC_LITERAL(4, 25, 16), // "directoryChanged"
QT_MOC_LITERAL(5, 42, 11), // "fileChanged"
QT_MOC_LITERAL(6, 54, 11), // "itemChanged"
QT_MOC_LITERAL(7, 66, 14), // "QStandardItem*"
QT_MOC_LITERAL(8, 81, 4) // "item"

    },
    "QtTest\0signal1\0\0btnClick\0directoryChanged\0"
    "fileChanged\0itemChanged\0QStandardItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    1,   41,    2, 0x09 /* Protected */,
       5,    1,   44,    2, 0x09 /* Protected */,
       6,    1,   47,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void QtTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtTest *_t = static_cast<QtTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal1(); break;
        case 1: _t->btnClick(); break;
        case 2: _t->directoryChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->fileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->itemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtTest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtTest::signal1)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtTest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtTest.data,
      qt_meta_data_QtTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtTest.stringdata0))
        return static_cast<void*>(const_cast< QtTest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QtTest::signal1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'fiveGo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fiveGo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fiveGo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fiveGo_t {
    QByteArrayData data[18];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fiveGo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fiveGo_t qt_meta_stringdata_fiveGo = {
    {
QT_MOC_LITERAL(0, 0, 6), // "fiveGo"
QT_MOC_LITERAL(1, 7, 7), // "isWiner"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "MyChess"
QT_MOC_LITERAL(4, 24, 34), // "QList<std::pair<MyPoint,MyChe..."
QT_MOC_LITERAL(5, 59, 9), // "drawPoint"
QT_MOC_LITERAL(6, 69, 7), // "MyPoint"
QT_MOC_LITERAL(7, 77, 8), // "startOne"
QT_MOC_LITERAL(8, 86, 10), // "loadMunual"
QT_MOC_LITERAL(9, 97, 7), // "on_load"
QT_MOC_LITERAL(10, 105, 8), // "on_start"
QT_MOC_LITERAL(11, 114, 9), // "on_defult"
QT_MOC_LITERAL(12, 124, 10), // "on_nowflag"
QT_MOC_LITERAL(13, 135, 5), // "point"
QT_MOC_LITERAL(14, 141, 11), // "on_getPoint"
QT_MOC_LITERAL(15, 153, 11), // "on_getStrat"
QT_MOC_LITERAL(16, 165, 2), // "ip"
QT_MOC_LITERAL(17, 168, 14) // "on_getStratRes"

    },
    "fiveGo\0isWiner\0\0MyChess\0"
    "QList<std::pair<MyPoint,MyChess> >\0"
    "drawPoint\0MyPoint\0startOne\0loadMunual\0"
    "on_load\0on_start\0on_defult\0on_nowflag\0"
    "point\0on_getPoint\0on_getStrat\0ip\0"
    "on_getStratRes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fiveGo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      15,    1,   92,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,   13,
    QMetaType::Void, 0x80000000 | 6,   13,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void fiveGo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fiveGo *_t = static_cast<fiveGo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isWiner((*reinterpret_cast< MyChess(*)>(_a[1])),(*reinterpret_cast< QList<std::pair<MyPoint,MyChess> >(*)>(_a[2]))); break;
        case 1: _t->drawPoint((*reinterpret_cast< MyPoint(*)>(_a[1])),(*reinterpret_cast< MyChess(*)>(_a[2]))); break;
        case 2: _t->startOne(); break;
        case 3: _t->loadMunual((*reinterpret_cast< QList<std::pair<MyPoint,MyChess> >(*)>(_a[1]))); break;
        case 4: _t->on_load(); break;
        case 5: _t->on_start(); break;
        case 6: _t->on_defult(); break;
        case 7: _t->on_nowflag((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 8: _t->on_getPoint((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 9: _t->on_getStrat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->on_getStratRes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (fiveGo::*_t)(MyChess , QList<std::pair<MyPoint,MyChess>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::isWiner)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (fiveGo::*_t)(MyPoint , MyChess );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::drawPoint)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (fiveGo::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::startOne)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (fiveGo::*_t)(QList<std::pair<MyPoint,MyChess>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::loadMunual)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject fiveGo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fiveGo.data,
      qt_meta_data_fiveGo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *fiveGo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fiveGo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fiveGo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int fiveGo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void fiveGo::isWiner(MyChess _t1, QList<std::pair<MyPoint,MyChess>> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fiveGo::drawPoint(MyPoint _t1, MyChess _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void fiveGo::startOne()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void fiveGo::loadMunual(QList<std::pair<MyPoint,MyChess>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

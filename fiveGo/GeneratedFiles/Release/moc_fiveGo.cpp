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
    QByteArrayData data[22];
    char stringdata0[214];
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
QT_MOC_LITERAL(8, 86, 8), // "startTwo"
QT_MOC_LITERAL(9, 95, 10), // "loadMunual"
QT_MOC_LITERAL(10, 106, 7), // "on_load"
QT_MOC_LITERAL(11, 114, 8), // "on_start"
QT_MOC_LITERAL(12, 123, 9), // "on_defult"
QT_MOC_LITERAL(13, 133, 10), // "on_nowflag"
QT_MOC_LITERAL(14, 144, 5), // "point"
QT_MOC_LITERAL(15, 150, 11), // "on_getPoint"
QT_MOC_LITERAL(16, 162, 11), // "on_getStrat"
QT_MOC_LITERAL(17, 174, 2), // "ip"
QT_MOC_LITERAL(18, 177, 14), // "on_getStratRes"
QT_MOC_LITERAL(19, 192, 9), // "on_getMsg"
QT_MOC_LITERAL(20, 202, 3), // "msg"
QT_MOC_LITERAL(21, 206, 7) // "on_send"

    },
    "fiveGo\0isWiner\0\0MyChess\0"
    "QList<std::pair<MyPoint,MyChess> >\0"
    "drawPoint\0MyPoint\0startOne\0startTwo\0"
    "loadMunual\0on_load\0on_start\0on_defult\0"
    "on_nowflag\0point\0on_getPoint\0on_getStrat\0"
    "ip\0on_getStratRes\0on_getMsg\0msg\0on_send"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fiveGo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   99,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      16,    1,  108,    2, 0x0a /* Public */,
      18,    1,  111,    2, 0x0a /* Public */,
      19,    1,  114,    2, 0x0a /* Public */,
      21,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,   14,
    QMetaType::Void, 0x80000000 | 6,   14,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

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
        case 3: _t->startTwo(); break;
        case 4: _t->loadMunual((*reinterpret_cast< QList<std::pair<MyPoint,MyChess> >(*)>(_a[1]))); break;
        case 5: _t->on_load(); break;
        case 6: _t->on_start(); break;
        case 7: _t->on_defult(); break;
        case 8: _t->on_nowflag((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 9: _t->on_getPoint((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 10: _t->on_getStrat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_getStratRes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_getMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->on_send(); break;
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
            typedef void (fiveGo::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::startTwo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (fiveGo::*_t)(QList<std::pair<MyPoint,MyChess>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fiveGo::loadMunual)) {
                *result = 4;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
void fiveGo::startTwo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void fiveGo::loadMunual(QList<std::pair<MyPoint,MyChess>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

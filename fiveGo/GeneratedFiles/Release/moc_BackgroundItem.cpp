/****************************************************************************
** Meta object code from reading C++ file 'BackgroundItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BackgroundItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackgroundItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackgroundItem_t {
    QByteArrayData data[13];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackgroundItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackgroundItem_t qt_meta_stringdata_BackgroundItem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BackgroundItem"
QT_MOC_LITERAL(1, 15, 7), // "nowFlag"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "MyPoint"
QT_MOC_LITERAL(4, 32, 10), // "on_isWiner"
QT_MOC_LITERAL(5, 43, 7), // "MyChess"
QT_MOC_LITERAL(6, 51, 1), // "d"
QT_MOC_LITERAL(7, 53, 34), // "QList<std::pair<MyPoint,MyChe..."
QT_MOC_LITERAL(8, 88, 1), // "m"
QT_MOC_LITERAL(9, 90, 12), // "on_drawPoint"
QT_MOC_LITERAL(10, 103, 1), // "p"
QT_MOC_LITERAL(11, 105, 11), // "on_startOne"
QT_MOC_LITERAL(12, 117, 13) // "on_loadMunual"

    },
    "BackgroundItem\0nowFlag\0\0MyPoint\0"
    "on_isWiner\0MyChess\0d\0"
    "QList<std::pair<MyPoint,MyChess> >\0m\0"
    "on_drawPoint\0p\0on_startOne\0on_loadMunual"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackgroundItem[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   42,    2, 0x0a /* Public */,
       9,    2,   47,    2, 0x0a /* Public */,
      11,    0,   52,    2, 0x0a /* Public */,
      12,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,   10,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void BackgroundItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackgroundItem *_t = static_cast<BackgroundItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nowFlag((*reinterpret_cast< MyPoint(*)>(_a[1]))); break;
        case 1: _t->on_isWiner((*reinterpret_cast< MyChess(*)>(_a[1])),(*reinterpret_cast< QList<std::pair<MyPoint,MyChess> >(*)>(_a[2]))); break;
        case 2: _t->on_drawPoint((*reinterpret_cast< MyPoint(*)>(_a[1])),(*reinterpret_cast< MyChess(*)>(_a[2]))); break;
        case 3: _t->on_startOne(); break;
        case 4: _t->on_loadMunual((*reinterpret_cast< QList<std::pair<MyPoint,MyChess> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BackgroundItem::*_t)(MyPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundItem::nowFlag)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BackgroundItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BackgroundItem.data,
      qt_meta_data_BackgroundItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BackgroundItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackgroundItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int BackgroundItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void BackgroundItem::nowFlag(MyPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

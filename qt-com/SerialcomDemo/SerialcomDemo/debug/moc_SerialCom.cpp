/****************************************************************************
** Meta object code from reading C++ file 'SerialCom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SerialCom/SerialCom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialCom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialCom_t {
    QByteArrayData data[6];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialCom_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialCom_t qt_meta_stringdata_SerialCom = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SerialCom"
QT_MOC_LITERAL(1, 10, 13), // "slot_readData"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "slot_HandleError"
QT_MOC_LITERAL(4, 42, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(5, 71, 5) // "error"

    },
    "SerialCom\0slot_readData\0\0slot_HandleError\0"
    "QSerialPort::SerialPortError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialCom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void SerialCom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialCom *_t = static_cast<SerialCom *>(_o);
        switch (_id) {
        case 0: _t->slot_readData(); break;
        case 1: _t->slot_HandleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SerialCom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialCom.data,
      qt_meta_data_SerialCom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialCom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialCom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialCom.stringdata))
        return static_cast<void*>(const_cast< SerialCom*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'PulseSensor.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/data/PulseSensor.hpp"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PulseSensor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_PulseSensor_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[7];
    char stringdata5[41];
    char stringdata6[5];
    char stringdata7[22];
    char stringdata8[6];
    char stringdata9[6];
    char stringdata10[5];
    char stringdata11[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PulseSensor_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PulseSensor_t qt_meta_stringdata_PulseSensor = {
    {
        QT_MOC_LITERAL(0, 11),  // "PulseSensor"
        QT_MOC_LITERAL(12, 7),  // "sampled"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 19),  // "PulseSensor::Status"
        QT_MOC_LITERAL(41, 6),  // "status"
        QT_MOC_LITERAL(48, 40),  // "std::optional<std::chrono::mi..."
        QT_MOC_LITERAL(89, 4),  // "time"
        QT_MOC_LITERAL(94, 21),  // "std::optional<double>"
        QT_MOC_LITERAL(116, 5),  // "pulse"
        QT_MOC_LITERAL(122, 5),  // "start"
        QT_MOC_LITERAL(128, 4),  // "stop"
        QT_MOC_LITERAL(133, 8)   // "on_timer"
    },
    "PulseSensor",
    "sampled",
    "",
    "PulseSensor::Status",
    "status",
    "std::optional<std::chrono::milliseconds>",
    "time",
    "std::optional<double>",
    "pulse",
    "start",
    "stop",
    "on_timer"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PulseSensor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   45,    2, 0x0a,    5 /* Public */,
      10,    0,   46,    2, 0x0a,    6 /* Public */,
      11,    0,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PulseSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PulseSensor.offsetsAndSizes,
    qt_meta_data_PulseSensor,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PulseSensor_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PulseSensor, std::true_type>,
        // method 'sampled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PulseSensor::Status, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::optional<std::chrono::milliseconds>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::optional<double>, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PulseSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PulseSensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sampled((*reinterpret_cast< std::add_pointer_t<PulseSensor::Status>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::optional<std::chrono::milliseconds>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::optional<double>>>(_a[3]))); break;
        case 1: _t->start(); break;
        case 2: _t->stop(); break;
        case 3: _t->on_timer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PulseSensor::*)(PulseSensor::Status , std::optional<std::chrono::milliseconds> , std::optional<double> );
            if (_t _q_method = &PulseSensor::sampled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PulseSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PulseSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PulseSensor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PulseSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PulseSensor::sampled(PulseSensor::Status _t1, std::optional<std::chrono::milliseconds> _t2, std::optional<double> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

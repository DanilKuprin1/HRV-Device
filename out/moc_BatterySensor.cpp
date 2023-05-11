/****************************************************************************
** Meta object code from reading C++ file 'BatterySensor.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/data/BatterySensor.hpp"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BatterySensor.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_BatterySensor_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[17];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_BatterySensor_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_BatterySensor_t qt_meta_stringdata_BatterySensor = {
    {
        QT_MOC_LITERAL(0, 13),  // "BatterySensor"
        QT_MOC_LITERAL(14, 13),  // "level_changed"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "level"
        QT_MOC_LITERAL(35, 16),  // "fully_discharged"
        QT_MOC_LITERAL(52, 5),  // "start"
        QT_MOC_LITERAL(58, 4),  // "stop"
        QT_MOC_LITERAL(63, 8)   // "on_timer"
    },
    "BatterySensor",
    "level_changed",
    "",
    "level",
    "fully_discharged",
    "start",
    "stop",
    "on_timer"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_BatterySensor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    0,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   48,    2, 0x0a,    4 /* Public */,
       6,    0,   49,    2, 0x0a,    5 /* Public */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BatterySensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BatterySensor.offsetsAndSizes,
    qt_meta_data_BatterySensor,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_BatterySensor_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BatterySensor, std::true_type>,
        // method 'level_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'fully_discharged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BatterySensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BatterySensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->level_changed((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->fully_discharged(); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->on_timer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BatterySensor::*)(double );
            if (_t _q_method = &BatterySensor::level_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BatterySensor::*)();
            if (_t _q_method = &BatterySensor::fully_discharged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *BatterySensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatterySensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BatterySensor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BatterySensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BatterySensor::level_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BatterySensor::fully_discharged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

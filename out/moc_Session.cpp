/****************************************************************************
** Meta object code from reading C++ file 'Session.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/Session.hpp"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Session.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_Session_t {
    uint offsetsAndSizes[12];
    char stringdata0[8];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[6];
    char stringdata5[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Session_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Session_t qt_meta_stringdata_Session = {
    {
        QT_MOC_LITERAL(0, 7),  // "Session"
        QT_MOC_LITERAL(8, 7),  // "started"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 5),  // "ended"
        QT_MOC_LITERAL(23, 5),  // "start"
        QT_MOC_LITERAL(29, 3)   // "end"
    },
    "Session",
    "started",
    "",
    "ended",
    "start",
    "end"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Session[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x106,    1 /* Public | MethodIsConst  */,
       3,    0,   39,    2, 0x106,    2 /* Public | MethodIsConst  */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   40,    2, 0x0a,    3 /* Public */,
       5,    0,   41,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Session::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Session.offsetsAndSizes,
    qt_meta_data_Session,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Session_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Session, std::true_type>,
        // method 'started'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'end'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Session::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Session *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->ended(); break;
        case 2: _t->start(); break;
        case 3: _t->end(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Session::*)() const;
            if (_t _q_method = &Session::started; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Session::*)() const;
            if (_t _q_method = &Session::ended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *Session::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Session::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Session.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Session::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Session::started()const
{
    QMetaObject::activate(const_cast< Session *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Session::ended()const
{
    QMetaObject::activate(const_cast< Session *>(this), &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

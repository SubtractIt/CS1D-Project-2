/****************************************************************************
** Meta object code from reading C++ file 'admin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Colleges/admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Admin_t {
    const uint offsetsAndSize[16];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Admin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Admin_t qt_meta_stringdata_Admin = {
    {
QT_MOC_LITERAL(0, 5), // "Admin"
QT_MOC_LITERAL(6, 34), // "on_collegeEdit_currentIndexCh..."
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 4), // "arg1"
QT_MOC_LITERAL(47, 18), // "on_addSouv_clicked"
QT_MOC_LITERAL(66, 21), // "on_deleteSouv_clicked"
QT_MOC_LITERAL(88, 21), // "on_modifySouv_clicked"
QT_MOC_LITERAL(110, 17) // "on_upload_clicked"

    },
    "Admin\0on_collegeEdit_currentIndexChanged\0"
    "\0arg1\0on_addSouv_clicked\0on_deleteSouv_clicked\0"
    "on_modifySouv_clicked\0on_upload_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Admin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    0,   47,    2, 0x08,    3 /* Private */,
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Admin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_collegeEdit_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_addSouv_clicked(); break;
        case 2: _t->on_deleteSouv_clicked(); break;
        case 3: _t->on_modifySouv_clicked(); break;
        case 4: _t->on_upload_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Admin::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Admin.offsetsAndSize,
    qt_meta_data_Admin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Admin_t
, QtPrivate::TypeAndForceComplete<Admin, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Admin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'PasswordChangeScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/PasswordChangeScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PasswordChangeScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PasswordChangeScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   40,   40,   40, 0x08,
      41,   40,   40,   40, 0x08,
      64,   40,   40,   40, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PasswordChangeScreen[] = {
    "PasswordChangeScreen\0on_close_clicked()\0"
    "\0on_potwierdz_clicked()\0"
    "mousePressEvent(QMouseEvent*)\0"
};

void PasswordChangeScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PasswordChangeScreen *_t = static_cast<PasswordChangeScreen *>(_o);
        switch (_id) {
        case 0: _t->on_close_clicked(); break;
        case 1: _t->on_potwierdz_clicked(); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PasswordChangeScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PasswordChangeScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PasswordChangeScreen,
      qt_meta_data_PasswordChangeScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PasswordChangeScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PasswordChangeScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PasswordChangeScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PasswordChangeScreen))
        return static_cast<void*>(const_cast< PasswordChangeScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int PasswordChangeScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

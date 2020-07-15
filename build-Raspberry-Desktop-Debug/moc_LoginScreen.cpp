/****************************************************************************
** Meta object code from reading C++ file 'LoginScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/LoginScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   32,   32,   32, 0x08,
      33,   32,   32,   32, 0x08,
      54,   84,   32,   32, 0x08,
      90,  120,  122,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoginScreen[] = {
    "LoginScreen\0on_powrot_clicked()\0\0"
    "on_zaloguj_clicked()\0mousePressEvent(QMouseEvent*)\0"
    "event\0eventFilter(QObject*,QEvent*)\0"
    ",\0bool\0"
};

void LoginScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoginScreen *_t = static_cast<LoginScreen *>(_o);
        switch (_id) {
        case 0: _t->on_powrot_clicked(); break;
        case 1: _t->on_zaloguj_clicked(); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoginScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoginScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoginScreen,
      qt_meta_data_LoginScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginScreen))
        return static_cast<void*>(const_cast< LoginScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoginScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'LoggedScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/LoggedScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoggedScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoggedScreen[] = {

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
      13,   34,   34,   34, 0x08,
      35,   34,   34,   34, 0x08,
      58,   34,   34,   34, 0x08,
      81,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoggedScreen[] = {
    "LoggedScreen\0on_wyloguj_clicked()\0\0"
    "on_kupKarnet_clicked()\0on_zmienDane_clicked()\0"
    "odbierzZmianeDanych()\0"
};

void LoggedScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoggedScreen *_t = static_cast<LoggedScreen *>(_o);
        switch (_id) {
        case 0: _t->on_wyloguj_clicked(); break;
        case 1: _t->on_kupKarnet_clicked(); break;
        case 2: _t->on_zmienDane_clicked(); break;
        case 3: _t->odbierzZmianeDanych(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LoggedScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoggedScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoggedScreen,
      qt_meta_data_LoggedScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoggedScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoggedScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoggedScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoggedScreen))
        return static_cast<void*>(const_cast< LoggedScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoggedScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

/****************************************************************************
** Meta object code from reading C++ file 'OnlinePaymentScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OnlinePaymentScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OnlinePaymentScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OnlinePaymentScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   29,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x08,
      50,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OnlinePaymentScreen[] = {
    "OnlinePaymentScreen\0drukuj()\0\0"
    "on_anuluj_clicked()\0on_zaplacono_clicked()\0"
};

void OnlinePaymentScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OnlinePaymentScreen *_t = static_cast<OnlinePaymentScreen *>(_o);
        switch (_id) {
        case 0: _t->drukuj(); break;
        case 1: _t->on_anuluj_clicked(); break;
        case 2: _t->on_zaplacono_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OnlinePaymentScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OnlinePaymentScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OnlinePaymentScreen,
      qt_meta_data_OnlinePaymentScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OnlinePaymentScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OnlinePaymentScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OnlinePaymentScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OnlinePaymentScreen))
        return static_cast<void*>(const_cast< OnlinePaymentScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int OnlinePaymentScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void OnlinePaymentScreen::drukuj()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

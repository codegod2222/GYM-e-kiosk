/****************************************************************************
** Meta object code from reading C++ file 'ConfirmPurchaseScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/ConfirmPurchaseScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfirmPurchaseScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfirmPurchaseScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   44,   44,   44, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   44,   44,   44, 0x08,
      68,  124,   44,   44, 0x08,
     148,   44,   44,   44, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfirmPurchaseScreen[] = {
    "ConfirmPurchaseScreen\0wyslijPotwierdzenie()\0"
    "\0on_potwierdz_clicked()\0"
    "odbierzDane(SubscriptionType,QString,BuyingPassScreen*)\0"
    "karnet,rodzajPlatnosci,\0on_close_clicked()\0"
};

void ConfirmPurchaseScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfirmPurchaseScreen *_t = static_cast<ConfirmPurchaseScreen *>(_o);
        switch (_id) {
        case 0: _t->wyslijPotwierdzenie(); break;
        case 1: _t->on_potwierdz_clicked(); break;
        case 2: _t->odbierzDane((*reinterpret_cast< SubscriptionType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< BuyingPassScreen*(*)>(_a[3]))); break;
        case 3: _t->on_close_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConfirmPurchaseScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConfirmPurchaseScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfirmPurchaseScreen,
      qt_meta_data_ConfirmPurchaseScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfirmPurchaseScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfirmPurchaseScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfirmPurchaseScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmPurchaseScreen))
        return static_cast<void*>(const_cast< ConfirmPurchaseScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfirmPurchaseScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ConfirmPurchaseScreen::wyslijPotwierdzenie()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

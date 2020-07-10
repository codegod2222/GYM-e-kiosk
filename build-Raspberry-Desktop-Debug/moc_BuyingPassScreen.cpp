/****************************************************************************
** Meta object code from reading C++ file 'BuyingPassScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/BuyingPassScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BuyingPassScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BuyingPassScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   87,  111,  111, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,  111,  111,  111, 0x08,
     132,  111,  111,  111, 0x08,
     153,  111,  111,  111, 0x08,
     172,  111,  111,  111, 0x08,
     192,  233,  111,  111, 0x08,
     235,  111,  111,  111, 0x08,
     258,  111,  111,  111, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BuyingPassScreen[] = {
    "BuyingPassScreen\0"
    "wyslijDaneDoPotwierdzenia(SubscriptionType,QString,BuyingPassScreen*)\0"
    "karnet,rodzajPlatnosci,\0\0on_powrot_clicked()\0"
    "on_gotowka_clicked()\0on_karta_clicked()\0"
    "on_online_clicked()\0"
    "potwierdzZakup(SubscriptionType,QString)\0"
    ",\0odbierzPotwierdzenie()\0drukuj2()\0"
};

void BuyingPassScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BuyingPassScreen *_t = static_cast<BuyingPassScreen *>(_o);
        switch (_id) {
        case 0: _t->wyslijDaneDoPotwierdzenia((*reinterpret_cast< SubscriptionType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< BuyingPassScreen*(*)>(_a[3]))); break;
        case 1: _t->on_powrot_clicked(); break;
        case 2: _t->on_gotowka_clicked(); break;
        case 3: _t->on_karta_clicked(); break;
        case 4: _t->on_online_clicked(); break;
        case 5: _t->potwierdzZakup((*reinterpret_cast< SubscriptionType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->odbierzPotwierdzenie(); break;
        case 7: _t->drukuj2(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BuyingPassScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BuyingPassScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BuyingPassScreen,
      qt_meta_data_BuyingPassScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BuyingPassScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BuyingPassScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BuyingPassScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BuyingPassScreen))
        return static_cast<void*>(const_cast< BuyingPassScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int BuyingPassScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BuyingPassScreen::wyslijDaneDoPotwierdzenia(SubscriptionType _t1, QString _t2, BuyingPassScreen * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

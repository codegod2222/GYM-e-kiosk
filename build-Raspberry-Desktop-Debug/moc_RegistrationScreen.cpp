/****************************************************************************
** Meta object code from reading C++ file 'RegistrationScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Raspberry QT/RegistrationScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegistrationScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegistrationScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   39,   39,   39, 0x08,
      40,   39,   39,   39, 0x08,
      64,   39,   39,   39, 0x08,
      94,  124,  126,   39, 0x08,
     131,   39,   39,   39, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RegistrationScreen[] = {
    "RegistrationScreen\0on_powrot_clicked()\0"
    "\0on_pushButton_clicked()\0"
    "mousePressEvent(QMouseEvent*)\0"
    "eventFilter(QObject*,QEvent*)\0,\0bool\0"
    "on_dodajZdjecie_clicked()\0"
};

void RegistrationScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegistrationScreen *_t = static_cast<RegistrationScreen *>(_o);
        switch (_id) {
        case 0: _t->on_powrot_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->on_dodajZdjecie_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegistrationScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegistrationScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RegistrationScreen,
      qt_meta_data_RegistrationScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegistrationScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegistrationScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegistrationScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegistrationScreen))
        return static_cast<void*>(const_cast< RegistrationScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int RegistrationScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'DataChangeScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DataChangeScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataChangeScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataChangeScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   38,   38,   38, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   38,   38,   38, 0x08,
      59,   38,   38,   38, 0x08,
      88,   38,   38,   38, 0x08,
     112,   38,   38,   38, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataChangeScreen[] = {
    "DataChangeScreen\0wyslijZmianeDanych()\0"
    "\0on_powrot_clicked()\0on_zatwierdzZmiany_clicked()\0"
    "on_zmienHaslo_clicked()\0"
    "mousePressEvent(QMouseEvent*)\0"
};

void DataChangeScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataChangeScreen *_t = static_cast<DataChangeScreen *>(_o);
        switch (_id) {
        case 0: _t->wyslijZmianeDanych(); break;
        case 1: _t->on_powrot_clicked(); break;
        case 2: _t->on_zatwierdzZmiany_clicked(); break;
        case 3: _t->on_zmienHaslo_clicked(); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataChangeScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataChangeScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DataChangeScreen,
      qt_meta_data_DataChangeScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataChangeScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataChangeScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataChangeScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataChangeScreen))
        return static_cast<void*>(const_cast< DataChangeScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int DataChangeScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void DataChangeScreen::wyslijZmianeDanych()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

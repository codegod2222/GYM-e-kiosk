/****************************************************************************
** Meta object code from reading C++ file 'ClubMembersScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ClubMembersScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClubMembersScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClubMembersScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   48,   50,   55, 0x08,
      56,   55,   55,   55, 0x08,
      71,   55,   55,   55, 0x08,
      97,   55,   55,   55, 0x08,
     122,   55,   55,   55, 0x08,
     149,   55,   55,   55, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClubMembersScreen[] = {
    "ClubMembersScreen\0eventFilter(QObject*,QEvent*)\0"
    ",\0bool\0\0refreshTable()\0on_dodajCzlonka_clicked()\0"
    "on_usunCzlonka_clicked()\0"
    "on_edytujCzlonka_clicked()\0"
    "on_powrot_clicked()\0"
};

void ClubMembersScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClubMembersScreen *_t = static_cast<ClubMembersScreen *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->refreshTable(); break;
        case 2: _t->on_dodajCzlonka_clicked(); break;
        case 3: _t->on_usunCzlonka_clicked(); break;
        case 4: _t->on_edytujCzlonka_clicked(); break;
        case 5: _t->on_powrot_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClubMembersScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClubMembersScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClubMembersScreen,
      qt_meta_data_ClubMembersScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClubMembersScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClubMembersScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClubMembersScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClubMembersScreen))
        return static_cast<void*>(const_cast< ClubMembersScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClubMembersScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

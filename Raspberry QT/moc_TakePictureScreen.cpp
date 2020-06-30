/****************************************************************************
** Meta object code from reading C++ file 'TakePictureScreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TakePictureScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TakePictureScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TakePictureScreen[] = {

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
      18,   30,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   52,   30,   30, 0x08,
      58,   30,   30,   30, 0x08,
      80,   30,   30,   30, 0x08,
      98,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TakePictureScreen[] = {
    "TakePictureScreen\0takePhoto()\0\0"
    "handleImage(QImage&)\0image\0"
    "on_btnStart_clicked()\0on_OK_2_clicked()\0"
    "on_OK_clicked()\0"
};

void TakePictureScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TakePictureScreen *_t = static_cast<TakePictureScreen *>(_o);
        switch (_id) {
        case 0: _t->takePhoto(); break;
        case 1: _t->handleImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->on_btnStart_clicked(); break;
        case 3: _t->on_OK_2_clicked(); break;
        case 4: _t->on_OK_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TakePictureScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TakePictureScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TakePictureScreen,
      qt_meta_data_TakePictureScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TakePictureScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TakePictureScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TakePictureScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TakePictureScreen))
        return static_cast<void*>(const_cast< TakePictureScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int TakePictureScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void TakePictureScreen::takePhoto()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

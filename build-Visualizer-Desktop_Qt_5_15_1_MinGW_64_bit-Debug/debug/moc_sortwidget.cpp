/****************************************************************************
** Meta object code from reading C++ file 'sortwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Visualizer/sortwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SortWidget_t {
    QByteArrayData data[12];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SortWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SortWidget_t qt_meta_stringdata_SortWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SortWidget"
QT_MOC_LITERAL(1, 11, 22), // "on_slider_valueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "value"
QT_MOC_LITERAL(4, 41, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 63, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(6, 86, 27), // "on_delaySlider_valueChanged"
QT_MOC_LITERAL(7, 114, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(8, 136, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(9, 158, 33), // "on_chooseData_currentIndexCha..."
QT_MOC_LITERAL(10, 192, 5), // "index"
QT_MOC_LITERAL(11, 198, 35) // "on_choosePoints_currentIndexC..."

    },
    "SortWidget\0on_slider_valueChanged\0\0"
    "value\0on_pushButton_clicked\0"
    "on_resetButton_clicked\0"
    "on_delaySlider_valueChanged\0"
    "on_stopButton_clicked\0on_quitButton_clicked\0"
    "on_chooseData_currentIndexChanged\0"
    "index\0on_choosePoints_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SortWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      11,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void SortWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SortWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_resetButton_clicked(); break;
        case 3: _t->on_delaySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_stopButton_clicked(); break;
        case 5: _t->on_quitButton_clicked(); break;
        case 6: _t->on_chooseData_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_choosePoints_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SortWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SortWidget.data,
    qt_meta_data_SortWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SortWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SortWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SortWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

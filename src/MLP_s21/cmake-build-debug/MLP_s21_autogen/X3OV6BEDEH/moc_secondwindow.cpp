/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../graphics/headers/secondwindow.hpp"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_secondWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[13];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[20];
    char stringdata5[7];
    char stringdata6[22];
    char stringdata7[11];
    char stringdata8[24];
    char stringdata9[39];
    char stringdata10[6];
    char stringdata11[28];
    char stringdata12[40];
    char stringdata13[27];
    char stringdata14[12];
    char stringdata15[13];
    char stringdata16[37];
    char stringdata17[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_secondWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_secondWindow_t qt_meta_stringdata_secondWindow = {
    {
        QT_MOC_LITERAL(0, 12),  // "secondWindow"
        QT_MOC_LITERAL(13, 8),  // "testDone"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 9),  // "trainDone"
        QT_MOC_LITERAL(33, 19),  // "std::vector<double>"
        QT_MOC_LITERAL(53, 6),  // "values"
        QT_MOC_LITERAL(60, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(82, 10),  // "save_image"
        QT_MOC_LITERAL(93, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(117, 38),  // "on_horizontalSlider_layer_val..."
        QT_MOC_LITERAL(156, 5),  // "value"
        QT_MOC_LITERAL(162, 27),  // "on_pushButton_learn_clicked"
        QT_MOC_LITERAL(190, 39),  // "on_horizontalSlider_epochs_va..."
        QT_MOC_LITERAL(230, 26),  // "on_pushButton_test_clicked"
        QT_MOC_LITERAL(257, 11),  // "showTestWin"
        QT_MOC_LITERAL(269, 12),  // "showTrainWin"
        QT_MOC_LITERAL(282, 36),  // "on_crossValidationCheck_state..."
        QT_MOC_LITERAL(319, 4)   // "arg1"
    },
    "secondWindow",
    "testDone",
    "",
    "trainDone",
    "std::vector<double>",
    "values",
    "on_pushButton_clicked",
    "save_image",
    "on_pushButton_2_clicked",
    "on_horizontalSlider_layer_valueChanged",
    "value",
    "on_pushButton_learn_clicked",
    "on_horizontalSlider_epochs_valueChanged",
    "on_pushButton_test_clicked",
    "showTestWin",
    "showTrainWin",
    "on_crossValidationCheck_stateChanged",
    "arg1"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_secondWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    1,   87,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   90,    2, 0x08,    4 /* Private */,
       7,    0,   91,    2, 0x08,    5 /* Private */,
       8,    0,   92,    2, 0x08,    6 /* Private */,
       9,    1,   93,    2, 0x08,    7 /* Private */,
      11,    0,   96,    2, 0x08,    9 /* Private */,
      12,    1,   97,    2, 0x08,   10 /* Private */,
      13,    0,  100,    2, 0x08,   12 /* Private */,
      14,    0,  101,    2, 0x08,   13 /* Private */,
      15,    1,  102,    2, 0x08,   14 /* Private */,
      16,    1,  105,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject secondWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_secondWindow.offsetsAndSizes,
    qt_meta_data_secondWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_secondWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<secondWindow, std::true_type>,
        // method 'testDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trainDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_image'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_layer_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_learn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_epochs_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_test_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTestWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTrainWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        // method 'on_crossValidationCheck_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void secondWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<secondWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testDone(); break;
        case 1: _t->trainDone((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->save_image(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_horizontalSlider_layer_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_pushButton_learn_clicked(); break;
        case 7: _t->on_horizontalSlider_epochs_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_pushButton_test_clicked(); break;
        case 9: _t->showTestWin(); break;
        case 10: _t->showTrainWin((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1]))); break;
        case 11: _t->on_crossValidationCheck_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (secondWindow::*)();
            if (_t _q_method = &secondWindow::testDone; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (secondWindow::*)(const std::vector<double> & );
            if (_t _q_method = &secondWindow::trainDone; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *secondWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *secondWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_secondWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int secondWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void secondWindow::testDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void secondWindow::trainDone(const std::vector<double> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

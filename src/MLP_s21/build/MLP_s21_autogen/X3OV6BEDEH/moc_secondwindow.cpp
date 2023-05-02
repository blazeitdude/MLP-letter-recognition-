/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../graphics/headers/secondwindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__secondWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__secondWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__secondWindow_t qt_meta_stringdata_s21__secondWindow = {
    {
QT_MOC_LITERAL(0, 17), // "s21::secondWindow"
QT_MOC_LITERAL(18, 8), // "testDone"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 9), // "trainDone"
QT_MOC_LITERAL(38, 19), // "std::vector<double>"
QT_MOC_LITERAL(58, 6), // "values"
QT_MOC_LITERAL(65, 27), // "on_pushButton_learn_clicked"
QT_MOC_LITERAL(93, 26), // "on_pushButton_test_clicked"
QT_MOC_LITERAL(120, 11), // "showTestWin"
QT_MOC_LITERAL(132, 12), // "showTrainWin"
QT_MOC_LITERAL(145, 26), // "on_saveImageButton_clicked"
QT_MOC_LITERAL(172, 28), // "on_uploadImageButton_clicked"
QT_MOC_LITERAL(201, 28), // "on_saveWeightsButton_clicked"
QT_MOC_LITERAL(230, 30), // "on_uploadWeightsButton_clicked"
QT_MOC_LITERAL(261, 29) // "on_settingsPushButton_clicked"

    },
    "s21::secondWindow\0testDone\0\0trainDone\0"
    "std::vector<double>\0values\0"
    "on_pushButton_learn_clicked\0"
    "on_pushButton_test_clicked\0showTestWin\0"
    "showTrainWin\0on_saveImageButton_clicked\0"
    "on_uploadImageButton_clicked\0"
    "on_saveWeightsButton_clicked\0"
    "on_uploadWeightsButton_clicked\0"
    "on_settingsPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__secondWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   84,    2, 0x08,    4 /* Private */,
       7,    0,   85,    2, 0x08,    5 /* Private */,
       8,    0,   86,    2, 0x08,    6 /* Private */,
       9,    1,   87,    2, 0x08,    7 /* Private */,
      10,    0,   90,    2, 0x08,    9 /* Private */,
      11,    0,   91,    2, 0x08,   10 /* Private */,
      12,    0,   92,    2, 0x08,   11 /* Private */,
      13,    0,   93,    2, 0x08,   12 /* Private */,
      14,    0,   94,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void s21::secondWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<secondWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testDone(); break;
        case 1: _t->trainDone((*reinterpret_cast< const std::vector<double>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_learn_clicked(); break;
        case 3: _t->on_pushButton_test_clicked(); break;
        case 4: _t->showTestWin(); break;
        case 5: _t->showTrainWin((*reinterpret_cast< const std::vector<double>(*)>(_a[1]))); break;
        case 6: _t->on_saveImageButton_clicked(); break;
        case 7: _t->on_uploadImageButton_clicked(); break;
        case 8: _t->on_saveWeightsButton_clicked(); break;
        case 9: _t->on_uploadWeightsButton_clicked(); break;
        case 10: _t->on_settingsPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (secondWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&secondWindow::testDone)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (secondWindow::*)(const std::vector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&secondWindow::trainDone)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject s21::secondWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_s21__secondWindow.offsetsAndSize,
    qt_meta_data_s21__secondWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__secondWindow_t
, QtPrivate::TypeAndForceComplete<secondWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::secondWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::secondWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__secondWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int s21::secondWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void s21::secondWindow::testDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void s21::secondWindow::trainDone(const std::vector<double> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

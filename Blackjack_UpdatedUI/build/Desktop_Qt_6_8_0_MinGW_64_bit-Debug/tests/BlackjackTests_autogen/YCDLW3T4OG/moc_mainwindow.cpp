/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmainWindowENDCLASS = QtMocHelpers::stringData(
    "mainWindow",
    "showErrorMessage",
    "",
    "message",
    "updateBetDisplay",
    "bet",
    "onOneDollarBet",
    "onFiveDollarBet",
    "onTenDollarBet",
    "onTwentyDollarBet",
    "onHundredDollarBet",
    "updateBalanceDisplay",
    "onSubmitBet",
    "displayPlayerHand",
    "onHitButtonClicked",
    "animateCardToWidget",
    "QWidget*",
    "targetWidget",
    "cardPath",
    "width",
    "height",
    "animateDealerCardToWidget",
    "faceDown",
    "displayDealerHand",
    "onDoubleDownButton",
    "onStandButton",
    "dealerStandStep",
    "onEndGame",
    "clearCardsDisplayed",
    "on_horizontalSlider_valueChanged",
    "value",
    "on_muteButton_clicked",
    "checked",
    "updateUserHandValDisplay",
    "updateDealerHandValDisplay",
    "updateSplitHandValDisplay",
    "onSplitButton",
    "displaySplitHand",
    "animateSplitCardToWidget",
    "showFloatingMessage"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  200,    2, 0x08,    1 /* Private */,
       4,    1,  203,    2, 0x08,    3 /* Private */,
       6,    0,  206,    2, 0x08,    5 /* Private */,
       7,    0,  207,    2, 0x08,    6 /* Private */,
       8,    0,  208,    2, 0x08,    7 /* Private */,
       9,    0,  209,    2, 0x08,    8 /* Private */,
      10,    0,  210,    2, 0x08,    9 /* Private */,
      11,    0,  211,    2, 0x08,   10 /* Private */,
      12,    0,  212,    2, 0x08,   11 /* Private */,
      13,    0,  213,    2, 0x08,   12 /* Private */,
      14,    0,  214,    2, 0x08,   13 /* Private */,
      15,    4,  215,    2, 0x08,   14 /* Private */,
      21,    5,  224,    2, 0x08,   19 /* Private */,
      21,    4,  235,    2, 0x28,   25 /* Private | MethodCloned */,
      21,    3,  244,    2, 0x28,   30 /* Private | MethodCloned */,
      21,    2,  251,    2, 0x28,   34 /* Private | MethodCloned */,
      23,    0,  256,    2, 0x08,   37 /* Private */,
      24,    0,  257,    2, 0x08,   38 /* Private */,
      25,    0,  258,    2, 0x08,   39 /* Private */,
      26,    0,  259,    2, 0x08,   40 /* Private */,
      27,    0,  260,    2, 0x08,   41 /* Private */,
      28,    0,  261,    2, 0x08,   42 /* Private */,
      29,    1,  262,    2, 0x08,   43 /* Private */,
      31,    1,  265,    2, 0x08,   45 /* Private */,
      33,    0,  268,    2, 0x08,   47 /* Private */,
      34,    0,  269,    2, 0x08,   48 /* Private */,
      35,    0,  270,    2, 0x08,   49 /* Private */,
      36,    0,  271,    2, 0x08,   50 /* Private */,
      37,    0,  272,    2, 0x08,   51 /* Private */,
      38,    4,  273,    2, 0x08,   52 /* Private */,
      39,    1,  282,    2, 0x08,   57 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   17,   18,   19,   20,   22,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainWindow, std::true_type>,
        // method 'showErrorMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateBetDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onOneDollarBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFiveDollarBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTenDollarBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTwentyDollarBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHundredDollarBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateBalanceDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSubmitBet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayPlayerHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHitButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animateCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'animateDealerCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'animateDealerCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'animateDealerCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'animateDealerCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayDealerHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDoubleDownButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStandButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dealerStandStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEndGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearCardsDisplayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_muteButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateUserHandValDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDealerHandValDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSplitHandValDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSplitButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displaySplitHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animateSplitCardToWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showFloatingMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showErrorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->updateBetDisplay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->onOneDollarBet(); break;
        case 3: _t->onFiveDollarBet(); break;
        case 4: _t->onTenDollarBet(); break;
        case 5: _t->onTwentyDollarBet(); break;
        case 6: _t->onHundredDollarBet(); break;
        case 7: _t->updateBalanceDisplay(); break;
        case 8: _t->onSubmitBet(); break;
        case 9: _t->displayPlayerHand(); break;
        case 10: _t->onHitButtonClicked(); break;
        case 11: _t->animateCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 12: _t->animateDealerCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 13: _t->animateDealerCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 14: _t->animateDealerCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->animateDealerCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->displayDealerHand(); break;
        case 17: _t->onDoubleDownButton(); break;
        case 18: _t->onStandButton(); break;
        case 19: _t->dealerStandStep(); break;
        case 20: _t->onEndGame(); break;
        case 21: _t->clearCardsDisplayed(); break;
        case 22: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_muteButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->updateUserHandValDisplay(); break;
        case 25: _t->updateDealerHandValDisplay(); break;
        case 26: _t->updateSplitHandValDisplay(); break;
        case 27: _t->onSplitButton(); break;
        case 28: _t->displaySplitHand(); break;
        case 29: _t->animateSplitCardToWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 30: _t->showFloatingMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP

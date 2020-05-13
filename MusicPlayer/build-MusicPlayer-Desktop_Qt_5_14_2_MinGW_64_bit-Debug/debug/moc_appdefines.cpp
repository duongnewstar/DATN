/****************************************************************************
** Meta object code from reading C++ file 'appdefines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MusicPlayer/appdefines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appdefines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEnums_t {
    QByteArrayData data[18];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppEnums_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppEnums_t qt_meta_stringdata_AppEnums = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppEnums"
QT_MOC_LITERAL(1, 9, 9), // "SCREEN_ID"
QT_MOC_LITERAL(2, 19, 22), // "SCREEN_ID_MUSIC_PLAYER"
QT_MOC_LITERAL(3, 42, 20), // "SCREEN_ID_MUSIC_LIST"
QT_MOC_LITERAL(4, 63, 13), // "LIST_CATEGORY"
QT_MOC_LITERAL(5, 77, 18), // "LIST_CATEGORY_SONG"
QT_MOC_LITERAL(6, 96, 20), // "LIST_CATEGORY_FOLDER"
QT_MOC_LITERAL(7, 117, 19), // "LIST_CATEGORY_ALBUM"
QT_MOC_LITERAL(8, 137, 20), // "LIST_CATEGORY_ARTIST"
QT_MOC_LITERAL(9, 158, 13), // "LIST_FUNCTION"
QT_MOC_LITERAL(10, 172, 10), // "ADD_FOLDER"
QT_MOC_LITERAL(11, 183, 8), // "ADD_SONG"
QT_MOC_LITERAL(12, 192, 9), // "PLAY_SONG"
QT_MOC_LITERAL(13, 202, 9), // "NEXT_SONG"
QT_MOC_LITERAL(14, 212, 9), // "PREV_SONG"
QT_MOC_LITERAL(15, 222, 12), // "SHUFFLE_SONG"
QT_MOC_LITERAL(16, 235, 11), // "REPEAT_SONG"
QT_MOC_LITERAL(17, 247, 15) // "LOAD_LAST_STATE"

    },
    "AppEnums\0SCREEN_ID\0SCREEN_ID_MUSIC_PLAYER\0"
    "SCREEN_ID_MUSIC_LIST\0LIST_CATEGORY\0"
    "LIST_CATEGORY_SONG\0LIST_CATEGORY_FOLDER\0"
    "LIST_CATEGORY_ALBUM\0LIST_CATEGORY_ARTIST\0"
    "LIST_FUNCTION\0ADD_FOLDER\0ADD_SONG\0"
    "PLAY_SONG\0NEXT_SONG\0PREV_SONG\0"
    "SHUFFLE_SONG\0REPEAT_SONG\0LOAD_LAST_STATE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEnums[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       3,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   29,
       4,    4, 0x0,    4,   33,
       9,    9, 0x0,    8,   41,

 // enum data: key, value
       2, uint(AppEnums::SCREEN_ID_MUSIC_PLAYER),
       3, uint(AppEnums::SCREEN_ID_MUSIC_LIST),
       5, uint(AppEnums::LIST_CATEGORY_SONG),
       6, uint(AppEnums::LIST_CATEGORY_FOLDER),
       7, uint(AppEnums::LIST_CATEGORY_ALBUM),
       8, uint(AppEnums::LIST_CATEGORY_ARTIST),
      10, uint(AppEnums::ADD_FOLDER),
      11, uint(AppEnums::ADD_SONG),
      12, uint(AppEnums::PLAY_SONG),
      13, uint(AppEnums::NEXT_SONG),
      14, uint(AppEnums::PREV_SONG),
      15, uint(AppEnums::SHUFFLE_SONG),
      16, uint(AppEnums::REPEAT_SONG),
      17, uint(AppEnums::LOAD_LAST_STATE),

       0        // eod
};

void AppEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AppEnums::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppEnums.data,
    qt_meta_data_AppEnums,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

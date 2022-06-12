TEMPLATE	= app
QT             += widgets sql
SOURCES		= main.cpp \
    authorization.cpp \
    database.cpp
windows:TARGET	= ../LineEdit

HEADERS += \
    authorization.h \
    database.h

RESOURCES += \
    res.qrc

win32: RC_FILE = db.rs

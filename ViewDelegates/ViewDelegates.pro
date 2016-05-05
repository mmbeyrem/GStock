#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T13:27:35
#
#-------------------------------------------------

TARGET = ViewDelegates
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ViewDelegatesFactory.cpp

HEADERS += ViewDelegatesFactory.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

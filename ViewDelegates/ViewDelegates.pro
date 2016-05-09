#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T13:27:35
#
#-------------------------------------------------

QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViewDelegates
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ViewDelegatesFactory.cpp \
           CategoryViewDelegate.cpp \
    ClientViewDelegate.cpp
HEADERS += ViewDelegatesFactory.h \
           CategoryViewDelegate.h \
           ViewDelegates.h \
    ClientViewDelegate.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

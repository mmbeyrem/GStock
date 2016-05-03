#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T18:33:45
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = EntityValidator
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    CategoryValidator.cpp

HEADERS += IEntityValidator.h \
    CategoryValidator.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../Models
INCLUDEPATH += $$PWD/../DBCore




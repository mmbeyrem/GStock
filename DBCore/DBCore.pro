#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T18:07:06
#
#-------------------------------------------------

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = DBCore
TEMPLATE = lib
CONFIG += staticlib

SOURCES += DbMigration.cpp \
    CategoryEntities.cpp \
    ProductEntities.cpp \
    ClientEntities.cpp \
    ProviderEntites.cpp \
    UserEntites.cpp \
    LogEntities.cpp \
    markEntities.cpp \
    ProductByMarkEntities.cpp

HEADERS += DbMigration.h \
    IEntities.h \
    CategoryEntities.h \
    ProductEntities.h \
    ClientEntities.h \
    ProviderEntites.h \
    UserEntites.h \
    LogEntities.h \
    MarkEntities.h \
    ProductByMarkEntities.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    script.sql

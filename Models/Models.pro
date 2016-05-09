#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T22:37:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Models
TEMPLATE = lib
CONFIG += staticlib

SOURCES += CommonModel.cpp \
    CategoryModels.cpp \
    ColumnCondition.cpp \
    ModelFactory.cpp \
    ModelResearch.cpp \
    ClientModels.cpp

HEADERS += CommonModel.h \
    CategoryModels.h \
    ColumnCondition.h \
    IModels.h \
    ModelFactory.h \
    ModelResearch.h \
    ClientModels.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DBCore/release/ -lDBCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DBCore/debug/ -lDBCore

INCLUDEPATH += $$PWD/../DBCore
DEPENDPATH += $$PWD/../DBCore

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/libDBCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/libDBCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/DBCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/DBCore.lib

#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T22:45:53
#
#-------------------------------------------------

QT       += gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Views
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    CategoryEntityDiag.cpp \
    CommonEntityDiag.cpp \
    CommonView.cpp \
    EntityDiagFactory.cpp \
    ClientEntityDiag.cpp

HEADERS += \
    CategoryEntityDiag.h \
    CommonEntityDiag.h \
    CommonView.h \
    EntityDiagFactory.h \
    IValidate.h \
    ClientEntityDiag.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    CommonEntityDiag.ui \
    CommonView.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Models/release/ -lModels
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Models/debug/ -lModels

INCLUDEPATH += $$PWD/../Models
DEPENDPATH += $$PWD/../Models

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/release/libModels.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/debug/libModels.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/release/Models.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/debug/Models.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DBCore/release/ -lDBCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DBCore/debug/ -lDBCore

INCLUDEPATH += $$PWD/../DBCore
DEPENDPATH += $$PWD/../DBCore

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/libDBCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/libDBCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/DBCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/DBCore.lib


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ViewDelegates/release/ -lViewDelegates
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ViewDelegates/debug/ -lViewDelegates

INCLUDEPATH += $$PWD/../ViewDelegates
DEPENDPATH += $$PWD/../ViewDelegates

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ViewDelegates/release/libViewDelegates.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ViewDelegates/debug/libViewDelegates.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ViewDelegates/release/ViewDelegates.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ViewDelegates/debug/ViewDelegates.lib

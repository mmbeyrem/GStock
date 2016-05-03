#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T23:04:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GStock
TEMPLATE = app


SOURCES += main.cpp \
    MainWindow.cpp

HEADERS  += \
    MainWindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DBCore/release/ -lDBCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DBCore/debug/ -lDBCore

INCLUDEPATH += $$PWD/../DBCore
DEPENDPATH += $$PWD/../DBCore

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/libDBCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/libDBCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/release/DBCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBCore/debug/DBCore.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Models/release/ -lModels
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Models/debug/ -lModels

INCLUDEPATH += $$PWD/../Models
DEPENDPATH += $$PWD/../Models

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/release/libModels.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/debug/libModels.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/release/Models.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Models/debug/Models.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Views/release/ -lViews
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Views/debug/ -lViews

INCLUDEPATH += $$PWD/../Views
DEPENDPATH += $$PWD/../Views

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Views/release/libViews.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Views/debug/libViews.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Views/release/Views.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Views/debug/Views.lib

#-------------------------------------------------
#
# Project created by QtCreator 2019-05-13T15:00:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        calculator.cpp

HEADERS += "C:/Users/Err/Desktop/TestLib/TestLib/BigNumberLib.h "
HEADERS += "calculator.h"

FORMS += \
        calculator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../TestLib/release/ -lTestLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../TestLib/debug/ -lTestLib
else:unix: LIBS += -L$$PWD/../../../TestLib/ -lTestLib

INCLUDEPATH += "C:/Users/Err/Desktop/TestLib/TestLib"
LIBS += "C:/Users/Err/Desktop/TestLib/Debug/TestLib.lib"

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../TestLib/release/libTestLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../TestLib/debug/libTestLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../TestLib/release/TestLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../TestLib/debug/TestLib.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../TestLib/libTestLib.a

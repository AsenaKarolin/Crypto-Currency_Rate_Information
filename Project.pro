QT   += core gui
QT   +=core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT += websockets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    myclass.cpp \
    main.cpp

HEADERS += \
    myclass.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = Lab2_qt
TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hyperlinkmodel.cpp \
    inputhyper.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Hyperlink.h \
    hyperlinkmodel.h \
    inputhyper.h \
    mainwindow.h

FORMS += \
    inputhyper.ui \
    mainwindow.ui

RESOURCES += \
    res/resources.qrc

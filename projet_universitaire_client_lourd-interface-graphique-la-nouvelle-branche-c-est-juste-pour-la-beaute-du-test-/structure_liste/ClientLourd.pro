QT += core
QT += widgets
QT += multimedia

QT -= gui

TARGET = ClientLourd
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    infoelement.cpp \
    element.cpp \
    list.cpp \
    mainwindow.cpp \
    listmodel.cpp \
    tree.cpp \
    listgraphics.cpp \
    connectionWidget.cpp \
    datamanager.cpp

HEADERS += \
    infoelement.h \
    element.h \
    list.h \
    mainwindow.h \
    listmodel.h \
    tree.h \
    listgraphics.h \
    connectionWidget.h \
    datamanager.h

CONFIG += c++14

FORMS += \
    mainwindow.ui \
    connectionWidget.ui

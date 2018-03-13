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
    admin.cpp \
    user.cpp

HEADERS += \
    infoelement.h \
    element.h \
    list.h \
    mainwindow.h \
    listmodel.h \
    tree.h \
    admin.h \
    user.h

CONFIG += c++14

FORMS += \
    mainwindow.ui

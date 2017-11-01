#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T17:08:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytimer.cpp \
    buttonoperator.cpp

HEADERS  += mainwindow.h \
    mytimer.h \
    buttonoperator.h

FORMS    += mainwindow.ui

DISTFILES += \
    UiForm.ui.qml \
    Ui.qml

RESOURCES += \
    resources.qrc

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
    buttonoperator.cpp \
    hovermanager.cpp \
    TimeManager.cpp

HEADERS  += mainwindow.h \
    buttonoperator.h \
    const.h \
    hovermanager.h \
    TimeManager.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
